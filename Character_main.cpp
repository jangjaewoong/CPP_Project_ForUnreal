#include <iostream>
#include "Character.h"

int main(){
    Character* warrior = new Warrior("전사");
    warrior->Attack();
    warrior->UseSkill();
    warrior->DisplayStatus();
    Character* magician = new Mage("마법사");
    magician->Attack();
    magician->UseSkill();
    magician->DisplayStatus();
    Character* archer = new Archer("궁수");
    archer->Attack();
    archer->UseSkill();
    archer->DisplayStatus();
}
//g++ -finput-charset=UTF-8 -fexec-charset=CP949 Inventory_main.cpp Inventory.cpp Item.cpp -o main