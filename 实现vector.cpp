#include <iostream>
#include <vector> //vector: templates class
#include <cstring>
using namespace std;

class Vector{
private:
	double * addr;
	int size;
	int capacity;
	
	void _copy(const Vector & v) {
		this->size = v.size;
		this->capacity = v.capacity;
		this->addr = new double [this->capacity];
		memcpy(this->addr, v.addr, this->size);
		}
		
	void _ensure_capacity(int size) {
		if (this->size == this->capacity) {
			this->capacity *= 2;
			double * temp = new double[this->capacity];
			//enlarge memory space 
			memcpy (temp, this->addr, this->size);
			delete []  this->addr;
			this->addr = temp;
		}
	} 
	
public:
	Vector() {
		this->addr = new double[1];
		this->size = 0;
		this->capacity = 1;
	}
	
	Vector(const Vector & v) {
		this->_copy(v);
	}
	
	Vector & operator = (const Vector &v) {
		delete [] this->addr;
		this->_copy(v);
		return *this;
	}
	
	~Vector() {
		delete [] this->addr;
	}
	
	Vector & push_back(double value) {
		 this->_ensure_capacity(this->size +1);
		 this->addr[this->size] = value;
		 ++ this->size;
		 return * this;
	}
	
	Vector & pop_back() {
		-- this->size;
		return *this;
	}
	
	double & operator [] (int index) {
		if (index < 0 || index >= this->size){
			throw Exception ("index out of bound");
			//exit (0); 
		}
		return this->addr[index];
	}
};
