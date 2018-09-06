/*Íê³Ésplitº¯Êý

EXAMPLE INPUT
	123   abcde   567     
	   ds   tete dfsd   567   
	  asd  te sdfs   567
  
EXAMPLE OUTPUT
	123
	abcde
	567
	ds
	tete
	dfsd
	567
	asd
	te
	sdfs
	567*/
#include <iostream> 
#include <string> 
#include <vector> 
using namespace std; 

vector<string> split(const string line) {
	vector<string> words;
	string word;
	for (int i = 0; i < line.length(); ++ i) {
		if (line[i] == ' ' || i == line.length()-1) {
			if(line[i] != ' ' && line[i] != '\n') word.push_back(line[i]); 
			if(line[i-1] != ' ' && i != 0) words.push_back(word);
			word.clear();
		}
		else word.push_back(line[i]);
	}
	return words;
}
 
void test() { 
    string line; 
    getline(cin, line); 
    vector<string> words = split(line); 
    for (int i = 0; i < words.size(); ++ i) { 
        cout << words[i] << endl; 
    } 
} 
 
int main() { 
    test(); 
    test(); 
    test(); 
}

