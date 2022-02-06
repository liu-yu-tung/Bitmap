#ifndef _CIRCLE_H_
#define _CIRCLE_H_

#include <iostream>
#include "base.h"

using namespace std;

class Circle: public Base{
public:
    Circle() {
        ref = Point(0,0);
        color = RGB(0,0,0);
        radius = 0;
    }
    Circle(const Point _ref, int _radius, RGB _color) {
        ref = _ref;
        color = _color;
        radius = _radius;
    }
    void operator*=(double scale) {
       radius *= scale;
    }
    void draw(Bitmap& map, int method) const {
        map.drawSolidCircle(ref, radius, color, method); 
    }
    Base* copy() const{
        Circle* circle;
        circle = new Circle;
        circle->ref = ref;
        circle->color = color;
        circle->radius = radius;     
        return circle;    
    }
protected:
    int radius;
};

#endif
