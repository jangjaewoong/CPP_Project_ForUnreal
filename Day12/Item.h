#ifndef ITEM_H
#define ITEM_H

#include <iostream>

class Item {
    private :
        std::string name;
        int value;
        float weight;
        std::string category;
    public :
        Item(std::string name, int value, float weight, std::string category);

        std::string GetName() const {return name;};
        int GetValue() const { return value; };
        float GetWeight() const { return weight;};
        std::string GetCategory() const { return category;};

        void Display() const;
};

#endif 