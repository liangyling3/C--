/*Design a class Full that implements interface Matrix: Full should has the following public object functions in addition:
	A constructor Full(int rows, int column), which initializes all elements in the matrix to 0's.
	A constructor Full(int rows, int column, double values[]), which initializes all elements in the matrix to the given values. Note that the given values are in one-dimensional, you need to fill then into the two-dimensional matrix correctly.
	A constructor Full(const Matrix & matrix2).
	A destructor.
	A print function which prints each row of elements in a single line, with each element preceded with 4 spaces.

EXAMPLE INPUT
	4 4
	1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
EXAMPLE OUTPUT
	constructor 1
	    0    0    0
	    0    0    0
	    0    0    0
	constructor 2
	    1    2    3    4
	    5    6    7    8
	    9    10    11    12
	    13    14    15    16
	constructor 3
	    1    2    3    4
	    5    6    7    8
	    9    10    11    12
	    13    14    15    16
	operator =
	    1    2    3    4
	    5    6    7    8
	    9    10    11    12
	    13    14    15    16*/ 

#include <iostream> 
#include <string> 
#include <cmath> 
using namespace std; 
 
class Matrix 
{     
public: 
 
    virtual int size(int dimension) const = 0; 
    virtual void set(int row, int column, double value) = 0;  
    virtual double get(int row, int column) const = 0;  
    virtual void print() const = 0; 
    virtual Matrix & operator = (const Matrix & matrix2) = 0; 
}; 

//answer
#include <vector> 

class Full : public Matrix{
private:
	// the sum of rows and columns, values
	int rows;
	int columns;
	vector<double> values;

public:
	
	Full (int rows, int columns) { //constructor 1
		this->rows = rows;
		this->columns = columns;
		for(int i = 0; i < rows * columns; ++ i) 
			this->values.push_back(0);
	}
	
	Full (int rows, int columns, double values[]) { //construtor 2
		this->rows = rows;
		this->columns = columns;
		for (int i = 0; i < rows* columns; ++ i)
			this->values.push_back(values[i]);
	}
	
	Full (const Matrix & matrix2) { //copy constructor
		this->rows = matrix2.size(1);
		this->columns = matrix2.size(2);
		for (int i = 0; i < matrix2.size(1); ++ i) {
			for (int j = 0; j < matrix2.size(2); ++ j) 
				this->values.push_back(matrix2.get(i,j));
		}
	}
	
	~Full(){ //deconstructor
	}
	
	int size(int dimension) const{
		if (dimension == 1) return this->rows;
		if (dimension == 2) return this->columns;
		if (dimension == 3) return this->values.size();
	}
	
	void set (int row, int column, double value) {
		this->values[row * this->columns + column] = value;
	}
	
	double get (int row, int column) const {
		return this->values[row * this->columns + column];
	}
	
	void print() const {
		for (int i = 0; i < this->rows; ++ i) {
			for (int j = 0; j < this->columns; ++ j) {
				cout << "    " << this->values[i*this->columns+j];
			}
			cout << endl;
		}
	}
	
	Matrix & operator = (const Matrix & matrix2) {
		vector<double> temp;
		temp.swap(this->values);
	
		this->rows = matrix2.size(1);
		this->columns = matrix2.size(2);
		for (int i = 0; i < matrix2.size(1); ++ i) 
			for (int j = 0; j < matrix2.size(2); ++ j) 
				this->values.push_back(matrix2.get(i,j));
	}
};
//answer end
 
Full readMatrix() { 
    int rows; 
    int columns; 
    double values[1000]; 
    cin >> rows >> columns; 
    for (int i = 0; i < rows * columns; ++ i) { 
        cin >> values[i]; 
    } 
    Full matrix(rows, columns, values); 
    return matrix; 
} 
 
void printMatrix(const Matrix & matrix) { 
    matrix.print(); 
} 
 
int main() { 
    cout << "constructor 1" << endl; 
    Full full1(3, 3); 
    Matrix & matrix1 = full1; // down-casting 
    matrix1.print(); 
     
    cout << "constructor 2" << endl; 
    const Matrix & matrix2 = readMatrix(); 
    matrix2.print(); 
     
    cout << "constructor 3" << endl; 
    Full full3 = matrix2; 
    Matrix & matrix3 = full3; 
    printMatrix(matrix3); 
     
    cout << "operator =" << endl; 
    matrix3.set(1, 1, 10.0); 
    matrix3 = matrix2; 
    matrix3.print(); 
} 
