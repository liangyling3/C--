#include <iostream>
using namespace std;

namespace space1 //ÃüÃû¿Õ¼ä 
{
	int data = 10;
	
	void print() {
		cout << "data = " << data << endl;
	}
	
	class People
	{
	public:
		void greet() {
			cout  << "hello" << endl;
		}
	};
	
}

int main() {
	using namespace space1;
	People me;
	me.greet(); 
}
