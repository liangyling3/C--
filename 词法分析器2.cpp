/* 写一个C++的词法分析器 
EXAMPLE INPUT
	class Cat {
	public:
		int id;
		Cat(int id) {
			this->id = id;
		}
		void print() {
			cout << id;
		}
	};
	
	int main() {
		Cat cat(123);
		cat.print();
	}*/

//answer
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string getWord (const string & line, int index) {
	string word;
	
	if(line[index] <= '9' && line[index] >= '0') { //occasion of number
		for (int i = index; i < line.size(); ++ i) {
			if (line[i] > '9' || line[i] < '0') 
				return word;
			word.push_back(line[i]);
		}			
	}
	
	else if ((line[index] <= 'z' && line[index] >= 'a') || (line[index] <= 'Z' && line[index] >= 'A')) {
		for (int i = index; i < line.size(); ++ i) {
			if (line[i] < 'A' || line[i] > 'z' || (line[i] < 'a' && line[i] > 'Z')) 
				return word;
			word.push_back(line[i]);
		}
	}

	else if (line[index] == '-' && line[index+1] == '>') 
		word += "->";
	
	else if (line[index] == '<' && line[index+1] == '<') 
		word += "<<";
	
	else 
		word.push_back(line[index]);
	
	return word;
}

int getLength(const string & line, int index) {
	string word = getWord(line, index);
	int count = 0;
	for (int i = index+word.size(); i < line.size(); ++ i) {
		if(line[i] == ' ' || line[i] == '\n' || line[i] == '\t') {
			count++;
			if(line[i+1] != ' ' && line[i+1] != '\n' && line[i+1] != '\t') break;
		}
		else break;
	}
	return word.size()+count;
}

vector <string> lexicalAnalysis (const string & line) {
	vector<string> words;
	
	int len = 1, i = 0;
	while (i < line.size()) {
		string word = getWord(line, i);
		len = getLength(line, i);
		words.push_back(word);
		i += len;
	}
	
	return words;
}
 
//answer end

#include <iostream> 
#include <string> 
#include <vector> 
using namespace std; 
 
string readAll() { 
    string all; 
    string line; 
    while (getline(cin, line)) 
        all += line + '\n'; 
    return all; 
} 
 
int main() { 
    string program = readAll(); 
    vector<string> words = lexicalAnalysis(program); 
    for (int i = 0; i < words.size(); ++ i) { 
        cout << words[i] << endl; 
    } 
} 
