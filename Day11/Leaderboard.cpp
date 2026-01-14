#include <iostream>
#include <map>
#include <set>
#include <utility>
#include <memory>
#include "Leaderboard.h"

std::unique_ptr<Leaderboard> Leaderboard::LeaderBoard_instance = nullptr;

Leaderboard& Leaderboard::LeaderBoard_GetInstance(){
    if(!LeaderBoard_instance){
        LeaderBoard_instance.reset(new Leaderboard());
        std::cout << "리더보드 생성!\n";
    }
    return *LeaderBoard_instance;
}

void Leaderboard::AddPlayer(std::string name){
    if(players.find(name) != players.end()) {
        std::cout << name << "은(는) 이미 존재합니다!\n";
        return;
    }

    Player newPlayer(name);
    players[name] = newPlayer;
    topScores.insert({newPlayer.GetScore(), name});
    std::cout << "✅ 플레이어 추가: " << name << "\n";
}

void Leaderboard::UpdateScore(std::string name, int scoreToAdd){
    auto it = players.find(name);
    if(it == players.end()) {
        std::cout << "❌ " << name << "을(를) 찾을 수 없습니다!\n";
        return;
    }
    int oldScore = it->second.GetScore();
    topScores.erase({oldScore, name});
    
    it->second.AddScore(scoreToAdd);
    int newScore = it->second.GetScore();
    
    topScores.insert({newScore, name});
}

void Leaderboard::RemovePlayer(std::string name){
    auto it = players.find(name);
    if(it == players.end()){
        std::cout << "❌ 해당 이름을 가진 플레이어가 존재하지 않습니다.\n";
        return;
    }
    int score = it->second.GetScore();
    players.erase(it);
    topScores.erase({score, name});
    std::cout << "🗑️  " << name << "을(를) 제거했습니다!\n";
}

void Leaderboard::DisplayAllPlayers() const {
    if(players.empty()) {
        std::cout << "플레이어가 없습니다.\n";
        return;
    }
    
    std::cout << "=== 전체 플레이어 (" << players.size() << "명) ===\n";
    for(auto it = players.begin(); it != players.end(); ++it){
        const Player& player = it->second;
        std::cout << "[이름]: " << player.GetName() 
                  << " | [레벨]: " << player.GetLevel() 
                  << " | [점수]: " << player.GetScore() << "\n";  // ⭐ \n 추가!
    }
}

void Leaderboard::DisplayTopN(int n) const {
    if(topScores.empty()) {
        std::cout << "플레이어가 없습니다.\n";
        return;
    }
    
    std::cout << "=== Top " << n << " 리더보드 ===\n";
    int rank = 1;
    
    // ⭐ rbegin()으로 역순 순회 (높은 점수부터)
    for(auto it = topScores.rbegin(); it != topScores.rend() && rank <= n; ++it) {
        std::cout << rank << "위: " << it->second 
                  << " (" << it->first << "점)\n";
        rank++;
    }
}

int Leaderboard::GetPlayerRank(std::string name) const {
    auto playerIt = players.find(name);
    if(playerIt == players.end()) {
        return -1;
    }
    
    int rank = 1;
    
    // ⭐ rbegin()으로 역순 순회
    for(auto it = topScores.rbegin(); it != topScores.rend(); ++it) {
        if(it->second == name) {
            return rank;
        }
        rank++;
    }
    
    return -1;
}

Player* Leaderboard::GetPlayerByName(std::string name){
    auto it = players.find(name);
    if(it != players.end()) {
        return &(it->second);
    }
    return nullptr;
}