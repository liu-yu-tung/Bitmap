#ifndef _HANDLE_H_
#define _HANDLE_H_

#include <iostream>
#include "circle.h"
#include "rect.h"
#include "tri.h"

using namespace std;

class Handle {
public:
    
    Handle() {
        p = NULL;
    }
    ~Handle() {
        if (--p->count == 0)
            delete p;
    }
    Handle (const Handle& another) {
        p = another.p;
        p->count ++; 
    }
    Handle(Point _ref, int _radius, RGB _color) {
        p = new Circle(_ref, _radius, _color);
    }
    Handle(Point _ref, int _width, int _height, RGB _color) {
        p = new Rect(_ref, _width, _height, _color);
    }
    Handle(Point _ref, int _left, int _right, int _height, RGB _color){
        p = new Tri(_ref, _left, _right, _height, _color);
    }

    Handle operator=(Handle another) {
        if (p == NULL) {
            p = another.p;
        }
        if (p!= another.p) {
            --p->count;
            if (p->count <= 0) 
                delete p;
        }
        p = another.p;
        ++p->count;
        return *this; 
    }
    Handle& operator*(const double _scale) {
        if(p->count > 1){
            Base* new_p = p->copy();
            p->count--;
            if (p->count == 0)
                delete p;
            p = new_p;
        }
        *this *= _scale;
        return *this;
    }

    Handle& operator+=(const Point& _ref) {
        if (p->count > 1) {
            Base* new_p = p->copy();
            --p->count;
            p = new_p;
        }
        p->ref += _ref;
        return *this;
    }

    Handle& operator*=(const double _scale) {
        if(p->count > 1){
            Base* new_p = p->copy();
            --p->count;
            p = new_p;
        }
        *p *= _scale;
        return *this;
    }


    void draw(Bitmap& _map, int _method) const{
         p->draw(_map, _method); 
    }
    void setColor(const RGB& _color) {
        p->setColor(_color);
    }
protected:
    Base* p;
}; 

#endif
