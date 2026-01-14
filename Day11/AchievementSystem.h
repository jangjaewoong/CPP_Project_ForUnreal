#ifndef ACHIEVEMENTSYSTEM_H
#define ACHIEVEMENTSYSTEM_H

#include <iostream>
#include <set>
#include <map>
#include <memory>

class AchievementSystem {
    private :
        std::set<std::string> achievements;
        std::map<std::string, std::set<std::string>> playerAchievements;
        static std::unique_ptr<AchievementSystem> AchievementSystem_instance;
        AchievementSystem(){};
    public :
        static AchievementSystem& AchievementSystem_GetInstance();
        void AddAchievement(std::string name);
        void UnlockAchievement(std::string playerName, std::string achievement);

        bool HasAchievement(std::string playerName, std::string achievement) const;
        std::set<std::string> GetPlayerAchievements(std::string playerName) const;

        void DisplayAchievements(std::string playerName) const;
        void DisplayAllAchievements() const;
};

#endif