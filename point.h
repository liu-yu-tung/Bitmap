#ifndef _POINT_H_
#define _POINT_H_
#include <iostream>

using namespace std;

class Point {
    public:
    friend class BitmapBase;
    friend class Bitmap;
        // Null Constructor
    Point () {
        x = 0;
        y = 0;
    }
    // Copy Constuctor 
    Point (const Point& p) {
        x = p.x;
        y = p.y;
    }
    // Copier
    Point& operator=(const Point& p){
        x = p.x;
        y = p.y;
        return *this;
    }
    Point (int _x, int _y){
        x = _x;
        y = _y;
    }
    Point operator+(const Point& p){
        Point result;
        result.x = (x+p.x);
        result.y = (y+p.y);
        return result;
    }
    Point& operator+=(const Point& p){
        x += p.x;
        y += p.y;
        return *this;
    }
	friend ostream& operator<<(ostream& o, const Point& p) {
        cout << "(" << p.x << ", " << p.y << ")";	
        return o;
        
	}

protected:
    int x;
    int y;
};
/*
int main() {
	Point p1(1, 2), p2(3, 4); // Overload <<
	cout << "p1=" << p1 << " p2=" << p2 << endl;
	Point p3(p1);
	cout << "p3=" << p3 << endl;
	p3 = Point(5, 6);
	cout << "p3=" << p3 << endl;
	// Overload +
	cout << "p1+p2=" << p1 + p2 << endl; // Overload +=
	p1 += p3;
	cout << "p1=" << p1 << endl;
	
	return 0;	 
*/

#endif
