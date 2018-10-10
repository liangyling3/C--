#include <iostream>
using namespace std;

class Matrix{
private:
	int rows;
	int columns;
	double * values;

public:
	Matrix (int rows, int columns){
		this->rows = rows;
		this->columns = columns;
		this->values = new double[rows*columns];
		for (int i = 0; i < rows*columns; ++ i) {
			this->values[i] = 0;
		}
	}
	
	Matrix (int rows, int columns, double *values){
		this->rows = rows;
		this->columns = columns;
		this->values = new double*[rows];
		for (int i = 0; i < rows; ++ i) {
			this->values[i] = new double[columns];
		}
		for (int i = 0; i < rows; ++ i) {
			for (int j = 0; i < columns; ++ j){
				this->values[i][j] == values[i*columns+j];
			}
		}
	}
	
	void set(int row, int column, double value) {
		this->values[(row-1)*column+column] = value;
	}
	
	void print(){
		for (int i = 0; i < rows*columns; ++ i) {
			cout << "    " << this->values[i];
			if((i+1)%columns == 0) cout << endl;
		}
	}
	
	~Matrix(){
		this->values = NULL;//如果不进行这一步，此编译器中会导致重复释放同一个地址
		if(this->values == NULL)
			delete [] this->values;
	}
};


int main() { 
    int rows; 
    int columns; 
    double values[1000]; 
    cin >> rows >> columns; 
    for (int i = 0; i < rows * columns; ++ i) { 
        cin >> values[i]; 
    } 
    Matrix matrix1(rows, columns, values); 
 
    int row; 
    int column; 
    double value; 
    cin >> row >> column >> value; 
    Matrix matrix2(0, 0); 
    matrix2 = matrix1; 
    matrix2.set(row, column, value); 
    matrix2.print(); 
     
}
