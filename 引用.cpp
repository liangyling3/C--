#include <iostream>
using namespace std;

struct MyArray {
	double * data;
	int size;
};

void set_up(MyArray & arr) {//ע��˴�ʹ�������� ����������ڲ���arr���� 
	arr.data = new double [10];//��̬�����ڴ�ռ� 
	arr.size = 10; //����Ŀռ�ı�ʱ��size�Ĵ�СҲҪ��Ӧ���� 
}

void clean_up(MyArray & arr) {//�������� 
	if (arr.data == 0) {
		delete[] arr.data;
		arr.size = 0;
	}
}

double get(MyArray & array, int index){//���Խ�緵��0����Խ���򷵻ظ��� (��Զ����Խ������)
	if (*array.data <= index) {
		return 0;
	} 
	return array.data[index];
}

void set(MyArray & array, int index, double value) {
	if (array.size <= index) {// <=��ʱ�������Խ�� 
		cout << "allocating new memory space...\n";
		//new
		int new_size = index + 10; //+10�������ٷ������
		double * new_data = new double[new_size]; 
		//init 0 ��ʼ�� 
		
		for (int i = 0; i < new_size; ++ i) 
			new_data[i] = 0;
		//copy 
		for (int i = 0; i < array.size; ++ i) 
			new_data[i] = array.data[i];
		//delete
		delete[] array.data;
		array.size = new_size;
		array.data = new_data;
	} 
	array.data[index] = value;
}

int main() {
	struct MyArray arr;
	set_up(arr);
	int len;
	cin >> len;
	for (int i = 0; i < len; ++ i) {
		double val;
		cin >> val;	
		set(arr, i, val);//���ܣ�����һ���µĸ�����ڴ�ռ䣬��ԭ�ռ�����������¿ռ䣬���ͷ�ԭ�ռ� 
	}
	for (int i = 0; i < len; ++ i) {
		cout << get (arr, i) << endl;	
	}
	clean_up(arr);
}

