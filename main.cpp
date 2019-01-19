#include <iostream>
#include "WordCount.h"

using namespace std;

int main(int argc, char* argv[]){
	auto *wordCount = new WordCount(argc, argv[1], argv[2]);
	wordCount->start();
	delete wordCount;
	return 0;
}