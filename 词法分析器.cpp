/*请写一个简单的四则运算词法分析器。
EXAMPLE INPUT
	1 +2 *
	(46-5)
	
EXAMPLE OUTPUT
	1
	+
	2
	*
	(
	46
	-
	5
	) */
	
//answer
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string noBlank (const string & program) {
	string line;
	for (int i = 0; i < program.size(); ++ i) {
		if (program[i] != ' ' && program[i] != '\n') 
			line.push_back(program[i]);
	}
	return line;
}

string getWord (const string & line, int index) {
	if(line[index] <= '9' && line[index] >= '0') { //occasion of number
		string number;
		for (int i = index; i < line.size(); ++ i) {
			if (line[i] > '9' || line[i] < '0') 
				return number;
			number.push_back(line[i]);
		}			
	}
	
	else {
		string word;
		word.push_back(line[index]);
		return word;
	}
}

int getLength(const string & line, int index) {
	string word = getWord(line, index);
	return word.size();
}

vector <string> lexicalAnalysis (const string & program) {
	vector<string> words;
	string line = noBlank(program);
	
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
    for (int i = 0; i < words.size(); ++ i) { //print
        cout << words[i] << endl; 
    } 
} 

