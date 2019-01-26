#ifndef OPERATOR_H
#define OPERATOR_H
	
#include "Calculator.h"
#include "Meaning.h"	

class Operator {
public:
	virtual void MakeOperation(Meaning&) = 0;
	virtual ~Operator() {};
};

class Add : public Operator {
public:
	void MakeOperation(Meaning&) ;
	~Add(){};
};

class Substract : public Operator {
public:
	void MakeOperation(Meaning&) ;
	~Substract(){};
};

class Multiplicate : public Operator {
public:
	void MakeOperation(Meaning&) ;
	~Multiplicate() {};
};

class Division : public Operator {
public:
	void MakeOperation(Meaning&);
	~Division() {};
};
class Sqrt : public Operator {
public:
	void MakeOperation(Meaning&);
	~Sqrt() {};
};

class Pop : public Operator {
public:
	void MakeOperation(Meaning&);
	~Pop() {};
};

class Print : public Operator {
public:
	void MakeOperation(Meaning&);
	~Print() {};
};

#endif