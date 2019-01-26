#include "Calculator.h"
#include "Factory.h"
#include "OperCreator.h"
#include "Exceptions.h"

Factory* Factory::FactoryCreate() {
	static Factory factory;
	return &factory;
}

void Factory::MakeInstruction(std::string key, OperCreator* value) {
	//��������� factory_map OperCreator'���
	factory_map[key] = value;
}

Operator* Factory::StartCreating(std::string name) {
	//���� find ���������� ��-�(OperCreator) ��������� �� ���������
	if (factory_map.find(name) == factory_map.end())
		throw no_operation();
	return factory_map.at(name)->create();//���������� OperCreator ����������� � ������� create
}

Factory::~Factory() {
	//���� �� ������ �� ����� map ������� ��� value
	for (auto i = factory_map.begin(); i != factory_map.end(); i++)
		delete i->second;//������� value � factory_map
}