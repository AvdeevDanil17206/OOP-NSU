#ifndef OPERCREATOR_H
#define OPERCREATOR_H

#include "Calculator.h"
#include "Operator.h"
//класс создания функции
class OperCreator {
public:
	virtual Operator* create() {
		return NULL;
	};
};
//подкласс для суммирования
class AddCreator : public OperCreator {
public:
	Operator* create() {
		Add* add = new Add;
		return add;
	};
};
//подкласс для вычитания
class SubCreator : public OperCreator {
public:
	Operator* create() {
		Substract* sub = new Substract;
		return sub;
	};
};
//подкласс для умножения
class MulCreator : public OperCreator {
public:
	Operator* create() {
		Multiplicate* mul = new Multiplicate;
		return mul;
	};
};
//подкласс для деления
class DivCreator : public OperCreator {
public:
	Operator* create() {
		Division* div = new Division;
		return div;
	};
};
//подкласс для взятия корня
class SqrtCreator : public OperCreator {
public:
	Operator* create() {
		Sqrt* sqrt = new Sqrt;
		return sqrt;
	};
};
//подкласс для снятия значения со стека
class PopCreator : public OperCreator {
public:
	Operator* create() {
		Pop* pop = new Pop;
		return pop;
	};
};
//подкласс для печати
class PrintCreator : public OperCreator {
public:
	Operator* create() {
		Print* print = new Print;
		return print;
	};
};
#endif