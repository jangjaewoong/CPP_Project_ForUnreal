#include <iostream>
#include <map>
#include <set>
#include <utility>
#include <memory>
#include "AchievementSystem.h"

std::unique_ptr<AchievementSystem> AchievementSystem::AchievementSystem_instance = nullptr;

AchievementSystem& AchievementSystem::AchievementSystem_GetInstance() {
    if(!AchievementSystem_instance) {
        AchievementSystem_instance.reset(new AchievementSystem());
        std::cout << "업적 시스템 생성!\n";
    }
    return *AchievementSystem_instance;
}

void AchievementSystem::AddAchievement(std::string name){
    if(achievements.find(name)!=achievements.end()){
        std::cout << "업적 '" << name << "'은(는) 이미 존재합니다!\n";
        return;
    }
    achievements.insert(name);
    std::cout << "✨ 새 업적 추가: " << name << "\n";
}

void AchievementSystem::UnlockAchievement(std::string playerName, std::string achievement){
    if(achievements.find(achievement)==achievements.end()){
        std::cout << "❌ 업적 '" << achievement << "'이(가) 존재하지 않습니다!\n";
        return;
    }
    if(playerAchievements[playerName].find(achievement)!=playerAchievements[playerName].end()){
        std::cout << "⚠️  " << playerName << "은(는) 이미 '" 
                  << achievement << "' 업적을 보유하고 있습니다!\n";
        return;
    }
    playerAchievements[playerName].insert(achievement);
    std::cout << "🎉 " << playerName << " 업적 해제: " << achievement << "\n";
}

bool AchievementSystem::HasAchievement(std::string playerName, std::string achievement) const{
    auto playerIt = playerAchievements.find(playerName);
    if(playerIt == playerAchievements.end()) {
        return false;
    }
    
    const std::set<std::string>& playerAchs = playerIt->second;
    return playerAchs.find(achievement) != playerAchs.end();
}

std::set<std::string> AchievementSystem::GetPlayerAchievements(std::string playerName) const {
    auto it = playerAchievements.find(playerName);
    if(it != playerAchievements.end()) {
        return it->second;
    }
    return std::set<std::string>();
}

void AchievementSystem::DisplayAchievements(std::string playerName) const {
    auto it = playerAchievements.find(playerName);
    if(it == playerAchievements.end() || it->second.empty()) {
        std::cout << playerName << "은(는) 아직 업적이 없습니다.\n";
        return;
    }
    
    const std::set<std::string>& achs = it->second;
    std::cout << "🏆 " << playerName << "의 업적 (" << achs.size() << "개):\n";
    for(const std::string& achieve : achs) {
        std::cout << "  ✓ " << achieve << "\n";
    }
}

void AchievementSystem::DisplayAllAchievements() const {
    if(achievements.empty()) {
        std::cout << "등록된 업적이 없습니다.\n";
        return;
    }
    
    std::cout << "=== 전체 업적 목록 (" << achievements.size() << "개) ===\n";
    int index = 1;
    for(const std::string& achieve : achievements) {
        std::cout << index++ << ". " << achieve << "\n";
    }
}