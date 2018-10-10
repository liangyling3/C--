/*Design a class Sparse that implements interface Matrix: Sparse should has the following public object functions in addition:
A constructor Sparse(int rows, int column), which initializes all elements in the matrix to 0's.
A function Sparse Sparse::operator + (Sparse & sparse2), which returns the pair-wise sum of two sparse matrixes.

HINT
	稀疏矩阵是大多数元素都为0的矩阵。
	因此，存储稀疏矩阵的时候只存储不为0的元素可以节省空间。
	例如，完整地存储一个1000000x1000000的浮点数矩阵需要8TB的内存。
	但是，如果矩阵只有10个非0元素，那么我们只需记录这10个元素在矩阵中的位置和值。
	要记录这10个元素中的每一个，我们可以使用一个3元组(行,列,值)，这个3元组的类Entry已经在主程序定义好。
	要记录这10个元素，我们可以用一个vector<Entry>存储10个Entry的对象。
	要获得这10个非0元素的值，只需查找这个vector。
	位置(行,列)不在这个vector中的元素，就是值为0的元素。
	题目中要求实现的print函数，只输出非0元素(的3元组表示)。顺序为小行优先，同行则小列优先。

EXAMPLE INPUT
	1000000 1000000
	
	1 1 10
	1 1000000 50
	1000000 1000000 20
	
	1 1000000 30
	1000000 1 40
	1 1 -10
EXAMPLE OUTPUT
	(1,1000000,80)
	(1000000,1,40)
	(1000000,1000000,20)*/

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
	vector <Entry> entrys;  
	
public:
	Sparse(int rows, int columns) { //constructor
	}
	
	Sparse operator + (Sparse & sparse2) {
		// 1.sparse2中的元素位置在this中为0，将此元素放入this； 
		// 2.sparse2中的元素位置在this中也有值，将二值相加；
		// 3.若二值相加后为0，删除此元素 
		int len1 = this->entrys.size();
		int len2 = sparse2.entrys.size();
		
		for (int j = 0; j < len2; ++ j) { 
			int flag = 0;
			for (int i = 0; i < len1; ++ i) {
				if(this->entrys[i].column == sparse2.entrys[j].column && this->entrys[i].row == sparse2.entrys[j].row) {
					flag = 1;
					this->entrys[i].value += sparse2.entrys[j].value; //第二种情况 
				} 
			}
			if(flag == 0) this->entrys.push_back(sparse2.entrys[j]); //第一种情况 
		}
		
		for (int i = 0; i < this->entrys.size(); ++ i) { //第三种情况，注意this的size已经发生了变化 
			if(this->entrys[i].value == 0) this->entrys.erase(this->entrys.begin()+i); 	
		} 
		
		return *this;
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
    cin >> rows >> columns; 
     
    Sparse sparse1(rows, columns); 
    readAndSetMultipleElements(sparse1, 3); 
     
    Sparse sparse2(rows, columns); 
    readAndSetMultipleElements(sparse2, 3); 
     
    Sparse sparse3 = sparse1 + sparse2; 
    print(sparse3); 
} 
