#include "Calculator.h"
#include "Meaning.h"
#include "OperCreator.h"
#include "Factory.h"
#include "Operator.h"
#include "Exceptions.h"

void Calculator::start(std::ifstream &fin) {
	Meaning meaning;
	std::string input_str, operation;
	OperCreator opercreator;
	while (!fin.eof()) {
		getline(fin, input_str, '\n');
		meaning.GetArg(input_str);
		
		if (meaning.ListEmpty() == 0) {
			operation = meaning.Front(); 
			meaning.PopFront(); 

			try {
				std::auto_ptr<Operator> oper(Factory::GetInstance()->GetOperator(operation));
				oper->MakeOperation(meaning);
			}
			catch (calc_exception& exc) {
				std::cout << exc.what() << "\n";
			}
		}
	}
}
