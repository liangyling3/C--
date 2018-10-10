#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Matrix {
private:
	int rows;
	int columns;
	vector<T> values;
	
public:
	Matrix (int rows, int columns) { //constructor 1
		this->rows = rows;
		this->columns = columns;
		this->values = new T[rows*columns];
		for (int i = 0; i < rows*columns; ++ i) {
			this->values[i] = 0;
		}
	}
	
	Matrix (int rows, int columns, vector<T> values) { //constructor 2
		this->rows = rows;
		this->columns = columns;
		this->values = new T[rows*columns];
		for (int i = 0; i < rows*columns; ++ i) {
			this->values[i] = values[i];
		}
	}
	
	Matrix(const Matrix & m2) { //copy constructor
		this->columns = m2.columns;
		this->rows = m2.rows;
		this->values = new vector<T> [m2.rows*m2.columns];
		for (int i = 0; i < m2.rows*m2.columns; ++ i) {
			this->values[i] = m2.values[i];
		}
	}
	
	~Matrix () { //deconstructor
		delete [] this->values;
	}
	
	void print() {
		for(int i = 0; i < this->columns*this->rows; ++ i) {
			cout << "    " << this->values[i];
			if((i+1)%this->columns == 0) 
				cout << endl; 
		}
	}
	
	Matrix operator = () const{
		Matrix m3(*this);
		return m3;
	}
	
	Matrix getColumn (int col) const {
		vector<T> zero[this->rows] = {0}; //此处this->rows的类型为const，可以直接用于数组声明 
		Matrix m3(this->rows, 1, zero);
		int i, j;
		for (j = 0; j == col; ++ j) {
			for (i = 0; i < this->rows; ++ i) {
				m3.values[i] = this->values[i*this->columns+j];
			}
		}
		return m3;
	}
	
	Matrix getRow (int row) const {
		vector<T> zero[this->columns] = {0};
		Matrix m3(1, this->columns, zero);
		int i, j;
		for (i = 0; i == row; ++ i) {
			for (j = 0; j < this->columns; ++ j) {
				m3.values[j] = this->values[i*this->columns+j];
			}
		}
		return m3;
	}
	
	Matrix concatenateRows (const Matrix & m2) const {
		vector<T> zero[(this->rows+m2.rows) * this->columns] = {0};
		Matrix m3(this->rows+m2.rows, this->columns, zero);
		int i, j;
		for (i = 0; i < m3.rows; ++ i) {
			for (j = 0; j < m3.columns; ++ j) {
				if(i < this->rows) 
					m3.values[i * m3.columns + j] = this->values[i * this->columns + j];
				else
					m3.values[i * m3.columns + j] = m2.values[(i - this->rows) * m2.columns + j];
			}
		}
		return m3;
	} 
	
	Matrix concatenateColumns (const Matrix & m2) const {
		vector<T> zero[this->rows * (this->columns+m2.columns)] = {0};
		Matrix m3(this->rows, this->columns+m2.columns, zero);
		int i, j;
		for (j = 0; j < m3.columns; ++ j) {
			for (i = 0; i < m3.columns; ++ i) {
				if(j < this->columns) 
					m3.values[i * m3.columns + j] = this->values[i * this->columns + j];
				else
					m3.values[i * m3.columns + j] = m2.values[i * m2.columns + (j - this->columns)];
			}
		}
		return m3;
	} 
	
	Matrix reshape (int rows, int cols) const {
		vector<T> zero[1000] = {0};
		Matrix m3 (cols, rows, zero);
		Matrix m4 (rows, cols, zero);
		
		int i, j;
		vector<vector<T>> values = new vector<T> [this->rows]; 
		//二维vector的创建！！！超级神奇 先进行第一层的动态分配
		for (i = 0; i < this->rows; ++ i) {
			vector<T> = new vector<T> [this->columns]; //再用一个循环进行第二层的分配 
		}
		for (i = 0; i < this->rows; ++ i) { //用于数据的储存 
			for (j = 0; j < this->columns; ++ j) {
				values[i][j] = this->values[i*this->columns+j];
			}
		} 
		
		//按列将数据存入m3
		int count = 0;
		for (j = 0; j < this->columns; ++ j) {
			for (i = 0; i < this->rows; ++ i) {
				while (count < m3.rows*m3.columns) {
					m3.values[count] = values[i][j];
					count ++; 
				}
			}
		}
		
		//取m3的转置得到结果
		for (i = 0; i < m3.rows; ++ i) {
			for (j = 0; j < m3.columns; ++ j) 
				m4.values[j*m4.columns+i] = m3.values[i*m3.columns+j];	
		} 
		
		for (i = 0; i < this->rows; ++ i){
			delete [] values[i];
		}
		delete [] values;
		return m4; 
	}
	
	Matrix transpose () const {
		vector<T> zero[this->rows*this->columns] = {0};
		Matrix m3 (this->columns, this->rows, zero);
		
		int i, j;
		for (i = 0; i < this->rows; ++ i) {
			for (j = 0; j < this->columns; ++ j) {
				m3.values[j*m3.columns+i] = this->values[i*this->columns+j];
			}
		}
		
		return m3;
	}
	
	Matrix operator + (const & m2) const{
		Matrix m3 (*this);
		for (int i = 0; i < this->rows*this->columns; ++ i) 
			m3.values[i] += m2.values[i];
		return m3;
	}
	
	Matrix operator + (vector<T> num) const{
		Matrix m3 (*this);
		for (int i = 0; i < this->rows*this->columns; ++ i) 
			m3.values[i] += num;
		return m3;
	}
	
	Matrix operator - (const & m2) const{
		Matrix m3 (*this);
		for (int i = 0; i < this->rows*this->columns; ++ i) 
			m3.values[i] -= m2.values[i];
		return m3;
	}
	
	Matrix operator - (vector<T> num) const{
		Matrix m3 (*this);
		for (int i = 0; i < this->rows*this->columns; ++ i) 
			m3.values[i] -= num;
		return m3;
	}
	
	Matrix operator * (const & m2) const{
		vector<T> zero[this->rows*m2.columns] = {0};
		Matrix m3 (this->rows, this->columns, zero);
		
		int i, j, k;
		for (i = 0; i < this->rows; ++ i) {
			for (j = 0; j < m2.columns; ++ j) {
				int sum = 0;
				for (k = 0; k < this->columns; ++ k) {
					sum += this->values[i*this->columns+k] * m2.values[k*m2.columns+j];
				}
				m3.values[i*m3.columns+j] = sum;
			}
		}
		return m3;
	}
	
	Matrix operator * (vector<T> num) const{
		Matrix m3 (*this);
		for (int i = 0; i < this->rows*this->columns; ++ i) 
			m3.values[i] *= num;
		return m3;
	}
	
	vector<T> get (int row, int col) const {
		return this->values[row*this->columns+col];	
	} 
	
	Matrix max() const{
		if(this->rows > 1 && this->columns > 1) {
			
		}
	}
	
}; 

int main() { 
    cout << "constructor 1" << endl; 
    Matrix<double> matrix1(3, 3); 
    matrix1.print(); 
     
    const double values1[] = { 
        1, 2, 3, 
        4, 5, 6, 
        7, 8, 9, 
    }; 
    vector<double> values2; 
    for (int i = 0; i < 9; ++ i) { 
        values2.push_back(values1[i]); 
    } 
     
    cout << "constructor 2" << endl; 
    Matrix<double> matrix2(3, 3, values2); 
    matrix2.print(); 
     
    cout << "copy constructor" << endl; 
    Matrix<double> matrix3 = matrix2; 
    matrix3.print(); 
     
    cout << "operator =" << endl; 
    matrix3.get(1, 1) = 10.0; 
    matrix3 = matrix2; 
    matrix3.print(); 
     
    cout << "getColumn" << endl; 
    matrix2.getColumn(2).print(); 
    cout << "getRow" << endl; 
    matrix2.getRow(2).print(); 
     
    cout << "concatenateRows" << endl; 
    matrix1.concatenateRows(matrix2).print(); 
    cout << "concatenateColumns" << endl; 
    matrix1.concatenateColumns(matrix2).print(); 
     
    cout << "reshape" << endl; 
    matrix1.concatenateColumns(matrix2). 
        reshape(6, 3).print(); 
     
    cout << "transpose" << endl; 
    matrix2.transpose().print(); 
     
    cout << "operator +" << endl; 
    (matrix2 + matrix2).print(); 
    cout << "operator +" << endl; 
    (matrix2 + 10).print(); 
    cout << "operator -" << endl; 
    (matrix2.transpose() - matrix2).print(); 
    cout << "operator -" << endl; 
    (matrix2 - 10).print(); 
     
    cout << "operator *" << endl; 
    (matrix2.transpose() * matrix2).print(); 
    cout << "operator *" << endl; 
    (matrix2 * 2).print(); 
     
    cout << "max" << endl; 
    cout << matrix2.max().max().get(1, 1) << endl; 
    cout << "min" << endl; 
    cout << matrix2.min().min().get(1, 1) << endl; 
    cout << "sum" << endl; 
    cout << matrix2.sum().sum().get(1, 1) << endl;
