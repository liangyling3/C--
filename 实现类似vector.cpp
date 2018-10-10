#include <iostream> 
#include <string> 
#include <vector> 
#include <math.h>
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
		int t1 = 1.0/0.0,
		int t2 = 1.0/0.0,
		int t3 = 1.0/0.0,
		int t4 = 1.0/0.0,
		int t5 = 1.0/0.0,
		int t6 = 1.0/0.0,
		int t7 = 1.0/0.0,
		int t8 = 1.0/0.0,
		int t9 = 1.0/0.0,
		int t10 = 1.0/0.0) { //constructor 
		
		if (isfinite(t1)) values.push_back(t1);
		if (isfinite(t2)) values.push_back(t2);
		if (isfinite(t3)) values.push_back(t3);
		if (isfinite(t4)) values.push_back(t4);
		if (isfinite(t5)) values.push_back(t5);
		if (isfinite(t6)) values.push_back(t6);
		if (isfinite(t7)) values.push_back(t7);
		if (isfinite(t8)) values.push_back(t8);
		if (isfinite(t9)) values.push_back(t9);
		if (isfinite(t10)) values.push_back(t10);
			
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
    test(100, Args<int>(1,2,3,0,5,6,7,8,9), "hello", Args<string>("good", "morning", "bye")); 
} 
