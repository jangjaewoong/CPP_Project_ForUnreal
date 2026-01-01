#include <iostream>
#include <cmath>
#include "Vector2D.h"

Vector2D::Vector2D() : x{0}, y{0} {}
Vector2D::Vector2D(float x, float y) : x{x}, y{y} {}
Vector2D::Vector2D(const Vector2D& other) : x{other.x}, y{other.y} {}
Vector2D Vector2D::operator+(const Vector2D& other) const{
    return Vector2D(x+other.x,y+other.y);
}

Vector2D Vector2D::operator-(const Vector2D& other) const{
    return Vector2D(x-other.x,y-other.y);
}

float Vector2D::Magnitude() const {
    return sqrt(x*x+y*y);
}

Vector2D Vector2D::Normalize() const {
    float magnitude = Vector2D::Magnitude();
    if(magnitude==0){
        std::cout<<"경고 : 0 벡터는 정규화할 수 없습니다.\n";
        return Vector2D(0,0);
    }
    return Vector2D(x/magnitude, y/magnitude);
}

void Vector2D::Print() const {
    std::cout<<"("<<x<<","<<y<<")"<<std::endl;
}