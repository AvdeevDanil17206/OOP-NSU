#ifndef OPERATOR_H
#define OPERATOR_H
	
#include "Calculator.h"
#include "Meaning.h"	

class Operator {
public:
	virtual void MakeOperation(Meaning&) = 0;
	virtual ~Operator() = 0;
};

class Add : public Operator {
public:
	void MakeOperation(Meaning&) override;
	~Add() override {};
};

class Substract : public Operator {
public:
	void MakeOperation(Meaning&) override;
	~Substract() override {};
};

class Multiplicate : public Operator {
public:
	void MakeOperation(Meaning&) override;
	~Multiplicate() override {};
};

class Division : public Operator {
public:
	void MakeOperation(Meaning&) override;
	~Division() override {};
};
class Sqrt : public Operator {
public:
	void MakeOperation(Meaning&) override;
	~Sqrt() override {};
};

class Pop : public Operator {
public:
	void MakeOperation(Meaning&) override;
	~Pop() override {};
};

class Print : public Operator {
public:
	void MakeOperation(Meaning&) override;
	~Print() override {};
};

#endif
