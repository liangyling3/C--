#include <iostream>
using namespace std;

class Student {
	friend void print(Student & s);
	friend class Teacher;
	
private:
	int grade;

};

class Teacher {

public:
	void assign(Student & s, int grade) {
		s.grade = grade;
	}
};

void print (Student & s) {
	cout << s.grade << endl;
}

int main () {
	Student s;
	Teacher().assign(s, 100);
	print(s); 
}
