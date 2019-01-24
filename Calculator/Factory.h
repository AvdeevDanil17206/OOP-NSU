#ifndef FACTORY_H
#define FACTORY_H

#include "Calculator.h"
#include <map>
#include "OperCreator.h"

class Factory {
private:
		Factory() = default;
		std::map<std::string, OperCreator *> factory_map;
public:
		Factory(Factory&) = delete;
		static Factory* get_instance();
		void make_instruction(std::string key, OperCreator* value);
		Operator* get_operator(std::string name);
		~Factory();
};

#endif