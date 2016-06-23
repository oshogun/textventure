#include "Player.h"

Player::Player(): level(1), experiencePoints(0), goldCoins(100), proficiencies(57,5), stats(7,5)
{
    name = "Test Dude";
    backstory = "This dude was created for testing purposes.\n";
    appearanceDescription = "He looks like a bunch of pixels\n";
}

void Player::printInfo() 
{
    std::cout << "Name: " << name << "\n" << "Backstory: " << backstory; 
    std::cout << "Appearance: " << appearanceDescription << "\nLevel: " << level << "\n";
    std::cout << "Experience: " << experiencePoints << "\n" << "Coins: " << goldCoins << "\n\n";
    std::cout << listProficiencies() << "\n" << listStats() << "\n";
    std::cout << "\n";

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
    for (int i = 1; i < names.size() / 2; i++) {
        buffer << names[i - 1] << proficiencies[i- 1] << "\t";
        buffer << names[i] << proficiencies[i] << "\n";
    }
    text = buffer.str();
    return text;
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
    p.printInfo();
}
