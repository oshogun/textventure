#pragma once
#include "Item.h"
#include <list>
#include <memory>
#include <map>

enum INVENTORIES { CONSUMABLES, EQUIPMENT, MISC };

class Inventory {

public:
    void insertItem(std::unique_ptr<Item> &item, INVENTORIES type);
    bool hasItem(unsigned ID, INVENTORIES type);
private:
    std::map<unsigned, std::unique_ptr<Item>> equipment;
    std::map<unsigned, std::unique_ptr<Item>> consumables;
    std::map<unsigned, std::unique_ptr<Item>> misc;
    
        
};
