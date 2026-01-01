#include <iostream>
#include "Vector2D.h"

int main(){
    Vector2D vec1 = {3.0f,4.0f};
    Vector2D vec2 = {4.0f,5.0f};
    Vector2D vec3 = vec1 + vec2;
    Vector2D vec4 = vec1 - vec2;
    vec3.Print();
    vec4.Print();
    float vec3_magitude = vec3.Magnitude();
    std::cout<<vec3_magitude<<std::endl;
    Vector2D norm_vec3 = vec3.Normalize();
    norm_vec3.Print();
    float vec4_magitude = vec4.Magnitude();
    std::cout<<vec4_magitude<<std::endl;
    Vector2D norm_vec4 = vec4.Normalize();
    norm_vec4.Print();
}