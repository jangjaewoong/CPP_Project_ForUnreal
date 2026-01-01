#ifndef RESOURCE_H
#define RESOURCE_H
#include <iostream>

class Resource {
    protected :
        std::string name;
        int id;
    
    public :
        Resource(std::string name, int id);
        virtual ~Resource();
        virtual void Load() = 0;
        std::string GetName() const;
        int GetId() const;   
};

class Texture : public Resource {
    private :
        int width;
        int height;
    
    public :
        Texture(std::string name, int id, int w, int h);
        ~Texture();
        void Load() override;
        void Display() const;
};

class Sound : public Resource{
    private :
        float duration;
    public :
        Sound(std::string name, int id, float duration);
        ~Sound();
        void Load() override;
        void Play() const;
};
#endif