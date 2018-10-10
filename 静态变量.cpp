#include <iostream>
using namespace std;

class Student {

private:
	static int nextId;
	int id;
	
public:
	Student() {
		++ nextId;
		id = nextId;
	}
	
	void print() {
		cout  << "I am "  << id << endl; 
	}
};

int Student::nextId = 0;

int main() {
	for (int i = 0; i < 5; ++ i){
		Student s1;
		s1.print();
	}
} 
