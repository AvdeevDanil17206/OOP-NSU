#include "Calculator.h"
#include "Meaning.h"
#include "OperCreator.h"
#include "Factory.h"
#include "Operator.h"
#include "Exceptions.h"

void Calculator::start(std::ifstream &fin) {
	Meaning meaning; //������� �������� ������
	std::string input_str, operation;
	OperCreator opercreator;//��������� 
	while (!fin.eof()) {//���� �� �� ������ �� ����� �����
		getline(fin, input_str, '\n');//���������� ������ �� fin � input_str
		meaning.GetArg(input_str);//�������������� ������ 

		//����������, ���� � ����� ���� �����-�� �������
		if (meaning.ListEmpty() == 0) {
			operation = meaning.Front(); // �������� ������� �� �����
			meaning.PopFront(); //������� ���������� ��������

			try {        //������� ����� ��������� ��� ���� �����, ���� MakeOp ����� ����������, oper �� ���� ���� �� ����������� � catch
				std::auto_ptr<Operator> oper(Factory::FactoryCreate()->StartCreating(operation));//������� factory -> �������� OperCreator -> �������� Operator 
				oper->MakeOperation(meaning);//�per � ���� ������� ��������� �� add(��������), ��������� ���������� ��������
			}
			catch (exception& exc) {//����������
				std::cout << exc.what() << "\n";
			}
		}
	}
}