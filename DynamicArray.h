#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

class DynamicArray {
    private :
        int* data;
        int size;
        int capacity;
        void Resize();
    public :
        DynamicArray();
        DynamicArray(int capacity);
        DynamicArray(const DynamicArray& other);
        ~DynamicArray();
        void Push(int value);
        void Pop();
        int Get(int index) const;
        void Set(int index, int value);
        int Size() const;
        int Capacity() const;
        void Print() const;
        DynamicArray& operator=(const DynamicArray& other);
};

#endif