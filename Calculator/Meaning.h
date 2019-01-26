#ifndef MEANING_H
#define MEANING_H

#include "Calculator.h"
#include <stack>
#include <map>
#include <list>

class Meaning {
	std::stack <double> value_stack;//стек аргументов(чисел)
	std::map <std::string, double> variables;//мап переменных(а=2, например)
	std::list <std::string> args; //двусвязный список аргументов(команд)
public:
	void PopFront();//удаляем команду из листа
	std::string Front();//берем команду из листа
	void GetArg(std::string&);//получаем интерпретацию строки(заполняем мап,стек и лист соотв значениями)
	void PushArg(double);//пушим в стек какое-то значение переменной
	void PopArg();//удаляем значение в стеке
	double TopArg();//берем значение из стека
	int ListEmpty();//проверка на пустоту list
};
#endif