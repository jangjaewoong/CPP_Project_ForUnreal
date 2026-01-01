#define _USE_MATH_DEFINES
#include <iostream>
#include "Shape.h"
#include <math.h>

Shape::Shape(std::string color) : color{color} {}

std::string Shape::GetColor() const {
    return color;
}

void Shape::Draw() const{
    std::cout<<"도형을 그립니다\n";
}

Circle::Circle(std::string color, double radius) : Shape(color), radius{radius} {}

void Circle::Draw() const{
    std::cout<<"원을 그립니다\n";
}

void Circle::Area() const {
    std::cout<<"원 넓이 : "<<M_PI * radius * radius<<"\n";
}

void Circle::Perimeter() const{
    std::cout<<"원둘레 : "<<2*M_PI*radius<<"\n";
}

double Circle::GetRadius() const {
    return radius;
}

Rectangle::Rectangle(std::string color, double width, double height): Shape(color), width{width}, height{height} {}

void Rectangle::Draw() const {
    std::cout<<"사각형을 그립니다\n";
}

void Rectangle::Area() const {
    std::cout<<"사각형 넓이 : "<<width*height<<"\n";
}

void Rectangle::Perimeter() const {
    std::cout<<"사각형 둘레 : "<<(width+height)*2<<"\n";
}

double Rectangle::GetWidth() const {
    return width;
}

double Rectangle::GetHeight() const {
    return height;
}

Triangle::Triangle(std::string color, double base, double height) : Shape(color), base{base}, height{height} {}

void Triangle::Draw() const{
    std::cout<<"삼각형을 그립니다\n";
}

void Triangle::Area() const {
    std::cout<<"삼각형 넓이 : "<<(base*height)/2<<"\n";
}