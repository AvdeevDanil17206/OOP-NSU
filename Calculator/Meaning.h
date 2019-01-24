#ifndef MEANING_H
#define MEANING_H

#include "Calculator.h"
#include <stack>
#include <map>
#include <list>

class Meaning {
	std::stack <double> arg_stack;
	std::map <std::string, double> variables;
	std::list <std::string> args;
	int stack_size = 0;
public:
	void PopFront();//list
	void PopBack();//list
	std::string Front();//list
	std::string& Back();//list
	void GetArg(std::string&);//list
	bool IsEmptyVar();//map
	void PushArg(double);//stack
	void PopArg();//stack
	double FindVar(std::string&);//map
	double TopArg();//stack
	int Size();//stack
	int ListEmpty();//list
	void AddVar(std::string, double);//map
};
#endif
