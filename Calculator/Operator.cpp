#include "Calculator.h"
#include "Factory.h"
#include "OperCreator.h"
#include "Meaning.h"
#include "Exceptions.h"
#include "Operator.h"

namespace{
	bool add_instruction() noexcept {
		AddCreator* add = new AddCreator;
		Factory::get_instance()->make_instruction("+", add);

		SubCreator* sub = new SubCreator;
		Factory::get_instance()->make_instruction("-", sub);
		
		MulCreator* mul = new MulCreator;
		Factory::get_instance()->make_instruction("*", mul);
		
		DivCreator* div = new DivCreator;
		Factory::get_instance()->make_instruction("/", div);
		
		SqrtCreator* sqrt = new SqrtCreator;
		Factory::get_instance()->make_instruction("SQRT", sqrt);
		
		PopCreator* pop = new PopCreator;
		Factory::get_instance()->make_instruction("POP", pop);
		
		PrintCreator* print = new PrintCreator;
		Factory::get_instance()->make_instruction("PRINT", print);

		return true;
	}
	bool fake = add_instruction();
}

void Add::make_operation(Meaning& meaning) {
	double Number = meaning.TopArg();
	meaning.PopArg();//значение из стека
	double SecNum = meaning.TopArg();
	meaning.PopArg();//значение второго знач из стека(уже первого)
	meaning.PushArg(Number + SecNum);
}

void Substract::make_operation(Meaning& meaning) {
	double Number = meaning.TopArg();
	meaning.PopArg();
	double SecNum = meaning.TopArg();
	meaning.PushArg(SecNum - Number);
}

void Multiplicate::make_operation(Meaning& meaning) {
	double Number = meaning.TopArg();
	meaning.PopArg();
	double SecNum = meaning.TopArg();
	meaning.PopArg();
	meaning.PushArg(Number * SecNum);
}

void Division::make_operation(Meaning& meaning) {
	double Number = meaning.TopArg();
	meaning.PopArg();
	if (!Number)
		throw negative_num();
	double SecNum = meaning.TopArg();
	meaning.PopArg();
	meaning.PushArg(SecNum / Number);
}

void Sqrt::make_operation(Meaning& meaning) {
	double Number = meaning.TopArg();
	meaning.PopArg();
	if (Number < 0)
		throw negative_num();
	meaning.PushArg(sqrt(Number));
}

void Pop::make_operation(Meaning& meaning) {
	meaning.PopArg();
}

void Print::make_operation(Meaning& meaning) {
	std::cout << "Answer is: "<< meaning.TopArg() << std::endl;
}

Operator::~Operator()
{
}