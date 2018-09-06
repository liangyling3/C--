#include <iostream>
#include <vector>
using namespace std;

class String{
	
private:
	vector <string> words;
	
public:
	String() {
	}
	
	~String() {
	}
	
	void print() {
		cout << this->words << endl;
	}
	
};

int main() {
	vector <string> str;
	cin >> str;
	for (int i = 0; i < str.size()-1; ++ i) {
		if (str[i] <= '9' && str[i] > ='0' && (str[i+1]>'9' || str[i+1]<'0')) {
			vector <char> s;
			
			
		}
	}
}
