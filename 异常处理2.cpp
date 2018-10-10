/*Design a class Matrix that throws the following exceptions:
A out_of_range exception, which is thrown whenever a user access an element in a matrix via an out-of-range row/column index. This exception is thrown by object functions get and set. This exception is defined by C++ in a library file named <stdexcept>
A MatrixSizesDoNotMatchException is thrown whenever adding two matrixes, whose rows or columns do not equal. You need to define this exception class. This exception is thrown in the object function operator +.
	EXAMPLE INPUT
		2 3
		1 2 3
		4 5 6
		
		1 2
		2 4
		
		2 3
		2 3 4
		3 4 5
		
		2 4
		1 2 3 4
		4 3 2 1
	EXAMPLE OUTPUT
		value = 2
		caught: out_of_range
		(2,3)
		 3 5 7
		 7 9 11
		caught: MatrixSizesDoNotMatchException*/
		
		
#include <vector> 
using namespace std; 
 
class Matrix 
{ 
private: 
    int rows; 
    int columns; 
    vector<double> elements; 
     
public: 
    Matrix(int rows, int columns) { 
        this->rows = rows; 
        this->columns = columns; 
        for (int i = 0; i < rows * columns;  ++ i) { 
            elements.push_back(0.0); 
        } 
    } 
     
    int size(int dimension) const { 
        switch (dimension) { 
        case 1: return rows; 
        case 2: return columns; 
        } 
        return 0; 
    } 
     
    double get(int row, int column) const; 
     
    void set(int row, int column, double value); 
     
    Matrix operator + (const Matrix & matrix2) const; 
}; 
 
// answer 
#include <stdexcept>
using namespace std;

class MatrixSizesDoNotMatchException {
};

double Matrix:: get(int row, int column) const{
	if(row > this->rows || column > this->columns) 
		throw out_of_range("???");
		
	return this->elements[(row-1)*this->columns+column-1];
} 

void Matrix:: set(int row, int column, double value) {
	if(row > this->rows || column > this->columns)
		throw out_of_range("???");
		
	this->elements[(row-1)*this->columns+column-1] = value;
}

Matrix Matrix:: operator + (const Matrix & matrix2) const {
	if (this->columns != matrix2.columns || this->rows != matrix2.rows)
		throw MatrixSizesDoNotMatchException();
		
	Matrix matrix3 (this->rows, this->columns);
	for (int i = 0; i < this->rows; ++ i) {
		for (int j = 0; j < this->columns; ++ j) {
			matrix3.elements.push_back(this->get(i,j)+matrix2.get(i,j));
		}
	}
	return matrix3;
}
// answer end
 
#include <iostream> 
using namespace std; 
 
Matrix read() { 
    int rows; 
    int columns; 
    cin >> rows >> columns; 
    Matrix matrix(rows, columns); 
    for (int i = 0; i < rows; ++ i) { 
        for (int j = 0; j < columns; ++ j) { 
            double value; 
            cin >> value; 
            matrix.set(i + 1, j + 1, value); 
        } 
    } 
    return matrix; 
} 
 
void print(const Matrix & matrix) { 
    int rows = matrix.size(1); 
    int columns = matrix.size(2); 
    cout << "(" << rows << "," << columns << ")" << endl; 
    for (int i = 0; i < rows; ++ i) { 
        for (int j = 0; j < columns; ++ j) { 
            cout << " " << matrix.get(i + 1, j + 1); 
        } 
        cout << endl; 
    } 
} 
 
void test1(const Matrix & matrix) { 
    for (int i = 0; i < 2; ++ i) { 
        int row; 
        int column; 
        cin >> row >> column; 
        try { 
            double value = matrix.get(row, column); 
            cout << "value = " << value << endl; 
        } 
        catch (out_of_range & ex) { 
            cout << "caught: out_of_range" << endl; 
        } 
    } 
} 
 
void test2(const Matrix & matrix) { 
    for (int i = 0; i < 2; ++ i) { 
        Matrix matrix2 = read(); 
        try { 
            matrix2 = matrix + matrix2; 
            print(matrix2); 
        } 
        catch (MatrixSizesDoNotMatchException & ex) { 
            cout << "caught: MatrixSizesDoNotMatchException" << endl; 
        } 
    } 
} 
 
int main() { 
    Matrix matrix = read(); 
    test1(matrix); 
    test2(matrix); 
} 
