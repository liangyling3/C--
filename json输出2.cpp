/*
OUTPUT:
{
	headers: [ 'A', 'B', 'C', ],
	rows: [
		[ '1-1', '1-2', '1-3', ],
		[ '2-1', '2-2', '2-3', ],
	],
]
1
0
1
0
{
	headers: [ 'A', ],
	rows: [
		[ '1-1', ],
		[ '2-1', ],
	],
]
{
	headers: [ 'A', 'B', 'C', ],
	rows: [
		[ '1-1', '1-2', '1-3', ],
	],
]
{
	headers: [ 'A', ],
	rows: [
		[ '1-1', ],
	],
]
1-1
{
	headers: [ 'A', 'B', 'C', ],
	rows: [
		[ '2-1', '2-2', '1-3', ],
		[ '2-1', '2-2', '2-3', ],
	],
]
{
	headers: [ 'A', 'C', ],
	rows: [
		[ '1-1', '1-3', ],
	],
]
_TableRef
{
	headers: [ 'A', 'C', ],
	rows: [
		[ '1-1', '1-3', ],
		[ '2-1', '2-3', ],
	],
]
{
	headers: [ 'A', 'B', 'C', ],
	rows: [
		[ '2-1', '2-2', '2-3', ],
	],
]
del
{
	headers: [ 'B', ],
	rows: [
		[ '1-2', ],
	],
]
+
{
	headers: [ 'A', 'B', 'C', 'D', ],
	rows: [
		[ '1-1', '1-2', '1-3', '1-4', ],
		[ '2-1', '2-2', '2-3', '2-4', ],
	],
]
{
	headers: [ 'A', 'B', 'C', ],
	rows: [
		[ '1-1', '1-2', '1-3', ],
		[ '2-1', '2-2', '2-3', ],
		[ '1-1', '1-2', '1-3', ],
		[ '2-1', '2-2', '2-3', ],
	],
]
---- assignment ----
{
	headers: [ 'D', ],
	rows: [
		[ '1-5', ],
		[ '2-5', ],
	],
]
{
	headers: [ 'A', 'B', 'C', ],
	rows: [
		[ 'C-1', '1-2', '1-3', ],
		[ 'C-2', '2-2', '2-3', ],
	],
]
{
	headers: [ 'A', 'B', 'C', ],
	rows: [
		[ '1-1', '1-2', '1-3', ],
		[ '2-1', '2-2', '2-3', ],
		[ 'A-1', 'B-2', 'C-3', ],
	],
]
{
	headers: [ 'A', 'B', 'C', ],
	rows: [
		[ '1-1', 'B-1', '1-3', ],
		[ '2-1', 'B-2', '2-3', ],
		[ 'A-1', 'B-3', 'C-3', ],
	],
]
{
	headers: [ 'A', 'B', 'C', ],
	rows: [
		[ '1-1', '1-2', '1-3', ],
		[ '2-1', 'B-1', '2-3', ],
		[ 'A-1', 'B-2', 'C-3', ],
	],
]
*/

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
using namespace std;

// Exceptions 
class NoSuchColumnException : public runtime_error {
	public:
		NoSuchColumnException() : runtime_error("NoSuchColumnException");
};

class NoSuchRowException : public runtime_error {
	public:
		NoSuchRowException() : runtime_error("NoSuchRowException"); 
};

// classes
class Range {
};

class Table {
	
private:
	vector <string> headers;
	vector <vector <string> > values;
	
public:
	Table() { //constructor
	}
	
	Table & operator = (Table t2) {
		this->headers = t2.headers;
		this->values = t2.values;
		return * this;
	}
	
	~Table() { //deconstrctor
	} 
	
	//append columns and rows
	void appendCol(string header) {
		this->headers.push_back(header);
	} 
	
	void appendRow() {
		vector <string> temp;
		this->values.push_back(temp);
	}
	
	// judge if the columns or row exist
	bool hasCol(string header) const {
		for (int i = 0; i < this->headers.size(); ++ i) {
			if (this->headers[i] == header) return 1;
		}
		return 0;
	}
	
	bool hasRow(int row) const {
		if (row < this->values.size()) return 1;
		return 0;
	}
	
	// access a row/column/value
	_TableRef & operator [] (int index) const { // access a row 
		_TableRef t1(*this);
		t1.table.appendRow();
		t1.headers = this->headers;
		t1.rowIndexes.push_back(index);
		
		if (index >= this->values.size() or index < 0) 
			throw NoSuchRowException();
		for (int i = 0; i < this->headers.size(); ++ i) {
			t1.values[0].push_back(this->values[index][i]);
		}
		
		return t1;
	}
	
	_TableRef & operator [] (string header) { // access a column
		_TableRef t1(*this);
		t1.headers.push_back(header);
		for (int i = 0; i < this->values.size(); ++ i)
			t1.rowIndexes.push_back(i);
		
		int index = -1;
		for (int i = 0; i < this->headers.size(); ++ i) {
			if (this->headers[i] == header) index = i;
		}
		if (index == -1) throw NoSuchColumnException();
		
		for (int i = 0; i < this->values.size(); ++ i) {
			vector <string> temp;
			t1.values.push_back(temp);
			t1.values[i].push_back(this->values[i][index]);
		}
		
		return t1;
	}
	
	_TableRef & operator [] (const vector <string> list) {
		_TableRef t1(*this);
		int index[list.size()];
		
		for (int i = 0; i < list.size(); ++ i) { // initial
			index[i] = -1;
		}
		for (int i = 0; i < this->headers.size(); ++ i) { //find the index
			for (int j = 0; j < list.size(); ++ j) {
				if (this->headers[i] == list[j]) index[j] = i;
			}
		}
		for (int i = 0; i < list.size(); ++ i) { // exception
			if (index[i] == -1) throw NoSuchColumnException();
		}
			
		for (int i = 0; i < list.size(); ++ i) { //put headers
			t1.headers.push_back(list[i]);
		}
		
		for (int i = 0; i < this->values.size(); ++ i) { //put values
			t1.rowIndexes.push_back(i);
			for (int j = 0; j < list.size(); ++ j) {
				t1.values[i].push_back(this->values[i][index[j]]);
			}
		} 
		
		return t1;
	}
	
	// The two operational character can't be overloading together!!!
	// use a nested class to solve this problem!! (in class _TableRef, overload [] again)
	
/*	_TableRef & operator [][] (string header, int index) {
		_TableRef t1(*this);
		t1.headers.push_back(header);
		t1.rowIndexes.push_back(index);
		
		if (index < headers.size() or index <= 0) throw NoSuchRowException;
		int index2 = -1;
		for (int i = 0; i < this->headers.size(); ++ i) {
			if (this->headers[i] == header) index2 = i;
		} 
		if (index == -1) throw NoSuchColumnException;
		
		vector <string> temp;
		t1.values.push_back(temp);
		t1.values[0].push_back(this->values[index][index2]);
		
		return t1;
	}
	 */
	 
	// delete a row/column 
	Table & delCol (string header) {
		int index = -1;
		for (int i = 0; i < this->headers.size(); ++ i) {
			if (this->headers[i] == header) index = i;
		}
		
		if (index != -1){
			this.headers.erase(this->headers.begin(), index);
			for (int i = 0; i < this->values.size(); ++ i) {
				this->values[i].erase(this->values[i].begin(), index);
			}
		} 
	
		return *this;
	}
	
	Table & delRow (int index) {
		if (index < this->values.size() and index >= 0) 
			this->values.erase(this->values.begin(), index); 
		return *this;
		
	}
	
	// Table to _TableRef  
	_TableRef json() const {
		_TableRef t1(*this);
		t1.headers = this->headers;
		t1.values = this->values;
		return t1; 
	}
	
private:
	// new class
	class _TableRef {  
		
	private:
		Table & table; // TableRef must include the reference of "Table", to revise it
		vector <int> rowIndexes; // use to change values in table (not just change TableRef)
		vector <string> headers;
		vector <vector <string> > values; 
		
	public:
		//constructor
		_TableRef(){
		}
		
		_TableRef(Table & t) {
			this->table = t;
		}
		
		_TableRef (string & str) {
			
		}
		
		~_TableRef{ //deconstructor
		}
		
		_TableRef & operator = (const _TableRef & t2) {
			this->table = t2.table;
			this->rowIndexes = t2.rowIndexes; 
			this->headers = t2.headers;
			this->values = t2.values;
			return *this;
		} 
		
		_TableRef & operator = (const vector <string> & values) {
			for (int i = 0; i < this->headers.size(); ++ i) { //change TableRef
					this->values[0].push_back(values[i]);
			}
			
			if (this->table.hasRow(this->rowIndexes)) //change table
				this->table.values[this->rowIndexes] = values;
			else 
				this->table.push_back(values);
			
			return *this;
		}
		
		//access a value
		string operator [] (string header) const {
			int index = -1;
			for (int i = 0; i < this->headers.size(); ++ i) {
				if (this->headers[i] == header) index = i;
			}
			if (index == -1) throw NoSuchColumnException();
			
			return this->values[0][index];
		} 
		
		_TableRef operator [] (int index) const {
			if (index < this->values.size() or index < 0)
				throw NoSuchRowException();
			
			_TableRef t1();
			t1.table = this->table;
			t1.headers = this->headers;
			t1.rowIndexes = index;
			t1.values = this->values[index];
			
			return t1;
		}
		
		void selectivelyCopy(Table t) {
			
		}
		
	};
	
};

string :: string & operator = (_TableRef t) {
	
}

vector<string> List(string str1, string str2) {
	vector <string> list;
	list.push_back(str1);
	list.push_back(str2);
	return list;
}

vector<string> List(string str1, string str2, string str3) {
	vector <string> list;
	list.push_back(str1);
	list.push_back(str2);
	list.push_back(str3);
	return list;
}

ostream & operator << (ostream & out, const _TableRef & table) {
	
}

ostream & operator  << (ostream & out, const string & str) {
	_TableRef t1(str); // for single string
	out <<  t1;
	return out;
}

#include <iostream>
using namespace std;

// ostream & operator << (ostream & out, const Table::_TableRef & ref) {
// 	out << ref.toTable().json();
// 	return out;
// }

ostream & operator << (ostream & out, const Table & table) {
	out << table.json();
	return out;
}


int main() {
	try {
		Table a;
		a.appendCol("A");
		a.appendCol("B");
		a.appendCol("C");
		a.appendRow();
		a[0] = List("1-1", "1-2", "1-3");
		vector<string> vec;
		vec.push_back("2-1");
		vec.push_back("2-2");
		vec.push_back("2-3");
		a[1] = vec; // appends the last row
		cout << a << endl;

		cout << a.hasCol("A") << endl;
		cout << a.hasCol("D") << endl;
		cout << a.hasRow(-1) << endl;
		cout << a.hasRow(2) << endl;

		cout << a["A"] << endl;
		cout << a[0] << endl;
		cout << a["A"][0] << endl;
		string value = a[0]["A"];
		cout << value << endl; //!!!
		
		Table b = a;
		b[0] = b[1];  
		b["C"].selectivelyCopy(a); //!!!
		cout << b << endl;

		b = a;
		b.delCol("B").delRow(-1);
		cout << b << endl;

		cout << "_TableRef" << endl;

		b = a[List("A", "C")]; 
		cout << b << endl;
		
		b = a[Range(1, 2)]; //!!!
		cout << b << endl;

		cout << "del" << endl;

		b = a;
		b.delCol(List("A", "C")).delRow(Range(1, 2)); //!!!
		cout << b << endl;

		cout << "+" << endl;

		b = Table();
		b.appendCol("D");
		b[0] = "1-4"; // only for single column table
		b[1] = "2-4"; //!!!
		b = a + b; //!!!
		cout << b << endl;
		b = a;
		b += a; //!!!
		cout << b << endl;

		cout << "---- assignment ----" << endl;

		b = Table();
		b.appendCol("D");
		b[0] = "1-4"; // only for single column table
		b[1] = "2-4";
		b = List("1-5", "2-5"); // only for single column table //!!!
		cout << b << endl;

		Table c = a;
		c["A"] = List("C-1", "C-2"); //!!!
		cout << c << endl;
		c = a;
		c[2] = List("A-1", "B-2", "C-3"); //!!!
		cout << c << endl;

		b = Table(); //!!!
		b.appendCol("B");
		b.appendRow();
		b.appendRow();
		b.appendRow();
		b = List("B-1", "B-2", "B-3");
		c["B"] = b;
		cout << c << endl;

		c = a;
		c[2] = List("A-1", "B-2", "C-3"); //!!!
		c[Range(1,-1)].selectivelyCopy(b); // only assign cols that are common to both tables
		cout << c << endl;
	}
	catch (runtime_error & ex) {
		cout << ex.what() << endl;
	}
}

