#include <iostream> 
#include <string>
#include <vector>
using namespace std;

class Integer
{
public:
	int value;
	Integer * other;
	
	Integer()
	{
		value = 0;
		other = 0;
	}	
	
	~Integer ()
	{
		if (other != NULL)	delete [] other;
	}

	Integer & operator = (const Integer b) 
	{
		value = b.value;
		return *this;
	}
	
	Integer & operator -= (int num) 
	{
		this->value -= num;
		this->other->value -= num;
		
		return * this;
	}
	
	Integer & operator += (Integer & b) 
	{
		this->value += b.value;
		this->other->value += b.value;
		return *this; 
	}
};

void link (Integer & a, Integer & b) 
{
	a.other = &b;
	b.other = &a;
} 

istream & operator >> (istream & in, Integer & i) 
{
	in >> i.value;
} 

ostream & operator << (ostream & out, Integer & i)
{
	out << i.value;
}

int main() 
{ 
    Integer a, b; 
    cin >> a >> b; 
    cout << a << " " << b << endl; 
    link(a, b); 
    a -= 100; 
    cout << a << " " << b << endl; 
    b += a; 
    cout << a << " " << b << endl; 
} 
