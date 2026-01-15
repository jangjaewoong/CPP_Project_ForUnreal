#include <iostream>
#include "Item.h"

Item::Item(std::string name, int value, float weight, std::string category) : name{name}, value{value}, weight{weight}, category{category}{}

void Item::Display() const {
    std::cout << "[" << category << "] " << name 
              << " (가치: " << value << ", 무게: " << weight << ")\n";
}