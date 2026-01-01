#ifndef STRING.H
#define STRING.H

#include <iostream>
#include <cstring>
class String {
    private:
        char* data;
        int length;
    
    public:
        String(const char* str): length{strlen(str)}{ //C언어에서 문자 표현식.
            data = new char[length+1]; //strlen함수는 const char* 타입의 문자열을 받아 길이를 반환해주는 함수이다.
            // +1을 해주는 이유는 문자열의 끝을 알리는 널 문자를 저장해야하기 때문이다.
            // strlen 함수는 순수길이만을 반환하기때문에 저장할때 널문자 크기 1을 더해줘야. 메모리를 안전하게 저장할 수 있다.
            strcpy(data,str); //str 내부 문자열을 data에 복사
        }
        String(const String& other): length{other.length}{
            data = new char[strlen(other.data)+1];
            strcpy(data,other.data);
        }
        ~String(){
            delete[] data;
        }

        void Print() const;
        void Length() const;
        void GetData() const;
};

#endif