#include <iostream>
#include "Shape.h"

int main() {
    Shape s = {"노란색"};
    s.Draw();
    Circle c = {"흰색",4};
    c.Draw();
    std::cout << "색상: " << c.GetColor() << "\n";
    c.Area();
    c.Perimeter();
    Rectangle r = {"검정색",5,5};
    r.Draw();
    r.Area();
    r.Perimeter();
    Triangle t = {"빨간색",4,3};
    t.Draw();
    t.Area();
    std::cout << "색상: " << t.GetColor() << "\n";
    
    return 0;
}