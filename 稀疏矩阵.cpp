/*Design a class Sparse that implements interface Matrix: Sparse should has the following public object functions in addition:
A constructor Sparse(int rows, int column), which initializes all elements in the matrix to 0's.
A function Sparse Sparse::operator + (Sparse & sparse2), which returns the pair-wise sum of two sparse matrixes.

HINT
	ϡ������Ǵ����Ԫ�ض�Ϊ0�ľ���
	��ˣ��洢ϡ������ʱ��ֻ�洢��Ϊ0��Ԫ�ؿ��Խ�ʡ�ռ䡣
	���磬�����ش洢һ��1000000x1000000�ĸ�����������Ҫ8TB���ڴ档
	���ǣ��������ֻ��10����0Ԫ�أ���ô����ֻ���¼��10��Ԫ���ھ����е�λ�ú�ֵ��
	Ҫ��¼��10��Ԫ���е�ÿһ�������ǿ���ʹ��һ��3Ԫ��(��,��,ֵ)�����3Ԫ�����Entry�Ѿ�����������á�
	Ҫ��¼��10��Ԫ�أ����ǿ�����һ��vector<Entry>�洢10��Entry�Ķ���
	Ҫ�����10����0Ԫ�ص�ֵ��ֻ��������vector��
	λ��(��,��)�������vector�е�Ԫ�أ�����ֵΪ0��Ԫ�ء�
	��Ŀ��Ҫ��ʵ�ֵ�print������ֻ�����0Ԫ��(��3Ԫ���ʾ)��˳��ΪС�����ȣ�ͬ����С�����ȡ�

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
		// 1.sparse2�е�Ԫ��λ����this��Ϊ0������Ԫ�ط���this�� 
		// 2.sparse2�е�Ԫ��λ����this��Ҳ��ֵ������ֵ��ӣ�
		// 3.����ֵ��Ӻ�Ϊ0��ɾ����Ԫ�� 
		int len1 = this->entrys.size();
		int len2 = sparse2.entrys.size();
		
		for (int j = 0; j < len2; ++ j) { 
			int flag = 0;
			for (int i = 0; i < len1; ++ i) {
				if(this->entrys[i].column == sparse2.entrys[j].column && this->entrys[i].row == sparse2.entrys[j].row) {
					flag = 1;
					this->entrys[i].value += sparse2.entrys[j].value; //�ڶ������ 
				} 
			}
			if(flag == 0) this->entrys.push_back(sparse2.entrys[j]); //��һ����� 
		}
		
		for (int i = 0; i < this->entrys.size(); ++ i) { //�����������ע��this��size�Ѿ������˱仯 
			if(this->entrys[i].value == 0) this->entrys.erase(this->entrys.begin()+i); 	
		} 
		
		return *this;
	}
	
	int size(int dimension) const {
		return this->entrys.size();
	}
	
	void set(int row, int column, double value) { //��ֵ�����entrys 
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
	
	//���Ҫ��С�����ȣ�ͬ��С�����ȵ�˳��
	//��֪vector�޷�ֱ�ӽ���Ԫ��˳��ʹ��ð������ 
	void print() { 
		Sparse m1 = *this; 
		for(int i = 0; i < m1.entrys.size(); ++ i) {  
			for (int j = 0; j < m1.entrys.size()-i-1; ++ j) {
				if(m1.entrys[i].row > m1.entrys[i+1].row) { //��С�����ȵ�ð������ 
					Entry temp = m1.entrys[i+1];;
					m1.entrys[i+1] = m1.entrys[i];
					m1.entrys[i] = temp;
				}
				
				if(m1.entrys[i].row == m1.entrys[i+1].row) { //ͬ�У���С�����ȵ�ð������ 
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
