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
    topScores.erase({oldScore,name});
    it->second.AddScore(scoreToAdd);
    int newScore = it->second.GetScore();
    topScores.insert({newScore,name});
}
void Leaderboard::RemovePlayer(std::string name){
    auto it = players.find(name);
    if(it==players.end()){
        std::cout<<"해당 이름을 가진 플레이어가 존재하지 않습니다.\n";
        return;
    }
    int score = it->second.GetScore();
    players.erase(it);
    topScores.erase({score,name});
    std::cout << name << "을(를) 제거했습니다!\n";
}

void Leaderboard::DisplayAllPlayers() const {
    for(auto it = players.begin(); it!= players.end(); it++ ){
        Player player = it->second;
        std::cout<<"[이름] :"<<player.GetName()<<"|[레벨] : "<<player.GetLevel()<<"|[점수] :"<<player.GetScore();
    }
}

void Leaderboard::DisplayTopN(int n) const {
    int count = 0;
    for(auto it = topScores.begin(); it!= topScores.end(); it++ ){
        if(count == n-1){
            std::string name = it->second;
            auto playerit = players.find(name);
            Player player = playerit->second;
            std::cout<<"랭킹 "<<n<<"위\n";
            std::cout<<"[이름] :"<<player.GetName()<<"|[레벨] : "<<player.GetLevel()<<"|[점수] :"<<player.GetScore();
        }
        count++;
    }
}

int Leaderboard::GetPlayerRank(std::string name) const{
    int count = 0;
    auto it = players.find(name);
    if(it == players.end()){
        return -1;
    }
    int score = it->second.GetScore();
    for(auto it = topScores.begin(); it!= topScores.end(); it++ ){
        if(it->first == score){
            return count;
        }
        count++;
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