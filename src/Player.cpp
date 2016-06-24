#include "Player.h"

Player::Player(): level(1), experiencePoints(0), goldCoins(100), proficiencies(57,5), stats(7,5)
{
    name = "Test Dude";
    backstory = "This dude was created for testing purposes.\n";
    appearanceDescription = "He looks like a bunch of pixels\n";
	generateExpTable();
}

void Player::printInfo() 
{
    std::cout << "Name: " << name << "\n" << "Backstory: " << backstory; 
    std::cout << "Appearance: " << appearanceDescription << "\nLevel: " << level << "\n";
    std::cout << "Experience: " << experiencePoints << "\n" << "Coins: " << goldCoins << "\n\n";
    std::cout << listProficiencies() << "\n" << listStats() << "\n";
    std::cout << "\n";

}

void Player::saveInfo() 
{
	std::ofstream file;
	file.open("player_info.atm");
    file << "Name: " << name << "\n" << "Backstory: " << backstory; 
    file << "Appearance: " << appearanceDescription << "\nLevel: " << level << "\n";
    file << "Experience: " << experiencePoints << "\n" << "Coins: " << goldCoins << "\n\n";
    file << listProficiencies() << "\n" << listStats() << "\n";
    file << "\n";
	file.close();
	
}

std::string Player::listProficiencies() 
{
    // here we fucking go
    std::stringstream buffer;
    std::string text;
    auto names = std::vector<std::string> {
        "Swordsmanship:             ", 
        "Axefighting:               ", 
        "Archery:                   ",
        "Gunshooting:               ",
        "Brawling:                  ",
        "Dagger Combat:             ", 
        "Restoration Magic:         ", 
        "Elemental Magic:           ", 
        "Chaos Magic:               ",
        "Martial Arts:              ",
        "Combat Alchemy:            ",
        "Stealth:                   ",
        "Awareness:                 ",
        "Pathfinding:               ",
        "Strategy:                  ",
        "Survivability(jungle):     ", 
        "Survivability(desert):     ",
        "Survivability(mountains):  ",
        "Construction:              ",
        "Alchemy:                   ",
        "Herbalism:                 ",
        "Mining:                    ",
        "Hunting:                   ",
        "Tailoring:                 ",
        "Leatherworking:            ",
        "Blacksmithing:             ",
        "Enchanting:                ",
        "Inscription:               ",
        "Archaeology:               ",
        "Fishing:                   ",
        "Engineering:               ",
        "Language:                  ", 
        "Teaching:                  ",
        "Math:                      ",
        "Woodworking:               ",
        "Lumberjacking:             ",
        "Lore:                      ",
        "Geography:                 ",
        "Philosophy:                ",
        "Leadership:                ",
        "Soloing:                   ",
        "Cooking:                   ",
        "Birb mastery:              ",
        "Empathy:                   ",
        "Focus:                     ", 
        "Medicine:                  ",
        "Speech:                    ",
        "Music:                     ", 
        "Stringed Instruments:      ", 
        "Wind Instruments:          ",
        "Drumming:                  ",
        "Storytelling:              ",
        "Poetry:                    ",
        "Acrobacy:                  ", 
        "Animal Handling:           "
    };
    #pragma unroll(3)
    for (int i = 1; i < names.size(); i++) {
        buffer << names[i - 1] << proficiencies[i- 1] << "\t";
        buffer << names[i] << proficiencies[i] << "\n";
    }
    text = buffer.str();
    return text;
}

unsigned long long int Player::calculateExpToLevel(unsigned int targetLevel) 
{
	if (targetLevel == 1)
		return 100;
	return (unsigned long long)((50 * pow(targetLevel, 2) - 5* targetLevel + 8) + calculateExpToLevel(targetLevel - 1));
}

void Player::generateExpTable()
{
	#pragma unroll(4)
	for (auto i = 1u; i <= 8008; i++) {
		expTable.insert(std::make_pair(i,calculateExpToLevel(i)));
	}
}
std::string Player::listStats()
{
    std::stringstream buffer;
    std::string text;
    auto names = std::vector<std::string> { "STR: ", "CON: ", "DEX: ", "WIS: ", "CHA: ", "INT: ","CSS: "};
    for (int i = 0; i < names.size(); i++) {
        buffer << names[i] << stats[i] << "\n";
    }
    text = buffer.str();
    return text;
}

//temporary for test
int main()
{
    Player p;
    // p.printInfo();
	p.saveInfo();
	std::map<unsigned,unsigned long long> expTable = p.getExpTable();
	std::ofstream file;
	file.open("tabela_exp.txt");
	for (auto it = expTable.cbegin(); it != expTable.cend(); ++it) {
		file << it->first << " : " << it->second << "\n";
	}
	file.close();
}
