/* Design a class Sparse that implements interface Matrix: Sparse should has the following public object functions in addition:
A constructor Sparse(int rows, int column), which initializes all elements in the matrix to 0's.
A function Sparse Sparse::operator * (Sparse & sparse2), which returns the product of two sparse matrixes.

EXAMPLE INPUT
	1000000 2000000 3000000
	
	1 1 10
	1 2000000 50
	1000000 2000000 20
	
	1 3000000 30
	2000000 1 40
	1 1 -10
EXAMPLE OUTPUT
	(1,1,1900)
	(1,3000000,300)
	(1000000,1,800)*/
	
class Entry 
{ 
public: 
    int row; 
    int column; 
    double value; 
    
    Entry operator = (Entry & e1){
		this->row = e1.row;
		this->column = e1.column;
		this->value = e1.value;
		return * this;
	}
}; 
     
class Matrix 
{     
public: 
    virtual int size(int dimension) const = 0; 
     
    virtual void set(int row, int column,  
    double value) = 0; 
     
    virtual double get(int row, int column)  
    const = 0; 
     
    virtual void print() = 0; 
     
}; 
 
//answer
#include <iostream>
#include <vector>
using namespace std;

class Sparse : public Matrix {
private:
	int rows;
	int columns;
	vector <Entry> entrys;  
	
public:
	Sparse(int rows, int columns) { //constructor
		this->rows = rows;
		this->columns = columns;
	}
	
	Sparse operator * (Sparse & sparse2) const {
		//所得矩阵的[i][j]元素，等于m1的第i行元素和m2的第j列元素分别相乘的和 
		//稀疏矩阵中，要使元素值≠0，需有this中的元素（i,k,value1）和sparse2中的元素（k,j,value2）
		Sparse sparse3(this->rows, sparse2.columns);
		
		//此处只计算了乘积，在下一段代码中计算乘积之和 
		for(int i = 0; i < this->entrys.size(); ++ i) {
			for (int j = 0; j < sparse2.entrys.size(); ++ j) {
				if(this->entrys[i].column == sparse2.entrys[j].row) {
					Entry temp;
					temp.row = this->entrys[i].row;
					temp.column = sparse2.entrys[j].column;
					temp.value = this->entrys[i].value * sparse2.entrys[j].value;
					sparse3.entrys.push_back(temp);
				}
			}
		}
		  
		//注意：循环中sparse3的size是在改变的 
		for (int i = 0; i < sparse3.entrys.size(); ++ i) {
			for (int j = i+1; j < sparse3.entrys.size(); ++ j) {
				if (sparse3.entrys[i].column == sparse3.entrys[j].column && sparse3.entrys[i].row == sparse3.entrys[j].row) {
					sparse3.entrys[i].value += sparse3.entrys[j].value;
					sparse3.entrys.erase(sparse3.entrys.begin() + j); 
				}
			}
		}
		return sparse3; 
	}
	
	int size(int dimension) const {
		return this->entrys.size();
	}
	
	void set(int row, int column, double value) { //将值储存进entrys 
		Entry m1;
		m1.column = column;
		m1.row = row;
		m1.value = value;
		this->entrys.push_back(m1); 
	}
	
	double get(int row, int column) const {
		for (int i = 0; i < this->entrys.size(); ++ i) {
			if(this->entrys[i].column == column && this->entrys[i].row == row)
				return this->entrys[i].value;
		}
		return 0;
	}
	
	//输出要求按小行优先，同行小列优先的顺序；
	//查知vector无法直接交换元素顺序，使用冒泡排序 
	void print() { 
		Sparse m1 = *this; 
		for(int i = 0; i < m1.entrys.size(); ++ i) {  
			for (int j = 0; j < m1.entrys.size()-i-1; ++ j) {
				if(m1.entrys[i].row > m1.entrys[i+1].row) { //按小行优先的冒泡排序 
					Entry temp = m1.entrys[i+1];;
					m1.entrys[i+1] = m1.entrys[i];
					m1.entrys[i] = temp;
				}
				
				if(m1.entrys[i].row == m1.entrys[i+1].row) { //同行，按小列优先的冒泡排序 
					if(m1.entrys[i].column > m1.entrys[i+1].column) {  
						Entry temp = m1.entrys[i+1];;
						m1.entrys[i+1] = m1.entrys[i];
						m1.entrys[i] = temp;
					}
				}
			}
		}
		
		for (int i = 0; i < m1.entrys.size(); ++ i) {
			cout << '(' << m1.entrys[i].row << ',' << m1.entrys[i].column << ',' << m1.entrys[i].value << ')' << endl;
		}
	}
};
//answer end

#include <iostream> 
using namespace std; 
 
void print(Matrix & matrix) { 
    matrix.print(); 
} 
 
void readAndSetElement(Matrix & matrix) { 
    int row; 
    int column; 
    double value; 
    cin >> row >> column >> value; 
    matrix.set(row, column, value); 
} 
 
void readAndSetMultipleElements(Matrix & matrix, int count) { 
    for (int i = 0; i < count; ++ i) { 
        readAndSetElement(matrix); 
    } 
} 
 
int main() { 
    int rows; 
    int columns; 
    int & rows2 = columns; 
    int columns2; 
     
    cin >> rows >> columns >> columns2; 
     
    Sparse sparse1(rows, columns); 
    readAndSetMultipleElements(sparse1, 3); 
     
    Sparse sparse2(rows2, columns2); 
    readAndSetMultipleElements(sparse2, 3); 
 
    Sparse sparse3 = sparse1 * sparse2; 
    print(sparse3); 
} 
