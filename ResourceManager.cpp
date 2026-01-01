#include <iostream>
#include <map>
#include <memory>
#include "ResourceManager.h"

std::unique_ptr<ResourceManager> ResourceManager::instance = nullptr;

ResourceManager& ResourceManager::GetInstance(){
    if(!instance){
        instance.reset(new ResourceManager());
        std::cout<<"ResourceManager 생성\n";
    }
    return *instance; // 이부분 왜 *instance를 내보내는지.
}

void ResourceManager::AddResource(std::shared_ptr<Resource> resource){
    if(resource) { 
        resources[resource->GetId()] = resource;
        std::cout << "리소스 추가: " << resource->GetName() 
                  << " (ID: " << resource->GetId() << ")\n";
    }
}

std::shared_ptr<Resource> ResourceManager::GetResource(int id){
    auto it = resources.find(id);
    if(it != resources.end()) {
        return it->second;
    }
    std::cout << "리소스 ID " << id << "를 찾을 수 없음\n";
    return nullptr;
}

void ResourceManager::RemoveResource(int id) {
    auto it = resources.find(id);
    if(it != resources.end()) {
        std::cout << "리소스 제거: " << it->second->GetName() << "\n";
        resources.erase(it);
    } else {
        std::cout << "리소스 ID " << id << "를 찾을 수 없음\n";
    }
}

void ResourceManager::ListResources() {
    if(resources.empty()) {
        std::cout << "리소스 없음\n";
        return;
    }
    
    std::cout << "=== 리소스 목록 ===\n";
    for(const auto& pair : resources) {
        std::cout << "[" << pair.first << "] " 
                  << pair.second->GetName() 
                  << " (참조: " << pair.second.use_count() << ")\n";
    }
}