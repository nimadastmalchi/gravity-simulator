#ifndef components_cpp
#define components_cpp

#include "components.h"

Vector::Vector() : x(0), y(0) {}
Vector::Vector(const double& ix, const double& iy) : x(ix), y(iy) {}
double Vector::getx() const { return x; }
double Vector::gety() const { return y; }
void Vector::setx(const double& x) {
    this->x = x;
}
void Vector::sety(const double& y) {
    this->y = y;
}
double Vector::getmag() {
    return pow(pow(x, 2.0) + pow(y, 2.0), 0.5);
}
Vector Vector::unit_vector() {
    return (*this) / getmag();
}
Vector Vector::operator*(const double& scaler) {
    return Vector(this->x * scaler, this->y * scaler);
}
Vector Vector::operator/(const double& scaler) {
    return Vector(this->x / scaler, this->y / scaler);
}
Vector Vector::operator+(const Vector& other) {
    return Vector(this->x + other.x, this->y + other.y);
}
Vector Vector::operator-(const Vector& other) {
    return Vector(this->x - other.x, this->y - other.y);
}

ostream& operator<<(ostream& out, const Vector& v) {
    out << "(" + to_string(v.getx()) + ", " + to_string(v.gety()) + ")" << endl;
    return out;
}

Point::Point() : loc(Vector()), init_vel(Vector()), rad(0), mass(0), current_time(0) {}
Point::Point(const Vector& iloc, const Vector& i_init_vel, const Vector& iaccel, const double& ir) : loc(iloc), init_vel(i_init_vel), accel(iaccel), rad(ir), mass(2*ir), current_time(0) {}
Vector& Point::getloc() { return loc; }
Vector& Point::getinitvel() { return init_vel; }
Vector& Point::getaccel() { return accel; }
double Point::getrad() const { return rad; }
double Point::getmass() const { return mass; }
double& Point::gettime() { return current_time; }
void Point::inc_time() {
    current_time += TIME_INC;
}

#endif
