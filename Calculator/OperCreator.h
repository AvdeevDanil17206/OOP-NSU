#ifndef OPERCREATOR_H
#define OPERCREATOR_H

#include "Calculator.h"
#include "Operator.h"

class OperCreator {
public:
	virtual Operator* create() {
		return NULL;
	};
};

class AddCreator : public OperCreator {
public:
	Operator* create() override {
		Add* add = new Add;
		return add;
	};
};

class SubCreator : public OperCreator {
public:
	Operator* create() override {
		Substract* sub = new Substract;
		return sub;
	};
};

class MulCreator : public OperCreator {
public:
	Operator* create() override {
		Multiplicate* mul = new Multiplicate;
		return mul;
	};
};

class DivCreator : public OperCreator {
public:
	Operator* create() override {
		Division* div = new Division;
		return div;
	};
};

class SqrtCreator : public OperCreator {
public:
	Operator* create() override {
		Sqrt* sqrt = new Sqrt;
		return sqrt;
	};
};

class PopCreator : public OperCreator {
public:
	Operator* create() override {
		Pop* pop = new Pop;
		return pop;
	};
};

class PrintCreator : public OperCreator {
public:
	Operator* create() override {
		Print* print = new Print;
		return print;
	};
};
#endif