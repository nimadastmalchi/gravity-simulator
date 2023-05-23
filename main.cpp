#include <iostream>
#include <string>
#include <unistd.h>
#include <math.h>

#include "components.h"
#include "canvas.h"

#define G -0.000000001

using namespace std;

unsigned num_objs;
Point** objects;

void refresh();
void update_accels();
void update_locs(const int& X_RES, const int& Y_RES);

int main() {
    num_objs = 2;
    objects = new Point*[num_objs];
    objects[0] = new Point(Vector(50, 20), Vector(0, 0), Vector(0, 0), 1, 100000000);
    objects[1] = new Point(Vector(60, 20), Vector(1, 1), Vector(0, 0), 1, 100000000);
    
    Canvas c;
    while (true) {
        update_accels();
        update_locs(c.getxres(), c.getyres());
        c.refresh(objects, num_objs);
        c.print_map();
    }
}

void update_accels() {
    // a = G * m2 / r^2
    for (unsigned i = 0; i < num_objs; i++) {
        Point* current = objects[i];
        for (unsigned j = 0; j < num_objs; j++) {
            // If current == other, continue:
            if (i == j) continue;
            
            // Get the direction vector (unit vector):
            Point* other = objects[j];
            Vector dir = other->getloc() - current->getloc();
            dir = dir / dir.getmag();
            
            // Get the distance between the two points:
            double x_squared = pow(current->getloc().getx(), 2.0);
            double y_squared = pow(current->getloc().gety(), 2.0);
            double d = pow(x_squared + y_squared, 0.5);
            
            // Calcualte the new acceleration of current object due to other object
            double new_accel_mag = ( G * other->getmass() ) / ( pow(d, 2.0) );
            Vector new_accel = dir * new_accel_mag;
            
            // Update current's acceleration:
            current->getaccel() = current->getaccel() + new_accel;
        }
        
    }
    
}

void update_locs(const int& X_RES, const int& Y_RES) {
    for (unsigned i = 0; i < num_objs; i++) {
        Point* current = objects[i];
        
        // Increment time:
        current->inc_time();
        
        double current_time = current->gettime();
        
        double new_x = current->getloc().getx() + current->getinitvel().getx() * current_time + 0.5 * current->getaccel().getx() * pow(current_time, 2.0);
        double new_y = current->getloc().gety() + current->getinitvel().gety() * current_time + 0.5 * current->getaccel().gety() * pow(current_time, 2.0);
        
        // Check for reflections:
        
        // v = v0 + a * t
        Vector old_vel = current->getinitvel() + current->getaccel() * current->gettime();
        if (new_x <= 0 || new_x >= X_RES) {
            current->getinitvel() = Vector(-old_vel.getx(), old_vel.gety());
            current->reset_time();
            if (new_x <= 0) {
                new_x = 1;
            } else if (new_x >= X_RES) {
                new_x = X_RES - 2;
            }
        }
        if (new_y <= 0 || new_y >= Y_RES) {
            current->getinitvel() = Vector(old_vel.getx(), -old_vel.gety());
            current->reset_time();
            if (new_y <= 0) {
                new_y = 1;
            } else if (new_y >= Y_RES) {
                new_y = Y_RES - 2;
            }
        }
        
        current->getloc() = Vector(new_x, new_y);
    }
}
