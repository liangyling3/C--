#include <iostream> 
#include <string> 
#include <vector> 
using namespace std; 
 
template <typename T>  
class Args {
private:
	vector <T> values;
};

template <>
class Args<string> {

private:
	vector<string> values;
	
public:

	~Args() {
	}
	
	
	Args(
		string t1 = "",
		string t2 = "",
		string t3 = "",
		string t4 = "",
		string t5 = "",
		string t6 = "",
		string t7 = "",
		string t8 = "",
		string t9 = "",
		string t10 = "") { //constructor 
		
		if (t1.size()>0) values.push_back(t1);
		if (t2.size()>0) values.push_back(t2);
		if (t3.size()>0) values.push_back(t3);
		if (t4.size()>0) values.push_back(t4);
		if (t5.size()>0) values.push_back(t5);
		if (t6.size()>0) values.push_back(t6);
		if (t7.size()>0) values.push_back(t7);
		if (t8.size()>0) values.push_back(t8);
		if (t9.size()>0) values.push_back(t9);
		if (t10.size()>0) values.push_back(t10);
			
	}

	operator vector<string> (){
		return this->values;
	}
	
};

template <>
class Args<int> {

private:
	vector<int> values;
	
public:
	~Args() {
	}
	
	Args(
		int t1 = 0,
		int t2 = 0,
		int t3 = 0,
		int t4 = 0,
		int t5 = 0,
		int t6 = 0,
		int t7 = 0,
		int t8 = 0,
		int t9 = 0,
		int t10 = 0) { //constructor 
		
		if (t1 != 0) values.push_back(t1);
		if (t2 != 0) values.push_back(t2);
		if (t3 != 0) values.push_back(t3);
		if (t4 != 0) values.push_back(t4);
		if (t5 != 0) values.push_back(t5);
		if (t6 != 0) values.push_back(t6);
		if (t7 != 0) values.push_back(t7);
		if (t8 != 0) values.push_back(t8);
		if (t9 != 0) values.push_back(t9);
		if (t10 != 0) values.push_back(t10);
			
	}

	operator vector<int> (){
		return this->values;
	}
	
};
 
void test(int arg1, vector<int> args1, string arg2, vector<string> args2) { 
    cout << arg1 << endl; 
    for (int i = 0; i < args1.size(); ++ i) { 
        cout << args1[i] << endl; 
    } 
    cout << arg2 << endl; 
    for (int i = 0; i < args2.size(); ++ i) { 
        cout << args2[i] << endl; 
    } 
} 
 
int main() { 
    test(100, Args<int>(1,2,3,4,5,6,7,8,9), "hello", Args<string>("good", "morning", "bye")); 
} 
