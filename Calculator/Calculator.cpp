#include "Calculator.h"
#include "Meaning.h"
#include "OperCreator.h"
#include "Factory.h"
#include "Operator.h"
#include "Exceptions.h"

void Calculator::start(std::ifstream &fin) {
	Meaning meaning; //создаем значение строки
	std::string input_str, operation;
	OperCreator opercreator;//создатель 
	while (!fin.eof()) {//пока мы не дойдем до конца файла
		getline(fin, input_str, '\n');//записываем строку из fin в input_str
		meaning.GetArg(input_str);//интерпретируем строку 

		//продолжаем, если в листе есть какие-то команды
		if (meaning.ListEmpty() == 0) {
			operation = meaning.Front(); // получаем команду из листа
			meaning.PopFront(); //удаляем полученное значение

			try {        //создаем умный указатель для того чтобы, если MakeOp выдал исключение, oper не надо было бы освобождать в catch
				std::auto_ptr<Operator> oper(Factory::FactoryCreate()->StartCreating(operation));//создаем factory -> получаем OperCreator -> получаем Operator 
				oper->MakeOperation(meaning);//оper и есть фабрика запускаем от add(например), выполняем полученную операцию
			}
			catch (exception& exc) {//исключения
				std::cout << exc.what() << "\n";
			}
		}
	}
}