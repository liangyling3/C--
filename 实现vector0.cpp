#include <cstring>

class String
{
private:
	char * chars;

	void _copy(const char text[]) {
		int num_chars = strlen(text)+ 1;
		this->chars = new char[num_chars];
		strcpy(this->chars, text);
	}

public:
	String() {
		this->chars = new char[1];
		this->chars[0] = 0;
	}

	String(const String & str2) {
		this->_copy(str2.chars);
	}

	String(const char text[]) {
		this->_copy(text)
	}

	String & operator = (const String & str2) {
		delete [] this->chars;
		this->_copy(str2.c_str());
		return *this;
	}

	const char * c_str() const {
		return this->chars;
	}

	~String() {
		delete [] this->chars;
	}
	
	int compare(const String & str2) const {
		return strcmp(this->chars, str2.chars);
	}

	bool operator >= (const String & str2) const {
		int result = this->compare(str2);
		return result >= 0;
	}

	int size() const {
		return strlen(this->chars);
	}

	String & replace(int start, int len, const string & replacement) {
		int new_len = strlen(this->chars) + 1 - len +
			replacement.size();
		char * temp = new char[new_len];
		strncpy(temp, this->chars, start);
		strcpy(temp + start, replacement.chars);
		strcpy(temp + start + replacement.size(), this->chars + start + len)
		delete [] this->chars;
		this->chars = temp;
		return *this;
	}

	String & operator += (const String & str2) {
		return this->replace(this->size(), 0, str2);
	}

	String & erase(int start, int len) {
		return this->replace(start, len, "");
	}

};


//////



class Vector
{
private:
	double * addr;
	int _size;
	int capacity;

	void _copy(const Vector & v) {
		this->_size = v._size;
		this->capacity = v.capacity;
		this->addr = new double[this->capacity];
		for (int i = 0; i < this->_size; ++ i) {
			this->addr[i] = v.addr[i];
		}
	}

	void _ensure_capacity(int size) {
		while (size > this->capacity) {
			this->capacity *= 2;
			double * temp = new double[this->capacity];
			for (int i = 0; i < this->_size; ++ i) {
				temp[i] = this->addr[i];
			}
			delete [] this->addr;
			this->addr = temp;
		}	
	}

public:
	int size() {
		return this->_size;
	}

	Vector() {
		this->new double[1];
		this->size = 0;
		this->capacity = 1;
	}

	Vector(const Vector & v) {
		this->_copy(v);
	}

	Vector & operator = (const Vector & v) {
		delete [] this->addr;
		this->_copy(v);
		return *this;
	}

	~Vector() {
		delete [] this->addr;
	}

	Vector & push_back(double value) {
		this->_ensure_capacity(this->_size + 1);
		this->addr[this->_size] = value;
		++ this->_size;
		return *this;
	}
	
	Vector & pop_back() {
		-- this->_size;
		return *this;
	}

	double & opertor [] (int index) {
		if (index < 0 || >= this->_size) {
			throw Exception("Index out of bound");
		}
		return this->addr[index];
	}

};




//////

#define Vector(Type) \
\
class Vector_##Type\
{\
private:\
	Type * addr;\
	int _size;\
	int capacity;\
\
	void _copy(const Vector_##Type & v) {\
		this->_size = v._size;\
		this->capacity = v.capacity;\
		this->addr = new Type[this->capacity];\
		for (int i = 0; i < this->_size; ++ i) {\
			this->addr[i] = v.addr[i];\
		}\
	}\
\
	void _ensure_capacity(int size) {\
		while (size > this->capacity) {\
			this->capacity *= 2;\
			Type * temp = new Type[this->capacity];\
			for (int i = 0; i < this->_size; ++ i) {\
				temp[i] = this->addr[i];\
			}\
			delete [] this->addr;\
			this->addr = temp;\
		}\
	}\
\
public:\
	int size() {\
		return this->_size;\
	}\
\
	Vector_##Type() {\
		this->new Type[1];\
		this->size = 0;\
		this->capacity = 1;\
	}\
\
	Vector_##Type(const Vector_##Type& v) {\
		this->_copy(v);\
	}\
\
	Vector_##Type& operator = (const Vector_##Type& v) {\
		delete [] this->addr;\
		this->_copy(v);\
		return *this;\
	}\
\
	~Vector_##Type() {\
		delete [] this->addr;\
	}\
\
	Vector_##Type& push_back(const Type & value) {\
		this->_ensure_capacity(this->_size + 1);\
		this->addr[this->_size] = value;\
		++ this->_size;\
		return *this;\
	}\
	\
	Vector_##Type& pop_back() {\
		-- this->_size;\
		return *this;\
	}\
\
	Type & opertor [] (int index) {\
		if (index < 0 || >= this->_size) {\
			throw Exception("Index out of bound");\
		}\
		return this->addr[index];\
	}\
\
};\

Vector(double)

Vector(Student)

///////

template <typename Type>
class Vector
{
private:
	Type * addr;
	int _size;
	int capacity;

	void _copy(const Vector & v) {
		this->_size = v._size;
		this->capacity = v.capacity;
		this->addr = new Type[this->capacity];
		for (int i = 0; i < this->_size; ++ i) {
			this->addr[i] = v.addr[i];
		}
	}

	void _ensure_capacity(int size) {
		while (size > this->capacity) {
			this->capacity *= 2;
			double * temp = new Type [this->capacity];
			for (int i = 0; i < this->_size; ++ i) {
				temp[i] = this->addr[i];
			}
			delete [] this->addr;
			this->addr = temp;
		}	
	}

public:
	int size() {
		return this->_size;
	}

	Vector() {
		this->new Type [1];
		this->size = 0;
		this->capacity = 1;
	}

	Vector(const Vector & v) {
		this->_copy(v);
	}

	Vector & operator = (const Vector & v) {
		delete [] this->addr;
		this->_copy(v);
		return *this;
	}

	~Vector() {
		delete [] this->addr;
	}

	Vector & push_back(const Type & value) {
		this->_ensure_capacity(this->_size + 1);
		this->addr[this->_size] = value;
		++ this->_size;
		return *this;
	}
	
	Vector & pop_back() {
		-- this->_size;
		return *this;
	}

	Type & opertor [] (int index) {
		if (index < 0 || >= this->_size) {
			throw Exception("Index out of bound");
		}
		return this->addr[index];
	}

};


Vector<double>
Vector<Student>

#include <vector>

vector<double> v;
