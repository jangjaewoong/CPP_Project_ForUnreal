#include <iostream>
#include "DynamicArray.h"

DynamicArray::DynamicArray() : size{0}, capacity{2} {
    data = new int[capacity];
}

DynamicArray::DynamicArray(int capacity) : size{0}, capacity{capacity}{
    data = new int[capacity];
}

DynamicArray::DynamicArray(const DynamicArray& other) : size{other.size}, capacity{other.capacity}{
    data = new int[other.capacity];
    for(int i = 0; i<other.size; i++){
        data[i] = other.data[i];
    }
}

DynamicArray::~DynamicArray(){
    delete[] data;
}

void DynamicArray::Push(int value){
    if(size>=capacity){
        Resize();
    }
    data[size++] = value;
}

void DynamicArray::Pop(){
    if(size>0){
        size--;
    }
}

int DynamicArray::Get(int index) const {
    if(index<size){
        return data[index];
    } else {
        std::cout<<"잘못된 접근입니다!\n";
        return -1;
    }
}

void DynamicArray::Set(int index, int value){
    if(index<size){
        data[index] = value;
    } else {
        std::cout<<"잘못된 접근입니다!\n";
    }
}

int DynamicArray::Size() const {
    return size;
}

int DynamicArray::Capacity() const {
    return capacity;
}

void DynamicArray::Print() const {
    std::cout<<"{";
    for(int i = 0; i<size; i++){
        if(i!=size-1){
            std::cout<<data[i]<<",";
        } else{
            std::cout<<data[i]<<"}\n";
        }
    }
}

void DynamicArray::Resize() {
    capacity *= 2;
    int* newData = new int[capacity];
    for(int i=0; i<size; i++){
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
}

DynamicArray& DynamicArray::operator=(const DynamicArray& other){
    if(this == &other) return *this;
    delete[] data;
    size = other.size;
    capacity = other.capacity;
    data = new int[capacity];
    for(int i=0; i<size; i++){
        data[i] = other.data[i];
    }
    return *this;
}