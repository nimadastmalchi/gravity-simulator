#ifndef canvas_h
#define canvas_h

#include <iostream>
#include "components.h"

#define X_RES 100
#define Y_RES 40

using namespace std;

class Canvas {
private:
    char map[X_RES][Y_RES];
public:
    Canvas();
    void print_map();
    void refresh(Point** objs, int size);
};

#endif