#include <iostream>
#include "Resource.h"

Resource::Resource(std::string name, int id) : name{name}, id{id} {}

Resource::~Resource(){
    std::cout<<"Resource 소멸\n";
}

std::string Resource::GetName() const {
    return name;
}

int Resource::GetId() const {
    return id;
}

Texture::Texture(std::string name, int id, int w, int h): Resource(name,id), width{w}, height{h} {}

Texture::~Texture() {
    std::cout<<"Texture 소멸\n";
}
void Texture::Load() {
    std::cout<<id<<"번 째 텍스처 : "<<name<<"을(를) 불러옵니다.\n";
}

void Texture::Display() const{
    std::cout<<width<<"X"<<height<<"크기 텍스쳐를 화면에 띄웁니다.\n";
}

Sound::Sound(std::string name, int id, float duration) : Resource(name,id), duration{duration} {}

Sound::~Sound() {
    std::cout<<"Sound 소멸\n";
}
void Sound::Load() {
    std::cout<<id<<"번 째 사운드 : "<<name<<"을(를) 불러옵니다.\n";
}

void Sound::Play() const {
    std::cout<<duration<<"초 동안 사운드를 재생합니다\n";
}