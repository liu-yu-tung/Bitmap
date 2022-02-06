#ifndef _RGB_H_
#define _RGB_H_
#include <iostream>

using namespace std;

class RGB {
    
public:
    friend class BitmapBase;    
    RGB(){
        r = 0;
        g = 0;
        b = 0;
    }
    RGB(int _r, int _g, int _b){
        r = _r;
        g = _g;
        b = _b;
    }
    RGB(const RGB& c){
        r = c.r;
        g = c.g;
        b = c.b;
    }
    
    RGB& operator=(const RGB& c){
        r = c.r;
        g = c.g;
        b = c.b;
        return *this;
    }
    RGB operator+(const RGB& c){
        RGB result;
        result.r = (r+c.r);
        result.g = (g+c.g);
        result.b = (b+c.b);
        return result;

    }
    RGB& operator+=(const RGB& c){
        r += c.r;
        g += c.g;
        b += c.b;
        return *this; 
    }
    RGB operator-(const RGB& c){
        RGB result;
        result.r = (r-c.r);
        result.g = (g-c.g);
        result.b = (b-c.b);
        return result;

    }
    RGB& operator-=(const RGB& c){
        r -= c.r;
        g -= c.g;
        b -= c.b;
        return *this; 
    }
    friend ostream& operator<<(ostream& o, const RGB& c){
        o << "("; 
        o << c.r << ", ";
        o << c.g << ", ";
        o << c.b << ")";
        return o;
    } 
protected:
    int r;
    int g;
    int b;
};

#endif
