#include <iostream>
using namespace std;
 
class A{
	public:
		int var;
		int add(int a, int b);
};

//�����ⲿʵ�ֺ�������Ҫ����д�� 
int A::add(int a, int b){
	return a+b;
}

int main(){
	A a1;
	a1.var = 11;
	cout << a1.add(1,10);
	cout << a1.add(2);
}
