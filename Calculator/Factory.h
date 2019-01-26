#ifndef FACTORY_H
#define FACTORY_H

#include "Calculator.h"
#include <map>
#include "OperCreator.h"

class Factory {
private:
		std::map<std::string, OperCreator *> factory_map;   //map �������� � �������� ������� ��� �� ����������
															//(��� ������ ��� ��������� �����-���� ��������)
public:
		static Factory* FactoryCreate();					//����� �������� �������
		void MakeInstruction(std::string key, OperCreator* value);	//����� �������� ����������(���������� ����)
		Operator* StartCreating(std::string name);			//��������� 
		~Factory();	
};
#endif