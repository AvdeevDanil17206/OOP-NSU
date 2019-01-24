#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include "Calculator.h"

class calc_exception : public std::exception {
public:
	virtual const char* what() const noexcept { return NULL; };
};

class empty_args : public calc_exception {
public:
	const char* what() const noexcept override {
		return "You forgot to write argument /:^)";
	}
};

class empty_stack : public calc_exception {
public:
	const char* what() const noexcept override {
		return "There is nothing in your stack";
	}
};

class negative_num : public calc_exception {
public:
	const char* what() const noexcept override {
		return "I don't know how to work with negative arguments";
	}
};

class division_by_zero : public calc_exception {
public:
	const char* what() const noexcept override {
		return "Division by zero";
	}
};

class nodefinition : public calc_exception {
public: 
	const char* what() const noexcept override {
		return "You forgot to define variable";
	}
};

class no_operation : public calc_exception {
public:
	const char* what() const noexcept override {
		return "There is no operation like this hello ";
	}
};

class invalid_arg : public calc_exception {
public:
	const char* what() const noexcept override {
		return "You can't read this argument";
	}
};
#endif