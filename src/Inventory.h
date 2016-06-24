#pragma once
#include "Item.h"
#include <list>
#include <memory>
enum INVENTORIES { CONSUMABLES, EQUIPMENT, MISC };

class Inventory {

public:
    Inventory();
    void insertItem(std::unique_ptr<Item> &item, INVENTORIES type);
    bool hasItem(unsigned ID, INVENTORIES type);
private:
    std::list<std::unique_ptr<Item>> equipment;
    std::list<std::unique_ptr<Item>> consumables;
    std::list<std::unique_ptr<Item>> misc;
    
        
};
