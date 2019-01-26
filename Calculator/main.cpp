#include "Calculator.h"

int main(int argc, char* argv[]) {
	std::ifstream fin;		
	fin.open("input.txt");
	Calculator calculator;	
	calculator.start(fin);
	system("pause");
	return 0;
}
