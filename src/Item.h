#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

enum ITEM_RARITY { TRASH, COMMON, UNCOMMON, RARE, EPIC, LEGENDARY };

class Item {

public:
    Item();
    Item (std::string name, unsigned ID, unsigned level, ITEM_RARITY rarity, bool consumable, bool equipable);
    void setName(std::string _name) { name = _name; } 
    void setLevel (unsigned _level) { level = _level; }
    void setRarity (ITEM_RARITY _rarity) { rarity = _rarity; }
    void setID(unsigned id) { ID = id; }
    void setConsumable (bool _consumable) { consumable = _consumable; }
    void setEquipable (bool _equipable) { equipable = _equipable; }
    unsigned getID() { return ID; }
    unsigned getLevel() { return level; }
    std::string getName() { return name; }
    ITEM_RARITY getRarity() { return rarity; }
    bool getEquipable() { return equipable; }
    bool getConsumable() { return consumable; }
private:
    ITEM_RARITY rarity;
    std::string name;
    unsigned ID;
    unsigned level;
    bool equipable;
    bool consumable;
    
};
