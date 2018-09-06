#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Matrix {
private:
	int rows;
	int columns;
	vector<T> values;
	
	vector<T> row2column() const {
		vector<T> temp;
		for(int i = 0; i < this->rows * this->columns; i ++) {
			temp.push_back(this->values[i % this->rows * this->columns + i / this->rows]); 
		}
		return temp;
	}
	
public:
	Matrix (int rows, int columns) { //constructor 1
		this->rows = rows;
		this->columns = columns;
		for (int i = 0; i < rows*columns; ++ i) 
			this->values.push_back(0);
	}
	
	Matrix (int rows, int columns, const vector<T> values) { //constructor 2
		this->rows = rows;
		this->columns = columns;
		for (int i = 0; i < rows*columns; ++ i) 
			this->values.push_back(values[i]);
	}
	
	Matrix(const Matrix & m2) { //copy constructor
		this->columns = m2.columns;
		this->rows = m2.rows;
		for (int i = 0; i < m2.rows*m2.columns; ++ i) 
			this->values.push_back(m2.values[i]);
	}
	
//	~Matrix () { //deconstructor
//		if (!this->values.empty()) {
//			vector<T> temp;
//			temp.swap(this->values);
//		}
//	}
	
	void print() {
		for(int i = 0; i < this->columns*this->rows; ++ i) {
			cout << "    " << this->values[i];
			if((i+1)%this->columns == 0) 
				cout << endl; 
		}
	}
	
	Matrix operator = (const Matrix & m2) {
		this->rows = m2.rows;
		this->columns = m2.columns;
		this->values.clear();
		for (int i = 0; i < m2.rows*m2.columns; ++ i) 
			this->values.push_back(m2.values[i]);
		return *this;
	}
	
	Matrix operator = (T num) {
		this->values.clear();
		for (int i = 0; i < this->rows*this->columns; ++ i) 
			this->values.push_back(num);
		return *this;
	}
	
	Matrix getColumn (int col) const { 
		Matrix m3(this->rows, 1);
		for (int i = 0; i < this->rows; ++ i) 
			m3.values[i] = (this->values[i*this->columns+(col-1)]);
		return m3;
	}
	
	Matrix getRow (int row) const {
		Matrix m3(1, this->columns);
		for (int j = 0; j < this->columns; ++ j) 
			m3.values[j] = (this->values[(row-1)*this->columns+j]);
		return m3;
	}
	
	Matrix concatenateRows (const Matrix & m2) const {
		Matrix m3(this->rows+m2.rows, this->columns);
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
		Matrix m3(this->rows, this->columns+m2.columns);
		int i, j;
		for (j = 0; j < m3.columns; ++ j) {
			for (i = 0; i < m3.rows; ++ i) {
				if(j < this->columns) 
					m3.values[i * m3.columns + j] = this->values[i * this->columns + j];
				else
					m3.values[i * m3.columns + j] = m2.values[i * m2.columns + (j - this->columns)];
			}
		}
		return m3;
	} 
	
	Matrix reshape(int row, int column) const {
		Matrix m(row, column);
		vector<T> temp = row2column();
		for(int i = 0; i < row * column; i ++) {
			m.values[i] = temp[i % column * row + i / column];
		}
		return m;
	}
	
//	Matrix reshape (int rows, int cols)const {
//		Matrix m3 (cols, rows);
//		Matrix m4 (rows, cols);	
//		int i, j, count = 0; 	
//		for (j = 0; j < this->columns; ++ j) { //按列将数据存入m3
//			for (i = 0; i < this->rows; ++ i) {
//				while(count<rows*cols) {
//					m3.values[count] = this->values[i*this->columns+j];
//					count ++;
//				}	
//			}	
//		}
//		//取m3的转置得到结果
//		for (j = 0; j < m3.columns; ++ j) {
//			for (i = 0; i < m3.rows; ++ i) 
//				m4.values[j*m4.columns+i] = m3.values[i*m3.columns+j];	
//		} 
//		return m4; 
//	}
	
	Matrix transpose() {
		vector<T> temp = this->row2column();
		Matrix m(this->columns, this->rows, temp);
		return m;
	}
	
//	Matrix transpose () const {
//		Matrix m3 (this->columns, this->rows);	
//		int i, j;
//		for (i = 0; i < this->rows; ++ i) {
//			for (j = 0; j < this->columns; ++ j) 
//				m3.values[j*m3.columns+i] = this->values[i*this->columns+j];
//		}
//		return m3;
//	}
	
	Matrix operator + (const Matrix & m2) const{
		Matrix m3 (*this);
		for (int i = 0; i < this->rows*this->columns; ++ i) 
			m3.values[i] += m2.values[i];
		return m3;
	}
	
	Matrix operator + (T num) const{
		Matrix m3 (*this);
		for (int i = 0; i < this->rows*this->columns; ++ i) 
			m3.values[i] += num;
		return m3;
	}
	
	Matrix operator - (const Matrix & m2) const{
		Matrix m3 (*this);
		for (int i = 0; i < this->rows*this->columns; ++ i) 
			m3.values[i] -= m2.values[i];
		return m3;
	}
	
	Matrix operator - (T num) const{
		Matrix m3 (*this);
		for (int i = 0; i < this->rows*this->columns; ++ i) 
			m3.values[i] -= num;
		return m3;
	}
	
	//??????????
	Matrix operator * (const Matrix & m2) const{
		Matrix m3 (this->rows, this->columns);	
		int i, j, k;
		for (i = 0; i < this->rows; ++ i) {
			for (j = 0; j < m2.columns; ++ j) {
				int sum = 0;
				for (k = 0; k < this->columns; ++ k) 
					sum += this->values[i*this->columns+k] * m2.values[k*m2.columns+j];
				m3.values[i*m3.columns+j] = sum;
			}
		}
		return m3;
	}
	
	Matrix operator * (T num) const{
		Matrix m3 (*this);
		for (int i = 0; i < this->rows*this->columns; ++ i) 
			m3.values[i] *= num;
		return m3;
	}
	
	T & get (int row, int col) {
		return this->values[row*this->columns+col];	
	} 
	
	Matrix max() const{
		int i, j;
		if(this->rows > 1) {
			Matrix m3(1, this->columns);
			T max;
			for (j = 0; j < this->columns; ++ j) {
				max = this->values[j];
				for (i = 0; i < this->rows; ++ i) 
					if (this->values[i*this->columns+j] > max)
						max = this->values[i*this->columns+j];
				m3.values[j] = max;
			}
			return m3;
		}
		
		Matrix m3(1,1);
		T max = this->values[0];
		for (i = 0; i < this->columns; ++ i) 
			if (this->values[i] > max) max = this->values[i];
		m3.values[0] = max;
		return m3;
	}
	
	Matrix min() const{
		int i, j;
		if(this->rows > 1) {
			Matrix m3(1, this->columns);
			for (j = 0; j < this->columns; ++ j) {
				T min = this->values[j];
				for (i = 0; i < this->rows; ++ i) 
					if (this->values[i*this->columns+j] < min)
						min = this->values[i*this->columns+j];
				m3.values[j] = min;
			}
			return m3;
		}
		
		Matrix m3(1,1);
		T min = this->values[0];
		for (i = 0; i < this->columns; ++ i) 
			if (this->values[i] < min) min = this->values[i];
		m3.values[0] = min;
		return m3;
	}
	
	Matrix sum() const{
		int i, j;
		if(this->rows > 1) {
			Matrix m3(1, this->columns);
			for (j = 0; j < this->columns; ++ j) {
				T sum = 0;
				for (i = 0; i < this->rows; ++ i) 
					sum += this->values[i*this->columns+j];
				m3.values[j] = sum;
			}
			return m3;
		}
		
		Matrix m3(1,1);
		T sum = 0;
		for (i = 0; i < this->columns; ++ i) 
			sum += this->values[i];
		m3.values[0] = sum;
		return m3;
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
}    
