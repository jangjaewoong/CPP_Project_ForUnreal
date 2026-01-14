#include <iostream>
#include "Player.h"

Player::Player() : name{""}, score{0}, level{1} {}  // 기본 생성자
Player::Player(std::string name) : name{name}, score{0}, level{1} {}  // 추가!
Player::Player(std::string name, int score, int level) 
    : name{name}, score{score}, level{level} {}  // = 제거, 세미콜론

void Player::AddScore(int points) {
    this->score += points;
    std::cout << points << "점을 획득하였습니다!\n";
}

void Player::LevelUp() {
    ++level;
    std::cout << "레벨 업! (레벨 " << level << ")\n";
}

void Player::Display() const {
    std::cout << "사용자 이름: " << name << "\n";
    std::cout << "현재 점수: " << score << "\n";  // name → score
    std::cout << "레벨: " << level << "\n";
}