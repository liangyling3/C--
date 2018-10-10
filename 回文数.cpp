#include <iostream>
#include <vector>
#include <string>
using namespace std;

string numToString(int num) {
	int rem;
	string str;
	while(num > 0) {
		rem = num % 10;
		str.push_back(rem+'0');
		num /= 10;
	}
	return str;
}

bool judge(string str) {
	int flag = 1;
	if (str.size()%2 == 0)	{
		for (int i = 0; i < str.size()/2; ++ i) {
			if (str[i] != str[str.size()-1-i])	flag = 0;
		}
	}
	else {
		for (int i = 0; i < (str.size()-1)/2; ++i) {
			if (str[i] != str[str.size()-1-i])	flag = 0;
		}
	}
	return flag;
}

int main() {
	int temp;
	vector<int> numbers;
	while(1) {
		cin >> temp;
		if (temp == -1)	break;
		numbers.push_back(temp);
	} 
	
	vector<string> strings;
	for (int i = 0; i < numbers.size(); ++ i) {
		strings.push_back(numToString(numbers[i]));
	}
	for (int i = 0; i < numbers.size(); ++ i) {
		if (judge(strings[i]) == 1)	cout << "Yes" << endl;
		else cout << "No" << endl;
	} 
}
