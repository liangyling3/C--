#include <iostream>
#include <cassert>
using namespace std;

class Array;

class Matrix
{
public:
	Matrix(int r=0,int c=0);
	
	class Array
	{
	   friend class Matrix;
	public:
	   int & operator[](int j) const; //列标
	private:
	   int size;
	   int * a;
	};
	
	Array & operator[](int i) const //行标
	{
	   return arr[i];
	}
	
private:
	int row;
	int col;
	int size;
	Array * arr;
};

Matrix::Matrix(int r,int c)
{
	assert(r>0 && c>0);
	row=r;
	col=c;
	int i,j;
	size=r;
	arr=new Array[r];
	
	for(i=0;i<c;i++)
	{
	   arr[i].a=new int[c];
	   arr[i].size=c;
	}
	
	for(i=0;i<r;i++)
	{
	   for(j=0;j<c;j++)
	   {
	    arr[i].a[j]=i*col+j;
	   }
	}
	
}

int & Matrix::Array::operator [](int j) const
{
	return a[j];
}

int main()
{
	Matrix m(10,10);
	int tmp=m[2][6];
	cout<<tmp<<endl;
	return 0;
}


