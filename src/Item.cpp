#include "Item.h"
#include "Inventory.h"

Item::Item(std::string name, unsigned ID, unsigned level, ITEM_RARITY rarity, bool consumable, bool equipable):
    name(name), ID(ID), level(level), rarity(rarity), equipable(equipable), consumable(consumable) {}

// for test
int main()
{
    Inventory inv;
	std::unique_ptr<Item> item(new Item("Thunderfury",200,10,EPIC,false,true));
    inv.insertItem(item, EQUIPMENT);	
    std:: cout << inv.hasItem(200, EQUIPMENT) << "\n";
    std:: cout << inv.hasItem(90125, MISC) << "\n";  
}
