#include <iostream>
using namespace std;

struct MyArray {
	double * data;
	int size;
};

void set_up(MyArray & arr) {//注意此处使用了引用 在这个函数内操作arr数组 
	arr.data = new double [10];//动态分配内存空间 
	arr.size = 10; //分配的空间改变时，size的大小也要相应更新 
}

void clean_up(MyArray & arr) {//？？？？ 
	if (arr.data == 0) {
		delete[] arr.data;
		arr.size = 0;
	}
}

double get(MyArray & array, int index){//如果越界返回0；不越界则返回该数 (永远不会越界的情况)
	if (*array.data <= index) {
		return 0;
	} 
	return array.data[index];
}

void set(MyArray & array, int index, double value) {
	if (array.size <= index) {// <=的时候数组会越界 
		cout << "allocating new memory space...\n";
		//new
		int new_size = index + 10; //+10？→减少分配次数
		double * new_data = new double[new_size]; 
		//init 0 初始化 
		
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
		set(arr, i, val);//功能：分配一个新的更大的内存空间，把原空间的数拷贝到新空间，并释放原空间 
	}
	for (int i = 0; i < len; ++ i) {
		cout << get (arr, i) << endl;	
	}
	clean_up(arr);
}

