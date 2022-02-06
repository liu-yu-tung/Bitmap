#ifndef _RECT_H_
#define _RECT_H_

#include <iostream> 
#include "base.h"

using namespace std;

class Rect: public Base {
public:
    Rect() {
        ref = Point(0, 0);
        color = RGB(0, 0, 0);
        count = 0;
        width = 0;
        height = 0;

    }
    Rect(const Point _ref, int _width, int _height, RGB _color) {
        ref = _ref;
        width = _width;
        height = _height;
        color = _color;
    }
    void operator*=(double scale) {
        width *= scale;
        height *= scale;
    }
    void draw(Bitmap& map, int method) const {
        map.drawSolidRect(ref, width, height, color, method);
    } 
    Base* copy() const {
        Rect* rect;
        rect = new Rect;
        rect->ref = ref;
        rect->color = color;
        rect->width = width;
        rect->height = height;
        return rect;
    }
protected:
    int width;
    int height;


};
/*
int main() {
    Bitmap map(400, 400);
    Rect red_rect(Point(0, 0), 120, 160, RGB(255, 0, 0));
    Base* green_rect;
    green_rect = red_rect.copy();
    green_rect->setColor(RGB(0, 255, 0));
    *green_rect *= 0.5;
    red_rect.draw(map, 0);
    green_rect->draw(map, 0);
    map.save("rect.bmp");
    return 0;

}
*/
#endif
