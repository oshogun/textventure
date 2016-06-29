#include "Player.h"

Player::Player(): level(1),
    experiencePoints(0),
    goldCoins(100),
    proficiencies(57,5),
    stats(7,5),
    hitpoints(100)
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
	for (auto i = 1u; i <= 1000; i++) {
		expTable.insert(std::make_pair(i,calculateExpToLevel(i)));
	}
    sqlite3 * expTableDB;
    sqlite3_open("exp_table.db", &expTableDB);
    std::string sql = "CREATE TABLE exp_table(LEVEL INT PRIMARY KEY NOT NULL, EXP INT NOT NULL);";
    sqlite3_exec(expTableDB, sql.c_str(),NULL, 0, NULL);
    sqlite3_stmt *res;

    sql = "INSERT INTO exp_table VALUES(?, ?);";
    for (auto i: expTable) {
        sqlite3_prepare_v2(expTableDB, sql.c_str(), -1, &res, 0);
        sqlite3_bind_int(res, 1, i.first);
        sqlite3_bind_int64(res, 2, i.second);
        sqlite3_step(res);
        sqlite3_finalize(res);
    }
    sqlite3_close(expTableDB);
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

void Player::receiveDamage(unsigned base_damage) {
    int remaining_hp = hitpoints - base_damage;
    if (remaining_hp < 0) hitpoints = 0;
    else hitpoints = (unsigned) remaining_hp;
}

void Player::loadExpTable() {
    sqlite3 * db;
    sqlite3_open ("exp_table.db", &db);

}
//temporary for test
int main()
{
    Player p;
}
