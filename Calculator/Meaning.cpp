#include "Meaning.h"
#include "Exceptions.h"

void Meaning::GetArg(std::string &input_str){
	int j = 0;
	std::string instruction = "";
	for (int i = 0; i < (int)input_str.length(); i++) {
		if (input_str[i] == ' ' || input_str[i + 1] == '\0') {
			if (input_str[i + 1] == '\0')
				i++;
			
			instruction = input_str.substr(j, i - j);
			j = i + 1 ;
			
		}
		if (instruction == "POP" || instruction == "PRINT" || instruction == "SQRT") {
			args.push_back(instruction);
		}
		if (instruction == "PUSH" || instruction == "+" || instruction == "-" || instruction == "*" || instruction == "/") {
			if (instruction != "PUSH") {
				args.push_back(instruction);
			}
			if (instruction == "PUSH") {
				i++;
				double number = 0;
				while (input_str[i] != ' ' && input_str[i + 1] != '\0') {
					i++;
				}
				if (input_str[i + 1] == '\0') {
					i++;
					if (! variables.empty()) {
						if (variables.find(input_str.substr(j, i - j)) != variables.end())
							number = variables[input_str.substr(j, i - j)];
						else
							number = DBL_MIN;
					}
					if (number == DBL_MIN)
						number = stod(input_str.substr(j, i - j));

					PushArg(number);
					j = i + 1;

				}
				if (number == 0)
					throw empty_args();
			}
		}
		if (instruction == "DEFINE") {
			std::string num_define = "";
			i++;
			while ((input_str[i] != ' ') && (input_str[i + 1] != '\0')) {
				if (input_str[i + 1] == '\0')
					throw empty_args();
				i++;
			}
			instruction = input_str.substr(j, i - j);
			j = i + 1;
			
			if (instruction == "")
				throw empty_args();
			else {
					i ++;
					while (input_str[i] != ' ' && input_str[i + 1] != '\0') {
					}
					
					if (input_str[i + 1] == '\0')
						i++;
					
					num_define = input_str.substr(j, i - j);
					j = i + 1;
					if (num_define == "")
						throw empty_args();
					else 
						variables[instruction] = stod(num_define);
				 }
		}
		instruction = "";
	}
}

void Meaning::PushArg(double arg) {
	arg_stack.push(arg); 
	stack_size++;
}

void Meaning::PopArg() {
	if (!Size())
		throw empty_stack();  
	arg_stack.pop();
}

bool Meaning::IsEmptyVar() {
	return variables.empty(); 
}

double Meaning::FindVar(std::string& name){
	if (!variables.size())
		throw	nodefinition();
	if (variables.find(name) != variables.end())
		return variables[name];
	return DBL_MIN;
}

double Meaning::TopArg(){
	if (!Size())
		throw empty_stack();
	return arg_stack.top();
}

int Meaning::Size(){
	return stack_size;
}

void Meaning::AddVar(std::string name, double value){
	variables[name] = value;
}

void Meaning::PopFront() {
	if (args.empty())
		throw no_operation();
	args.pop_front();
}

void Meaning::PopBack() {
	if (args.empty())
		throw no_operation();
	args.pop_back();
}

std::string Meaning::Front() {
	if (args.empty())
		throw no_operation();
	return args.front();
}

std::string& Meaning::Back() {
	return args.back();
}

int Meaning::ListEmpty() {
	return args.empty();
}
