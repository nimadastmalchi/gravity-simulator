#ifndef canvas_h
#define canvas_h

#include <iostream>
#include "components.h"

using namespace std;

class Canvas {
private:
    const static int X_RES = 100;
    const static int Y_RES = 40;
    char map[X_RES][Y_RES];
public:
    Canvas();
    void print_map();
    void refresh(Point** objs, int size);
    int getxres() const;
    int getyres() const;
};

#endif