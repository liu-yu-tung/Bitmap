#ifndef _TRI_H_
#define _TRI_H_

#include <iostream>
#include "base.h"

using namespace std;

class Tri: public Base{
public:
   Tri() {
        ref = Point(0, 0);
        color = RGB(0, 0, 0);
        count = 0;
        left = 0;
        right = 0;
        height = 0;
        
    }
    Tri(const Point _ref, int _left, int _right, int _height, RGB _color) {
        ref = _ref;
        left = _left;
        right = _right;
        height = _height;
        color = _color;
    }
    void operator*=(double scale) {
        left *= scale;
        right *= scale;
        height *= scale;
    }
    void draw(Bitmap& map, int method) const {
        map.drawSolidTriangle(ref, left, right, height, color, method);
    }
    Base* copy() const {
        Tri* tri;
        tri = new Tri;
        tri->ref = ref;
        tri->left = left;
        tri->right = right;
        tri->height = height;
        return tri;
    }
protected:
    int left;
    int right;
    int height;
};

/*
int main () {
    Bitmap map(400, 400);
    Tri red_tri(Point(0, 0), 50, 100, 150, RGB(255, 0, 0));
    Base* green_tri;
    green_tri = red_tri.copy();
    green_tri->setColor(RGB(0, 255, 0));
    *green_tri *= 0.5;
    red_tri.draw(map, 0);
    green_tri->draw(map, 0);
    map.save("tri.bmp");
    return 0;
}
*/

#endif
