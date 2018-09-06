#include <iostream>
using namespace std;

class A;    //���õ���Ԫ��Ա����ʱ����ע����Ԫ��������Ԫ����֮��Ļ���������������A������
class B
{
public:
    void set_show(int x, A &a);             //�ú�������A����Ԫ����
};

class A
{
public:
    friend void B::set_show(int x, A &a);   //�ú�������Ԫ��Ա����������
private:
    int data;
    void show() { cout << data << endl; }
};

void B::set_show(int x, A &a)       //ֻ���ڶ�����A����ܶ���ú������Ͼ���������Ϊ��Ԫ��Ϊ�˷�����A�ĳ�Ա
{
    a.data = x;
    cout << a.data << endl;
}

int main(void)
{
    class A a;
    class B b;
    b.set_show(1, a);
    return 0;
}
