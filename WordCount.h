#ifndef WORDCOUNT_H
#define WORDCOUNT_H
#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;
class WordCount{
	ifstream fin;
	ofstream fout;
	int word_counter = 0;
	map<string, int> CSV_map;

public:
	WordCount(int argc, char *input_file, char *output_file);
	void start();
private:
	void Printer();
	void MapFilling();
};
#endif 