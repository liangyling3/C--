/* The Point2D class was created to model a point in a two-dimensional space.
The Point2D class has the properties x and y that represent the x and the y coordinates, two getter functions for x and y, and the function for returning the distance between two points.
Create a class named Point3D to model a point in a three-dimensional space. Let Point3D be derived from Point2D with the following additional features:
	A data field named z that represents the z-coordinate.
	A no-arg constructor that constructs a point with coordinate (0,0,0).
	A constructor that constructs a point with three specified coordinates.
	A getter function that returns the value for the z coordinate.
	Override the distance function to return the distance between two points in the tree dimensional space.
Hint: In order to override a function in a base class, a derived class should define a function with exactly the same signature. A signature of a function includes the function name and the list of its parameter types.

EXAMPLE INPUT:
	1 2 3
	10 20 30
EXAMPLE OUTPUT:
	point1.getX() = 1
	point1.getY() = 2
	point1.getZ() = 3
	point2.getX() = 10
	point2.getY() = 20
	point2.getZ() = 30
	point1.distance(point2) = 33.6749*/ 

#include <cmath> 
 
class Point2D 
{ 
private: 
    double x; 
    double y; 
     
public: 
    Point2D() { 
        x = 0; 
        y = 0; 
    } 
     
    double getX() { 
        return x; 
    } 
     
    double getY() { 
        return y; 
    } 
     
    void setX(double x) { 
        this->x = x; 
    } 
     
    void setY(double y) { 
        this->y = y; 
    } 
     
    virtual double distance(Point2D & point2) { 
        double dx = x - point2.x; 
        double dy = y - point2.y; 
        return sqrt(dx * dx + dy * dy); 
    } 
     
}; 
 
// answer

#include <iostream>
using namespace std;

class Point3D : public Point2D {
private:
	double z;
	
public:
	Point3D() {
		setX(0);
		setY(0);
		this->z = 0;
	}
	
	Point3D(double x, double y, double z) {
		setX(x);
		setY(y);
		this->z = z;
	}
	
	double getZ() {
		return z;
	}
	
	double distance(Point2D & point2) { //仅实现接口 
		double dx = this->getX() - point2.getX(); 
        double dy = this->getY() - point2.getY(); 
        return sqrt(dx * dx + dy * dy);
	}
	
	double distance(Point3D & point2) {
		double d1 = this->getX() - point2.getX();
		double d2 = this->getY() - point2.getY();
		double d3 = this->getZ() - point2.getZ();
		return sqrt(d1 * d1 + d2 * d2 + d3 * d3);
	} 
	
};

void printDistance(Point3D & point1, Point3D & point2) { //神奇的思路！！重载printDistance就可以解决乱七八糟的问题 
	cout << "point1.distance(point2) = " <<  
        point1.distance(point2) << endl; 
}


// answer end
 
#include <iostream> 
using namespace std; 
 
void printDistance(Point2D & point1, Point2D & point2) { 
    cout << "point1.distance(point2) = " <<  
        point1.distance(point2) << endl; 
} 
 
int main() { 
    double x1; 
    double y1; 
    double z1; 
    double x2; 
    double y2; 
    double z2; 
    cin >> x1; 
    cin >> y1; 
    cin >> z1; 
    cin >> x2; 
    cin >> y2; 
    cin >> z2; 
     
    Point3D point1(x1, y1, z1); 
    Point3D point2(x2, y2, z2); 
     
    cout << "point1.getX() = " << point1.getX() << endl; 
    cout << "point1.getY() = " << point1.getY() << endl; 
    cout << "point1.getZ() = " << point1.getZ() << endl; 
    cout << "point2.getX() = " << point2.getX() << endl; 
    cout << "point2.getY() = " << point2.getY() << endl; 
    cout << "point2.getZ() = " << point2.getZ() << endl; 
     
    printDistance(point1, point2);
}
