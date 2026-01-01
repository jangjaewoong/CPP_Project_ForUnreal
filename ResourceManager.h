#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H
#include <iostream>
#include <memory>
#include <map>
#include "Resource.h"

class ResourceManager {
    private:
        std::map<int, std::shared_ptr<Resource>> resources; 
        static std::unique_ptr<ResourceManager> instance;
        ResourceManager(){};
    public :    
        static ResourceManager& GetInstance();
        void AddResource(std::shared_ptr<Resource> resource);
        std::shared_ptr<Resource> GetResource(int id);
        void RemoveResource(int id);
        void ListResources();
};

#endif