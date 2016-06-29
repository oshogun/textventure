#include "Inventory.h"


void Inventory::insertItem(std::unique_ptr<Item> & item, INVENTORIES type)
{
	switch(type) {
		case CONSUMABLES:
			consumables.insert(std::make_pair(item->getID(), std::move(item)));
			break;
		case EQUIPMENT:
			equipment.insert(std::make_pair(item->getID(), std::move(item)));
			break;
		case MISC:
			misc.insert(std::make_pair(item->getID(), std::move(item)));
			break;
	}
}

bool Inventory::hasItem(unsigned ID, INVENTORIES type)
{
	switch(type) {
		case CONSUMABLES: 
		{
			auto found = consumables.find(ID);
			return found != consumables.end();
		}
		case EQUIPMENT:
		{
			auto found = equipment.find(ID);
			return found != equipment.end();
		}
		case MISC:
		{
			auto found = misc.find(ID);
			return found != misc.end();
		}
	}
}




