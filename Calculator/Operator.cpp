#include "Calculator.h"
#include "Factory.h"
#include "OperCreator.h"
#include "Meaning.h"
#include "Exceptions.h"
#include "Operator.h"

namespace{
	//���������� ������� ������� ������� ���������� � factory_map
	bool AddInstruction() {
		AddCreator* add = new AddCreator;
		Factory::FactoryCreate()->MakeInstruction("+", add);

		SubCreator* sub = new SubCreator;
		Factory::FactoryCreate()->MakeInstruction("-", sub);
		
		MulCreator* mul = new MulCreator;
		Factory::FactoryCreate()->MakeInstruction("*", mul);
		
		DivCreator* div = new DivCreator;
		Factory::FactoryCreate()->MakeInstruction("/", div);
		
		SqrtCreator* sqrt = new SqrtCreator;
		Factory::FactoryCreate()->MakeInstruction("SQRT", sqrt);
		
		PopCreator* pop = new PopCreator;
		Factory::FactoryCreate()->MakeInstruction("POP", pop);
		
		PrintCreator* print = new PrintCreator;
		Factory::FactoryCreate()->MakeInstruction("PRINT", print);

		return true;
	}
	bool fake = AddInstruction();
}
//������� �������� �������� +
void Add::MakeOperation(Meaning& meaning) {
	double Number = meaning.TopArg();
	meaning.PopArg();//�������� �� �����
	double SecNum = meaning.TopArg();
	meaning.PopArg();//�������� ������� ���� �� �����(��� �������)
	meaning.PushArg(Number + SecNum);
}
//������� �������� �������� -
void Substract::MakeOperation(Meaning& meaning) {
	double Number = meaning.TopArg();
	meaning.PopArg();
	double SecNum = meaning.TopArg();
	meaning.PushArg(SecNum - Number);
}
//������� �������� �������� *
void Multiplicate::MakeOperation(Meaning& meaning) {
	double Number = meaning.TopArg();
	meaning.PopArg();
	double SecNum = meaning.TopArg();
	meaning.PopArg();
	meaning.PushArg(Number * SecNum);
}
//������� �������� �������� /
void Division::MakeOperation(Meaning& meaning) {
	double Number = meaning.TopArg();
	meaning.PopArg();
	if (Number == 0)
		throw division_by_zero();
	double SecNum = meaning.TopArg();
	meaning.PopArg();
	meaning.PushArg(SecNum / Number);
}
//������� �������� �������� ������ �����
void Sqrt::MakeOperation(Meaning& meaning) {
	double Number = meaning.TopArg();
	meaning.PopArg();
	if (Number < 0)
		throw negative_num();
	meaning.PushArg(sqrt(Number));
}
//������� �������� �������� �������� �������� �� �����
void Pop::MakeOperation(Meaning& meaning) {
	meaning.PopArg();
}
//������� �������� �������� ������
void Print::MakeOperation(Meaning& meaning) {
	std::cout << "Answer is: "<< meaning.TopArg() << std::endl;
}
