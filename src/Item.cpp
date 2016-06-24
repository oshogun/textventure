#include "Item.h"
#include "Inventory.h"

Item::Item(std::string name, unsigned ID, unsigned level, ITEM_RARITY rarity, bool consumable, bool equipable):
    name(name), ID(ID), level(level), rarity(rarity), equipable(equipable), consumable(consumable) {}

// for test
int main()
{
    //Inventory inv;
    //inv.insertItem(p, EQUIPMENT);
    //std:: cout << inv.hasItem(2112, EQUIPMENT) << "\n";
    //std:: cout << inv.hasItem(90125, MISC) << "\n";  
}
