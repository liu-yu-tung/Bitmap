#ifndef _BITMAP_H
#define _BITMAP_H

#include <iostream>
#include "bitmapbase.h"

using namespace std;

class Bitmap: public BitmapBase {
public:
    Bitmap() {
        xSize = 0;
        ySize = 0;       
        
    }
    Bitmap(int _xSize, int _ySize) {
        xSize = _xSize;
        ySize = _ySize;
        image = new unsigned char[xSize*ySize*3];
    }
    ~Bitmap(){
        delete image;
    }
    void drawSolidTriangle(const Point& ref, int left, int right ,int height, const RGB& c, int m) {
        
        Point start(ref.x-left, ref.y);
        
        int left_end = left;
        int right_end = right;
        double k_left = double(left)/double(height);
        double k_right = double(right)/double(height);
        
        for(int i=0; i<= height; i++){
            start.y = ref.y+i;
            for(int p = 0; p <= (left_end+right_end-i*(k_left+k_right)); p++){
                start.x = ref.x-(left_end-k_left*i)+p;
              
                setPixel(start, c, m);
            } 
        } 
    }

    void drawSolidRect(const Point& base, int width, int height, const RGB& c, int m) {
        Point point(0, 0);
        for(int j=0; j<=height; j++){
            point.y = base.y+j;
            for(int i=0; i<= width; i++){
                point.x = base.x+i;
                    setPixel(point, c, m);
            }    
        }
    }
    
    void drawSolidCircle(const Point& center, int radius, const RGB& c, int m) {
        for(int j=1; j<=radius; j++){
            for(int i=1; i<=radius; i++){
                if ((pow(i,2) + pow(j,2)) <= (pow(radius,2))) {
                    setPixel(center.x+i, center.y+j, c, m);
                    setPixel(center.x-i, center.y+j, c, m);
                    setPixel(center.x+i, center.y-j, c, m);
                    setPixel(center.x-i, center.y-j, c, m);
                }
            }
        }
        for (int i=1; i<=radius; i++){
            setPixel(center.x+i, center.y, c, m);
            setPixel(center.x-i, center.y, c, m);
            setPixel(center.x, center.y+i, c, m);
            setPixel(center.x, center.y-i, c, m);
        }
        setPixel(center.x, center.y, c, m);
    }
};
/*
int main () {
    Bitmap map(800, 800);
    RGB red(255, 0, 0);
    Point ref(200, -200);
    int left = 150;
    int right = 300;
    int height = 200;
    map.drawSolidRect(ref, left, right, red, 0);
    map.save("test.bmp");

    map.clear();

    return 0;
}
*/
#endif

