#include <iostream>
using namespace std;
 
class A{
	public:
		int var;
		int add(int a, int b);
};

//若在外部实现函数，需要这样写： 
int A::add(int a, int b){
	return a+b;
}

int main(){
	A a1;
	a1.var = 11;
	cout << a1.add(1,10);
	cout << a1.add(2);
}
