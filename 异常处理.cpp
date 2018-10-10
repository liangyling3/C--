#include <stdexcept> 
using namespace std; 
 
class NonPositiveValueException : public out_of_range 
{ 
public: 
    NonPositiveValueException() : out_of_range("non-negative") { 
    } 
}; 
 
class Vector 
{ 
private: 
    int length; 
    double * elements; 
     
    void assign(const Vector & vector) { 
        length = vector.length; 
        elements = new double[length]; 
        for (int i = 0; i < length; ++ i) { 
            elements[i] = vector.elements[i]; 
        } 
    } 
     
public: 
    Vector(int size) { //constructor
        length = size; 
        elements = new double[size]; 
    } 
     
    ~Vector() { 
        delete [] elements; 
    } 
     
    Vector(const Vector & vector) { 
        assign(vector); 
    } 
     
    Vector & operator = (const Vector & vector) { 
        delete [] elements; 
        assign(vector); 
    } 
     
    int size() const { 
        return length; 
    } 
     
    double get(int index) const { 
        if (index < 0 || index >= length) { 
            throw out_of_range("index"); 
        } 
        return elements[index]; 
    } 
     
    void set(int index, double value) { 
        if (index < 0 || index >= length) { 
            throw out_of_range("index"); 
        } 
        if (value <= 0) { 
            throw NonPositiveValueException(); 
        } 
        elements[index] = value; 
    } 
 
}; 
 
#include <iostream> 
using namespace std; 
 
Vector read() { 
    int size; 
    cin >> size; 
    Vector vector(size); 
    for (int i = 0; i < size; ++ i) { 
        double value; 
        cin >> value; 
        vector.set(i, value); 
    } 
    return vector; 
} 
 
void print(const Vector & vector) { 
    for (int i = 0; i < vector.size(); ++ i) { 
        cout << vector.get(i) << " "; 
    } 
    cout << endl; 
} 
 
int main() { 
    Vector vector = read(); 
    for (int i = 0; i < 5; ++ i) { 
     
        try { 
            int index; 
            double value; 
            cin >> index >> value; 
            vector.set(index, value); 
            print(vector); 
        } 
        
    	catch (NonPositiveValueException & ex){
			cout << "caught: NonPositiveValueException" << endl;
		}
		
		catch (out_of_range & ex) {
			cout << "caught: out_of_range" << endl;
		}
 
    } 
}
