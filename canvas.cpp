#ifndef canvas_cpp
#define canvas_cpp

#include "canvas.h"
#include <unordered_map>
#include <string>
#include <unistd.h>

#define WAIT_TIME 7000

Canvas::Canvas() {
    int i, j;
    
    for (i = 0; i < X_RES; i++) {
        map[i][0] = '-';
    }
    
    for (i = 0; i < X_RES; i++) {
        for (j = 1; j < Y_RES - 1; j++) {
            if (i == 0 || i == X_RES - 1) {
                map[i][j] = '|';
            } else {
                map[i][j] = ' ';
            }
        }
    }
    
    for (i = 0; i < X_RES; i++) {
        map[i][Y_RES - 1] = '-';
    }
    
}

void Canvas::print_map() {
    cout << "\033[2J"; // clear the screen
    
    string output = "";
    for (int j = 0; j < Y_RES; j++) {
        for (int i = 0; i < X_RES; i++) {
            char pixel = map[i][j];
            if (pixel == '@') {
                if (j == 0 || j == Y_RES - 1) {
                    map[i][j] = '-';
                } else if (i == 0 || i == X_RES - 1) {
                    map[i][j] = '|';
                } else {
                    map[i][j] = ' ';
                }
            }
            output += pixel;
        } output += "\n";
    }
    cout << output;
    usleep(WAIT_TIME);
}

void Canvas::refresh(Point** objs, int size) {
    unordered_map<string, Point*> hash;
    
    int i, j;
    for (i = 0; i < size; i++) {
        Point* current = objs[i];
        hash[to_string((int) round(current->getloc().getx())) + ":" + to_string((int) round(current->getloc().gety()))] = current;
    }
    
    for (i = 0; i < X_RES; i++) {
        for (j = 0; j < Y_RES; j++) {
            string s_loc = to_string(i) + ":" + to_string(j);
            if (hash.find(s_loc) != hash.end()) {
                // key found
                map[i][j] = '@';
            }
        }
    }
}

#endif