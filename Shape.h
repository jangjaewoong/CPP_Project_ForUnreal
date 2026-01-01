#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>
class Shape {
    protected :
        std::string color;
    public :
        Shape(std::string color);
        std::string GetColor() const;
        void Draw() const;
        void Area() const;
};

class Circle : public Shape {
    private :
        double radius;
    public :
        Circle(std::string color, double radius);
        void Draw() const;
        void Area() const;
        void Perimeter() const;
        double GetRadius() const;
};

class Rectangle : public Shape {
    private :
        double width;
        double height;
    public :
        Rectangle(std::string color, double width, double height);
        void Draw() const;
        void Area() const;
        void Perimeter() const;
        double GetWidth() const;
        double GetHeight() const;
};

class Triangle : public Shape{
    private :
        double base;
        double height;
    public :
        Triangle(std::string color, double base, double height);
        void Draw() const;
        void Area() const;
};
#endif