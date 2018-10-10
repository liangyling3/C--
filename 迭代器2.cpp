class Entry 
{ 
public: 
    int row; 
    int column; 
    double value; 
}; 
     
class Iterator 
{ 
public: 
    virtual bool hasNext() const = 0; 
    virtual const Entry & next() = 0; 
}; 
     
class Matrix 
{ 
public: 
    virtual Iterator * iterator() const  = 0; //增加了const 
    virtual int size(int dimension) const = 0; 
    virtual void set(int row, int column, double value) = 0;  
    virtual double get(int row, int column) const = 0; 
    virtual void print() = 0;      
    virtual Matrix & operator = (const Matrix & matrix2) = 0; 
}; 
 
#include <iostream> 
using namespace std; 

//implements interface Matrix
class Sparse:public Matrix {

private:
	vector<Entry> matrixs;
	
	//implementation of iterator (inner class)
	class Iterator1: public Iterator, public Entry{ 
	private:
		const Sparse * sparse;
		int nextIndex;
	public:
		Iterator1(const Sparse * s2) {
			this->sparse = s2;
			this->nextIndex = 0;
		}
		
		//overrides
		bool hasNext(){
			return (nextIndex < this->sparse->size(1));
		}
		
		//overrides
		const Entry & next () { //返回类型为Entry的引用
			++ this->nextIndex;
			return this->sparse->matrix[nextIndex-1];
		}
	}; //end of iterator
	
public:
	Sparse(int rows, int columns) {
	}
	
	Sparse(Matrix & m2){
		while(m2.iterator()->hasNext()) {
			this->matrixs.push_back(m2.iterator()->next());	
		}
	}
	
	~Sparse() { 
		delete [] this->values;
	} 
	
	void print() const{ 
		for(int i = 0; i < this->rows; ++ i) {
			for (int j = 0; j < this->columns; ++ j) {
				cout << "    " << this->values[i*this->columns+j];
			}
			cout << endl;
		}
	}
	
	int size(int dimension) const {
		if(dimension == 1) return this->rows;
		return this->columns;
	}
	
	void set(int row, int column, double value) {
		this->values[row*this->columns+column] = value;
	} 
	
	double get(int row, int column) const{
		return this->values[row*this->columns+column];
	}
	
	Matrix & operator = (const Matrix & m2) {
		delete [] this->values;	
		this->rows = m2.size(1);
		this->columns = m2.size(2);
		this->values = new double [this->columns*this->rows];
		for (int i = 0; i < this->rows; ++ i) {
			for (int j = 0; j < this->columns; ++ j) {
				this->values[i*this->columns+j] = m2.get(i,j);
			}
		}
	}
	
	Iterator * iterator() const{ //返回迭代器的指针 
		return Iterator1(this);
	}
};
 
#include <iostream> 
using namespace std; 
 
void printMatrix(Matrix & matrix) { 
    matrix.print(); 
} 
 
// 新增 
void printMatrix2(const Matrix & matrix) { 
    Iterator * it = matrix.iterator(); 
    while (it->hasNext()) { 
        Entry entry = it->next(); 
        cout << "(" << entry.row << "," << entry.column << 
            "," << entry.value << ")" << endl; 
    } 
    delete it; 
} 
 
int main() { 
    int rows; 
    int columns; 
    cin >> rows >> columns; 
     
    int row1; 
    int column1; 
    double value1; 
    cin >> row1 >> column1 >> value1; 
     
    int row2; 
    int column2; 
    double value2; 
    cin >> row2 >> column2 >> value2; 
     
    int row3; 
    int column3; 
    double value3; 
    cin >> row3 >> column3 >> value3; 
     
    int row4; 
    int column4; 
    double value4; 
    cin >> row4 >> column4 >> value4; 
     
     
    Sparse sparse1(rows, columns); 
    Matrix & matrix1 = sparse1; 
    matrix1.set(row1, column1, value1); 
    matrix1.set(row2, column2, value2); 
    matrix1.print(); 
    cout << endl; 
     
    Sparse sparse2(sparse1); 
    Matrix & matrix2 = sparse2; 
    matrix2.print(); 
    cout << endl; 
     
    matrix2.set(row3, column3, value3); 
    matrix2.set(row4, column4, value4); 
    matrix1 = matrix2; 
    matrix1.print(); 
    cout << endl; 
     
    // 新增 
    printMatrix2(matrix1); 
     
} 
