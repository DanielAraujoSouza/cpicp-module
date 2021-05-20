#include "../include/Point3.h"

Point3::Point3(double x, double y, double z) : x(x), y(y), z(z) { };

Point3::~Point3() { };

void Point3::Set(double newX, double newY, double newZ) {
  x = newX;
  y = newY;
  z = newZ;
}

double Point3::Get(char axis) {
  if (axis == 'x') {
    return x;
  }
  else if (axis == 'y') {
    return y;
  }
  else {
    return z;
  }
}