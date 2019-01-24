#include "Calculator.h"
#include "Factory.h"
#include "OperCreator.h"
#include "Exceptions.h"

Factory* Factory::GetInstance() {
	static Factory factory;
	return &factory;
}

void Factory::MakeInstruction(std::string key, OperCreator* value) {
	factory_map[key] = value;
}

Operator* Factory::GetOperator(std::string name) {
	if (factory_map.find(name) == factory_map.end())
		throw negative_num();
	return factory_map.at(name)->create();
}

Factory::~Factory() {
	for (auto i = factory_map.begin(); i != factory_map.end(); i++)
		delete i->second;
}
