#include "Meaning.h"
#include "Exceptions.h"
//������������� ������
void Meaning::GetArg(std::string &input_str){
	int j = 0;
	std::string instruction = "";	
	for (int i = 0; i < (int)input_str.length(); i++) { //���� �� ����� ������
		if (input_str[i] == ' ' || input_str[i + 1] == '\0') {  //���� (��������� ������ ��� ���� ������ - ����� ������)
			if (input_str[i + 1] == '\0')					    //���� ����� ������ ��� �� ����� ������, �� ��������� i++
				i++;										    //(��� �������, ����� �������� +, -, *, /.
			
			instruction = input_str.substr(j, i - j);			//� ���������� ���������� �� ������ i - j ��������, ������� � j
			j = i + 1 ;											
		}
		if (instruction == "DEFINE") {							//���� � ���������� �������� DEFINE 
			std::string num_define = "";						
			i++;
			while ((input_str[i] != ' ') && (input_str[i + 1] != '\0')) {	//����� ���� ������ ��� ����� ������ ����� 1 ������
				if (input_str[i + 1] == '\0')								//���� � DEFINE �� ������� ����� �� ����� ������, �� ������ ���������� �� ����
					throw empty_args();
				i++;
			}
			instruction = input_str.substr(j, i - j);						//����� �� ������� ����� ������� ���������
			j = i + 1;

			if (instruction == "")
				throw empty_args();
			else {															//���� � ���������� �� �������� �������� ����������, ��..
				i++;
				while (input_str[i] != ' ' && input_str[i + 1] != '\0') {	//���� �������� ����������(������� �� ��������� ����� ��������)
					i++;
				}

				if (input_str[i + 1] == '\0')								//���� �� ����� �� ��������� �����, �� ��������� 1 � i
					i++;

				num_define = input_str.substr(j, i - j);					//���������� �������� ���������� 
				j = i + 1;
				if (num_define == "")										//���� ��� ������, �� ����������
					throw empty_args();
				else
					variables[instruction] = stod(num_define);				//���������� �� ���� string � ��� double
			}
		}
		//���� � ���������� �������� PUSH
		if (instruction == "PUSH") {
				i++;
				double number = 0;
				while (input_str[i] != ' ' && input_str[i + 1] != '\0') {   //���������� DEFINE
					i++;
				}
				if (input_str[i + 1] == '\0') {								//���� ����� �� ���������� ������� ����������
					i++;
					if (!variables.empty()) {												//��������� �� ������� map
						if (variables.find(input_str.substr(j, i - j)) != variables.end())	//���� ������ ������ key � map 
							number = variables[input_str.substr(j, i - j)];					//���������� � number value �� map �� ����� key
						else {
								number = stod(input_str.substr(j, i - j));					//���� � map ��� ������� �����������, �� � number ���������� �����
						}
					}
					PushArg(number);														//� ���� ���������� �����
					j = i + 1;

				}
			}
		}
		//���� � ���������� �������� POP, PRINT, SQRT , +, -, * ��� /.
		if (instruction == "POP" || instruction == "PRINT" ||
				instruction == "SQRT" || instruction == "+"    ||
					instruction == "-" || instruction == "*" || instruction == "/") {
			args.push_back(instruction); //�� ������ ����� ������� � ���� ������
		}
}


//���������� � ���� ��������
void Meaning::PushArg(double arg) {
	value_stack.push(arg); //push ��������� � ����
}

//�������� �� ����� ��������
void Meaning::PopArg() {
	if (!value_stack.size())
		throw empty_stack(); //exception 
	value_stack.pop();
}

//���������� ������� ������� �����
double Meaning::TopArg(){
	if (!value_stack.size())
		throw empty_stack();//exc
	return value_stack.top();
}

//�������� ������� ��-�� ����� 
void Meaning::PopFront() {
	if (args.empty())
		throw no_operation();//exc
	args.pop_front();
}

//��������� ������� ��-�� ����
std::string Meaning::Front() {
	if (args.empty())
		throw no_operation();//exc
	return args.front();
}
//�������� ����� �� �������
int Meaning::ListEmpty() {
	return args.empty();
}
