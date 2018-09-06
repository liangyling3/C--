/*Design a class Sparse that implements interface Matrix: Sparse should has the following public object functions in addition:
	A constructor Sparse(int rows, int column), which initializes all elements in the matrix to 0's.
	A copy constructor Sparse(Matrix & matrix2).
	A destructor.
	A print function which prints each entry of non-zero element in a single line. Only the triples for the non-zero elements are printed. The triples are ordered first by their row indexes, then by their column indexes.
Hint:
	A sparse matrix is a matrix where most elements are 0's. To represent a sparse matrix efficiently, we only need to store its non-zero elements. Each non-zero element is store with a 3-tuple (row, col, value), where row and col are the row-number and column-number of the element, and value is the value of the element. The class Entry below is the class for this 3-tuple.
	An iterator is a class to visit all of the elements in a container. In this exercise, you need to implement an iterator to inspect all non-zero elements in your Sparse matrix. For more about iterator, please refer to my lecture note (lectureNote6-8.pdf).
EXAMPLE INPUT
	1000000 1000000
	1 1 10
	1000000 1000000 20
	1 1000000 30
	1000000 1 40
EXAMPLE OUTPUT
	(1,1,10)
	(1000000,1000000,20)
	
	(1,1,10)
	(1000000,1000000,20)
	
	(1,1,10)
	(1,1000000,30)
	(1000000,1,40)
	(1000000,1000000,20)
	
	(1,1,10)
	(1,1000000,30)
	(1000000,1,40)
	(1000000,1000000,20)*/ 
	
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
 
//answer
#include <iostream>
#include <vector>
using namespace std;
 
class Sparse : public Matrix {
private:
	vector <Entry> entrys;
	
	//在Sparse中定义遍历器，实现接口 
	class iterator1: public Iterator { 
	private:
		const Sparse * sparse; //储存多个稀疏矩阵的地址 
		int nextIndex; //索引，指向下一个 
	
	public:
		iterator1 (const Sparse *& sparse2) { //copy constructor 
			this->sparse = sparse2; //让指针等于一个引用？？？ 
			nextIndex = 0; //初始化遍历器的第一个索引为0 
		}
		
		bool hasNext() const { //判断是否变量完毕 
			return (this->nextIndex < this->sparse->size(1));
		}
		
		const Entry & next() {
			this->nextIndex ++;
			return this->sparse->entrys[nextIndex - 1];
		}
	};
	
public:
	
	Sparse(int rows, int columns) {
	}
	
	Iterator * iterator() const {
	}
	
	Sparse(const Matrix & matrix2) {
		while(matrix2.iterator.hasNext()) { 
			this->entrys.push_back(matrix2.iterator()->next());
		}
	}
	
	~Sparse(){
	}
	
};
//answer end
 
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
