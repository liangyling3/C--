//请为Grammar写operator >>
//EXAMPLE INPUT
	//Num	<=	+-  Num  
	//Prod	<=	Num  */  Num  
	//Prod	<=	Prod  */  Num  
	//Prod	<=	Num  
	//Sum	<=	Prod  +-  Prod  
	//Sum	<=	Sum  +-  Prod  
	//Sum	<=	Prod  
	//Num	<=	(  Sum  )  
	//S	<=	Sum
//EXAMPLE OUTPUT
	//Num	<=	+-  Num  
	//Prod	<=	Num  */  Num  
	//Prod	<=	Prod  */  Num  
	//Prod	<=	Num  
	//Sum	<=	Prod  +-  Prod  
	//Sum	<=	Sum  +-  Prod  
	//Sum	<=	Prod  
	//Num	<=	(  Sum  )  
	//S	<=	Sum
     
#include <string> 
#include <vector> 
#include <iostream> 
using namespace std; 
 
class Grammar 
{ 
public: 
    string to; 
    vector<string> from; 
 
    Grammar(string to, string from1, string from2="", string from3="", string from4="", string from5="") { 
        this->to = to; 
        if (from1.size() > 0) from.push_back(from1); 
        if (from2.size() > 0) from.push_back(from2); 
        if (from3.size() > 0) from.push_back(from3); 
        if (from4.size() > 0) from.push_back(from4); 
        if (from5.size() > 0) from.push_back(from5); 
    } 
     
    Grammar() {} 
}; 
 
ostream & operator << (ostream & out, const Grammar & grammar) { 
    out << grammar.to << "\t<=\t"; 
    for (int i = 0; i < grammar.from.size(); ++ i) 
        cout << grammar.from[i] << "  "; 
    return out; 
} 
 
istream & operator >> (istream & in, Grammar & grammar) {
	string input;
	getline(in, input);
	
	int index = 0;
	for (int i = 0; ; ++ i) {
		if(input[i] == ' ' || input[i] == '\t') 
			grammar.to = input.substr(0,i); //第一个字符串 
	
		if (input[i] == '<' && input[i+1] == '=') {
			index = i+3;
			break;
		} 
	}
	
	int start = index;
	for (int i = start; i < input.size(); ++ i) {
		if (input[i] == ' ' && input[i+1] == ' ') { 
			grammar.from.push_back(input.substr(index, i-index));
			index = i+2;
		}
	}
	
	grammar.from.push_back(input.substr(index, input.size()-index)); //最后一个字符串 
	
} 
 
int main() { 
    for (int i = 0; i < 9; ++ i) { 
        Grammar grammar; 
        cin >> grammar; 
        cout << grammar << endl; 
    } 
} 
