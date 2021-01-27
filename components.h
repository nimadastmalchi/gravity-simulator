#ifndef components_h
#define components_h

#include <iostream>
#include <math.h>

#define TIME_INC 0.1

using namespace std;

class Vector {
private:
    double x, y;
public:
    Vector();
    Vector(const double& ix, const double& iy);
    double getx() const;
    double gety() const;
    void setx(const double& x);
    void sety(const double& y);
    double getmag();
    Vector unit_vector();
    Vector operator*(const double& scaler);
    Vector operator/(const double& scaler);
    Vector operator+(const Vector& other);
    Vector operator-(const Vector& other);
};
ostream& operator<<(ostream& out, const Vector& v);

class Point {
private:
    Vector loc, init_vel, accel;
    double rad, mass, current_time;
public:
    Point();
    Point(const Vector& iloc, const Vector& i_init_vel, const Vector& iaccel, const double& ir);
    Vector& getloc();
    Vector& getinitvel();
    Vector& getaccel();
    double getrad() const;
    double getmass() const;
    double& gettime();
    void inc_time();
};

#endif