#include "Meaning.h"
#include "Exceptions.h"
//интерпретация строки
void Meaning::GetArg(std::string &input_str){
	int j = 0;
	std::string instruction = "";	
	for (int i = 0; i < (int)input_str.length(); i++) { //идем до конца строки
		if (input_str[i] == ' ' || input_str[i + 1] == '\0') {  //если (встретили пробел или след символ - конец строки)
			if (input_str[i + 1] == '\0')					    //если вслед символ все же конец строки, то добавляем i++
				i++;										    //(для случаев, когда операция +, -, *, /.
			
			instruction = input_str.substr(j, i - j);			//в инструкцию записываем из строки i - j символов, начиная с j
			j = i + 1 ;											
		}
		if (instruction == "DEFINE") {							//если в инструкцию записали DEFINE 
			std::string num_define = "";						
			i++;
			while ((input_str[i] != ' ') && (input_str[i + 1] != '\0')) {	//опять ищем пробел или конец строки через 1 символ
				if (input_str[i + 1] == '\0')								//если в DEFINE мы сначала дошли до конца строки, то других аргументов не было
					throw empty_args();
				i++;
			}
			instruction = input_str.substr(j, i - j);						//дошли до пробела после первого аргумента
			j = i + 1;

			if (instruction == "")
				throw empty_args();
			else {															//если в инструкцию мы записали название переменной, то..
				i++;
				while (input_str[i] != ' ' && input_str[i + 1] != '\0') {	//ищем значение переменной(доходим до последней цифры значения)
					i++;
				}

				if (input_str[i + 1] == '\0')								//если мы дошли до последней цифры, то добавляем 1 к i
					i++;

				num_define = input_str.substr(j, i - j);					//запоминаем значение переменной 
				j = i + 1;
				if (num_define == "")										//если оно пустое, то исключение
					throw empty_args();
				else
					variables[instruction] = stod(num_define);				//записываем из типа string в тип double
			}
		}
		//если в инструкцию записали PUSH
		if (instruction == "PUSH") {
				i++;
				double number = 0;
				while (input_str[i] != ' ' && input_str[i + 1] != '\0') {   //аналогично DEFINE
					i++;
				}
				if (input_str[i + 1] == '\0') {								//если дошли до последнего символа переменной
					i++;
					if (!variables.empty()) {												//проверяем на пустоту map
						if (variables.find(input_str.substr(j, i - j)) != variables.end())	//если найден нужный key в map 
							number = variables[input_str.substr(j, i - j)];					//записываем в number value из map по ключу key
						else {
								number = stod(input_str.substr(j, i - j));					//если в map нет нужного переменного, то в number записываем число
						}
					}
					PushArg(number);														//в стек записываем число
					j = i + 1;

				}
			}
		}
		//если в инструкцию записали POP, PRINT, SQRT , +, -, * или /.
		if (instruction == "POP" || instruction == "PRINT" ||
				instruction == "SQRT" || instruction == "+"    ||
					instruction == "-" || instruction == "*" || instruction == "/") {
			args.push_back(instruction); //мы просто пушим команду в лист команд
		}
}


//добавление в стек значений
void Meaning::PushArg(double arg) {
	value_stack.push(arg); //push аргумента в стэк
}

//удаление из стека значений
void Meaning::PopArg() {
	if (!value_stack.size())
		throw empty_stack(); //exception 
	value_stack.pop();
}

//возвращает верхний элемент стека
double Meaning::TopArg(){
	if (!value_stack.size())
		throw empty_stack();//exc
	return value_stack.top();
}

//удаление первого эл-та листа 
void Meaning::PopFront() {
	if (args.empty())
		throw no_operation();//exc
	args.pop_front();
}

//получение первого эл-та лист
std::string Meaning::Front() {
	if (args.empty())
		throw no_operation();//exc
	return args.front();
}
//проверка листа на пустоту
int Meaning::ListEmpty() {
	return args.empty();
}
