#ifndef MEANING_H
#define MEANING_H

#include "Calculator.h"
#include <stack>
#include <map>
#include <list>

class Meaning {
	std::stack <double> value_stack;//���� ����������(�����)
	std::map <std::string, double> variables;//��� ����������(�=2, ��������)
	std::list <std::string> args; //���������� ������ ����������(������)
public:
	void PopFront();//������� ������� �� �����
	std::string Front();//����� ������� �� �����
	void GetArg(std::string&);//�������� ������������� ������(��������� ���,���� � ���� ����� ����������)
	void PushArg(double);//����� � ���� �����-�� �������� ����������
	void PopArg();//������� �������� � �����
	double TopArg();//����� �������� �� �����
	int ListEmpty();//�������� �� ������� list
};
#endif