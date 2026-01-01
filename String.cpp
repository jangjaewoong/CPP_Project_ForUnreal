#include <iostream>
#include "String.h"

void String::Print() const {
    std::cout << data << std::endl;
}

void String::Length() const {
    std::cout << length << std::endl;
}

void String::GetData() const {
    std::cout << "메모리 주소 : "<< (void*)data<< std::endl;
}