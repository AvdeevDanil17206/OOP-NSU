#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include "Calculator.h"
//класс исключений
class exception : public std::exception {
public:
	virtual const char* what() { 
		return NULL; 
	};
};
//подкласс исключений для случая, когда не хватает какого-то аргумента
class empty_args : public exception {
public:
	const char* what() {
		return "You forgot to write arguments in input.txt /:^)";
	}
};
//подкласс исключений для случая, когда стэк пустой 
class empty_stack : public exception {
public:
	const char* what() {
		return "There is nothing in your stack";
	}
};
//подкласс исключений для случая, когда корень берется из отрицательного числа
class negative_num : public exception {
public:
	const char* what() {
		return "I don't know how to get the root of the negative number";
	}
};
////подкласс исключений для случая, когда происходит деление на 0
class division_by_zero : public exception {
public:
	const char* what() {
		return "Division by zero";
	}
};
//подкласс исключений для случая, когда в листе нет операций
class no_operation : public exception {
public:
	const char* what() {
		return "There are no operations is my list :( ";
	}
};

#endif