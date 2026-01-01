#include <iostream>
#include "DynamicArray.h"

int main() {
    std::cout << "=== 기본 테스트 ===\n";
    DynamicArray arr;
    
    arr.Push(10);
    arr.Push(20);
    arr.Print();
    std::cout << "Size: " << arr.Size() << ", Capacity: " << arr.Capacity() << "\n\n";
    
    arr.Push(30);  // Resize!
    arr.Print();
    std::cout << "Size: " << arr.Size() << ", Capacity: " << arr.Capacity() << "\n\n";
    
    arr.Push(40);
    arr.Push(50);  // 또 Resize!
    arr.Print();
    std::cout << "Size: " << arr.Size() << ", Capacity: " << arr.Capacity() << "\n\n";
    
    std::cout << "=== 복사 생성자 테스트 ===\n";
    DynamicArray arr2 = arr;
    arr2.Print();
    
    arr.Set(0, 999);
    std::cout << "arr 수정 후:\n";
    arr.Print();
    arr2.Print();
    std::cout << "\n";
    
    std::cout << "=== 대입 연산자 테스트 ===\n";
    DynamicArray arr3;
    arr3.Push(1);
    arr3.Push(2);
    std::cout << "대입 전: ";
    arr3.Print();
    
    arr3 = arr;
    std::cout << "대입 후: ";
    arr3.Print();
    
    std::cout << "\n=== Get/Set 테스트 ===\n";
    std::cout << "arr[2] = " << arr.Get(2) << "\n";
    arr.Set(2, 777);
    std::cout << "Set 후 arr[2] = " << arr.Get(2) << "\n";
    
    std::cout << "\n=== Pop 테스트 ===\n";
    arr.Print();
    arr.Pop();
    arr.Pop();
    arr.Print();
    
    return 0;
}