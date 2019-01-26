#include "Calculator.h"
#include "Factory.h"
#include "OperCreator.h"
#include "Exceptions.h"

Factory* Factory::FactoryCreate() {
	static Factory factory;
	return &factory;
}

void Factory::MakeInstruction(std::string key, OperCreator* value) {
	//заполняем factory_map OperCreator'ами
	factory_map[key] = value;
}

Operator* Factory::StartCreating(std::string name) {
	//если find возвращает эл-т(OperCreator) следующий за последним
	if (factory_map.find(name) == factory_map.end())
		throw no_operation();
	return factory_map.at(name)->create();//отправляем OperCreator создаваться с помощью create
}

Factory::~Factory() {
	//пока не дойдем до конца map удаляем все value
	for (auto i = factory_map.begin(); i != factory_map.end(); i++)
		delete i->second;//удаляем value в factory_map
}