#include "Calculator.h"
#include "Factory.h"
#include "OperCreator.h"
#include "Meaning.h"
#include "Exceptions.h"
#include "Operator.h"

namespace{
	bool AddInstruction() noexcept {
		AddCreator* add = new AddCreator;
		Factory::GetInstance()->MakeInstruction("+", add);

		SubCreator* sub = new SubCreator;
		Factory::GetInstance()->MakeInstruction("-", sub);
		
		MulCreator* mul = new MulCreator;
		Factory::GetInstance()->MakeInstruction("*", mul);
		
		DivCreator* div = new DivCreator;
		Factory::GetInstance()->MakeInstruction("/", div);
		
		SqrtCreator* sqrt = new SqrtCreator;
		Factory::GetInstance()->MakeInstruction("SQRT", sqrt);
		
		PopCreator* pop = new PopCreator;
		Factory::GetInstance()->MakeInstruction("POP", pop);
		
		PrintCreator* print = new PrintCreator;
		Factory::GetInstance()->MakeInstruction("PRINT", print);

		return true;
	}
	bool fake = AddInstruction();
}

void Add::MakeOperation(Meaning& meaning) {
	double Number = meaning.TopArg();
	meaning.PopArg();
	double SecNum = meaning.TopArg();
	meaning.PopArg();
	meaning.PushArg(Number + SecNum);
}

void Substract::MakeOperation(Meaning& meaning) {
	double Number = meaning.TopArg();
	meaning.PopArg();
	double SecNum = meaning.TopArg();
	meaning.PushArg(SecNum - Number);
}

void Multiplicate::MakeOperation(Meaning& meaning) {
	double Number = meaning.TopArg();
	meaning.PopArg();
	double SecNum = meaning.TopArg();
	meaning.PopArg();
	meaning.PushArg(Number * SecNum);
}

void Division::MakeOperation(Meaning& meaning) {
	double Number = meaning.TopArg();
	meaning.PopArg();
	if (!Number)
		throw negative_num();
	double SecNum = meaning.TopArg();
	meaning.PopArg();
	meaning.PushArg(SecNum / Number);
}

void Sqrt::MakeOperation(Meaning& meaning) {
	double Number = meaning.TopArg();
	meaning.PopArg();
	if (Number < 0)
		throw negative_num();
	meaning.PushArg(sqrt(Number));
}

void Pop::MakeOperation(Meaning& meaning) {
	meaning.PopArg();
}

void Print::MakeOperation(Meaning& meaning) {
	std::cout << "Answer is: "<< meaning.TopArg() << std::endl;
}

Operator::~Operator()
{
}
