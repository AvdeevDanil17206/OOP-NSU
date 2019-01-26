#ifndef FACTORY_H
#define FACTORY_H

#include "Calculator.h"
#include <map>
#include "OperCreator.h"

class Factory {
private:
		std::map<std::string, OperCreator *> factory_map;   //map операций и создания методов для их выполнения
															//(что делать при получении какой-либо операции)
public:
		static Factory* FactoryCreate();					//метод создания фабрики
		void MakeInstruction(std::string key, OperCreator* value);	//метод создания инструкции(заполнение мапа)
		Operator* StartCreating(std::string name);			//получение 
		~Factory();	
};
#endif