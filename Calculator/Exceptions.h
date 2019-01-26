#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include "Calculator.h"
//����� ����������
class exception : public std::exception {
public:
	virtual const char* what() { 
		return NULL; 
	};
};
//�������� ���������� ��� ������, ����� �� ������� ������-�� ���������
class empty_args : public exception {
public:
	const char* what() {
		return "You forgot to write arguments in input.txt /:^)";
	}
};
//�������� ���������� ��� ������, ����� ���� ������ 
class empty_stack : public exception {
public:
	const char* what() {
		return "There is nothing in your stack";
	}
};
//�������� ���������� ��� ������, ����� ������ ������� �� �������������� �����
class negative_num : public exception {
public:
	const char* what() {
		return "I don't know how to get the root of the negative number";
	}
};
////�������� ���������� ��� ������, ����� ���������� ������� �� 0
class division_by_zero : public exception {
public:
	const char* what() {
		return "Division by zero";
	}
};
//�������� ���������� ��� ������, ����� � ����� ��� ��������
class no_operation : public exception {
public:
	const char* what() {
		return "There are no operations is my list :( ";
	}
};

#endif