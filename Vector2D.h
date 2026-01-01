#ifndef VECTOR2D.H
#define VECTOR2D.H
#include <iostream>
class Vector2D {
    private :
        float x;
        float y;
    
    public :
        Vector2D();
        Vector2D(float x, float y);
        Vector2D(const Vector2D& other);
        Vector2D operator+(const Vector2D& other) const;
        Vector2D operator-(const Vector2D& other) const;
        float Magnitude() const;
        Vector2D Normalize() const;
        void Print() const;
};

#endif