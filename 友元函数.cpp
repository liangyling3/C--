#include <iostream>
using namespace std;

class A {
public:
    friend void set_show(int x, A &a); //�ú�������Ԫ����������
private:
    int data;
};

void set_show(int x, A &a) {  //��Ԫ�������壬Ϊ�˷�����A�еĳ�Ա
    a.data = x;
    cout << a.data << endl;
}

int main(void)
{
    class A a;
    set_show(1, a);
    return 0;
}
