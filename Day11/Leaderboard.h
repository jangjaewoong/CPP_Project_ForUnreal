#ifndef LEADERBOARD_H
#define LEADERBOARD_H

#include <iostream>
#include <map>
#include <set>
#include <utility>
#include <memory>
#include "Player.h"

class Leaderboard {
    private :
        std::map<std::string, Player> players;
        std::set<std::pair<int,std::string>> topScores;
        static std::unique_ptr<Leaderboard> LeaderBoard_instance;
        Leaderboard(){};
    public :
        static Leaderboard& LeaderBoard_GetInstance();
        void AddPlayer(std::string name);
        void RemovePlayer(std::string name);
        void UpdateScore(std::string name, int scoreToAdd);
        void DisplayAllPlayers() const;
        void DisplayTopN(int n) const;
        int GetPlayerRank(std::string name) const;
        Player* GetPlayerByName(std::string name);
        
};

#endif