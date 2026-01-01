#include <iostream>
#include <windows.h> 
#include "Player.h"
#include "Enemy.h"
#include "GameManager.h"


int main(){
    SetConsoleOutputCP(CP_UTF8);
    Player p1 = {"도적", 3};
    Player p2 = {"전사", 2};
    Enemy e1 = {"고스트", 3};
    Enemy e2 = {"구울", 2};
    Enemy e3 = {"슬라임", 1};
    GameManager GM;
    GameManager::ShowGameStats();
    e1.Attack(p1);
    p1.displayStatus();
    GM.FullHeal(p1);
    p1.displayStatus();
    GM.KillEnemy(e1);
    e1.displayStatus();
    GM.DebugPrint(p2);
}