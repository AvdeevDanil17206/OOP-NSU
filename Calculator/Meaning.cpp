#include "Meaning.h"
#include "Exceptions.h"

//using namespace std;
//получение аргумента
void Meaning::GetArg(std::string &input_str){
	int j = 0;
	std::string instruction = "";
	//std::cout << std::endl << input_str << " " << std::endl;
	for (int i = 0; i < (int)input_str.length(); i++) {
		if (input_str[i] == ' ' || input_str[i + 1] == '\0') {
			if (input_str[i + 1] == '\0')
				i++;
			
			instruction = input_str.substr(j, i - j);
			j = i + 1 ;
			
		}
	//	std::cout <<"  i: " << i <<"  instruction: " << instruction;
		if (instruction == "POP" || instruction == "PRINT" || instruction == "SQRT") {
			args.push_back(instruction);
	//		std::cout << std::endl << args.front() << " DAROVA NAH " << std::endl;
		}
		if (instruction == "PUSH" || instruction == "+" || instruction == "-" || instruction == "*" || instruction == "/") {
			if (instruction != "PUSH") {
				args.push_back(instruction);
	//			std::cout << std::endl << "FACE VO TI FLEKSISH" << std::endl;
			}
			if (instruction == "PUSH") {
				i++;
				double number = 0;
	//			std::cout << " i: " << i;
				while (input_str[i] != ' ' && input_str[i + 1] != '\0') {
					//if (instruction[i + 1] == '\0')
		//			std::cout << "pepe";
					i++;
				}
		//		std::cout << " letim " << i;
				if (input_str[i + 1] == '\0') {
					i++;
		//			std::cout << " 1 ";
					if (! /*meaning.IsEmptyVar()*/  variables.empty()) {
						/*if (!variables.size())
								throw	nodefinition();*/
		//				std::cout << "2";
		//				std::cout << " i,j,(a) :" << i << j << variables[input_str.substr(j, i - j)];
						if (variables.find(input_str.substr(j, i - j)) != variables.end())
							number = variables[input_str.substr(j, i - j)];
						else
							number = DBL_MIN;

						/*number = meaning.FindVar(input_str.substr(j, i - j));*/
					}
					if (number == DBL_MIN)
						number = stod(input_str.substr(j, i - j));

					PushArg(number);
					j = i + 1;

				}
		//		std::cout << " number: " << number;
				if (number == 0)
					throw empty_args();
			}
		}
		if (instruction == "DEFINE") {
		//	std::cout << " memno ";
			std::string num_define = "";
			i++;
			while ((input_str[i] != ' ') && (input_str[i + 1] != '\0')) {
				if (input_str[i + 1] == '\0')
					throw empty_args();
				//instruction = input_str.substr(j, i - j); 
				//j = i + 1;
				//cout << " memno2 " << " i: " << i;
				i++;
		//		std::cout << " memno2 " << " i: " << i;
			}
			instruction = input_str.substr(j, i - j);
			j = i + 1;
			
		//	std::cout << " memno3 " << " instruction: " << instruction << " i,j " << i << "," << j;;
			
			if (instruction == "")
				throw empty_args();
			else {
			//		std::cout << " minecraft.BETA ";
					i ++;
					while (input_str[i] != ' ' && input_str[i + 1] != '\0') {
					//	if (input_str[i + 1] == '\0')
							i++;
				//			std::cout << " minecraft " << " i,j " << i << "," << j;
					}
					
					if (input_str[i + 1] == '\0')
						i++;
					
					//std::cout << " minecraft2 " << " i,j " << i << "," << j;
					num_define = input_str.substr(j, i - j);
					j = i + 1;
					//std::cout << " num_define: " << num_define << " i,j " << i << "," << j;
					if (num_define == "")
						throw empty_args();
					else 
						variables[instruction] = stod(num_define);
					//std::cout << " variables[instruction] " << variables[instruction];
				 }
		}
		instruction = "";
	}
}

//добавление в стек значений
void Meaning::PushArg(double arg) {
	arg_stack.push(arg); //push аргумента в стэк
	stack_size++;
}

//удаление из стека значений
void Meaning::PopArg() {
	if (!Size())
		throw empty_stack(); //exception 
	arg_stack.pop();
}

//проверка на пустой map
bool Meaning::IsEmptyVar() {
	return variables.empty(); //проверка на пустой map
}

//поиск в мапе по нейму
double Meaning::FindVar(std::string& name){
	if (!variables.size())
		throw	nodefinition();
	if (variables.find(name) != variables.end())
		return variables[name];
	return DBL_MIN;
}

//возвращает верхний элемент стека
double Meaning::TopArg(){
	if (!Size())
		throw empty_stack();
	return arg_stack.top();
}

//возвращает размер стека
int Meaning::Size(){
	return stack_size;
}

//добавление в map
void Meaning::AddVar(std::string name, double value){
	variables[name] = value;
}

//удаление первого эл-та листа 
void Meaning::PopFront() {
	if (args.empty())
		throw no_operation();
	args.pop_front();
}

//удаление последнего эл-та лист
void Meaning::PopBack() {
//	std::cout << " popback ";
	if (args.empty())
		throw no_operation();
	args.pop_back();
}

//получение первого эл-та лист
std::string Meaning::Front() {
	if (args.empty())
		throw no_operation();
	return args.front();
}

//получение последнего эл-та листа
std::string& Meaning::Back() {
	return args.back();
}

int Meaning::ListEmpty() {
	return args.empty();
}