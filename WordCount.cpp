#include "WordCount.h"

WordCount::WordCount(int argc, char * input_file, char * output_file){
	if (argc != 3)
		cerr << "Wrong amount of arguments" << endl;
	
	fin.open(input_file, ios::in);
	if (!fin)
		cerr << "There is no input file like that" << endl;

	fout.open(output_file, ios::out);
	if (!fout)
		cerr << "Output file can't be opened" << endl;
}
void WordCount::start() {
	MapFilling();
	Printer();
}

void WordCount::MapFilling() {
	int EndOF = 0;
	int Symbol;
	string word;

	while (!EndOF) {
		Symbol = fin.get();
		if (isalpha(Symbol) || isdigit(Symbol)) {
			word += (char)Symbol;
		} else if (!word.empty()) {
			if (CSV_map.count(word) == 0) {
				CSV_map.insert( pair<string, int>(word, 1));
			} else {
				CSV_map[word]++;
			}
			word_counter++;
			word.clear();
		}
		if (Symbol == EOF)
			EndOF = 1;
	}
}

void WordCount::Printer(){
	
	multimap<int, string> sortedlyCount;
	for (auto item : CSV_map) {
		sortedlyCount.insert(pair<int, string>(item.second, item.first));
	}
	
	for (multimap<int, string>::reverse_iterator it = sortedlyCount.rbegin(); it != sortedlyCount.rend(); ++it) {
		fout << it->second << "," << it->first << "," << (double)it->first / word_counter * 100 << endl;
	}	
}
