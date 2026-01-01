#include <iostream>
#include <memory>
#include "ResourceManager.h"

int main() {
    std::cout << "=== 리소스 생성 ===\n";
    
    // shared_ptr로 생성
    auto texture1 = std::make_shared<Texture>("player.png", 1, 128, 128);
    auto texture2 = std::make_shared<Texture>("enemy.png", 2, 64, 64);
    auto sound1 = std::make_shared<Sound>("bgm.mp3", 3, 180.5f);
    
    std::cout << "texture1 참조 카운트: " << texture1.use_count() << "\n\n";
    
    std::cout << "=== 리소스 매니저에 추가 ===\n";
    ResourceManager& manager = ResourceManager::GetInstance();
    
    manager.AddResource(texture1);
    manager.AddResource(texture2);
    manager.AddResource(sound1);
    
    std::cout << "texture1 참조 카운트: " << texture1.use_count() << "\n\n";
    
    std::cout << "=== 리소스 목록 ===\n";
    manager.ListResources();
    
    std::cout << "\n=== 리소스 사용 ===\n";
    auto res = manager.GetResource(1);
    if(auto tex = std::dynamic_pointer_cast<Texture>(res)) {
        tex->Display();
    }
    
    std::cout << "\n=== weak_ptr 테스트 ===\n";
    std::weak_ptr<Resource> weakRef = texture1;
    std::cout << "weak_ptr 생성 후 참조 카운트: " << texture1.use_count() << "\n";
    
    texture1.reset();  // 소유권 포기
    std::cout << "texture1 reset 후:\n";
    
    if(auto locked = weakRef.lock()) {
        std::cout << "아직 살아있음: " << locked->GetName() << "\n";
    } else {
        std::cout << "이미 해제됨\n";
    }
    
    std::cout << "\n=== 리소스 제거 ===\n";
    manager.RemoveResource(1);
    manager.ListResources();
    
    return 0;
}