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
    saveProficiencies();
    saveStats();
}

void Player::saveProficiencies()
{
    sqlite3 * db;
    sqlite3_stmt * res;
    sqlite3_open("player.db", &db);
    for (auto i = 0; i < proficiencies.size(); i++) {
        std::string sql = "INSERT INTO PROFICIENCIES VALUES (?,?);";
        sqlite3_prepare_v2(db, sql.c_str(), -1, &res, 0);
        sqlite3_bind_int(res, 1, i);
        sqlite3_bind_int(res, 2, proficiencies[i]);
        sqlite3_step(res);
    }
    sqlite3_finalize(res);
    sqlite3_close(db);

}

void Player::saveStats()
{
    sqlite3 * db;
    sqlite3_stmt * res;
    sqlite3_open("player.db", &db);
    std::string sql = "INSERT INTO PLAYER_STATS VALUES(?,?,?,?,?,?,?,?);";
    sqlite3_prepare_v2(db, sql.c_str(), -1, &res, 0);
    sqlite3_bind_text(res,1,name.c_str(),-1,0);
    sqlite3_bind_int(res,2,level);
    sqlite3_bind_int(res,3,experiencePoints);
    sqlite3_bind_int(res,4,hitpoints);
    sqlite3_bind_int(res,5,magicPoints);
    sqlite3_bind_int64(res,6,goldCoins);
    sqlite3_bind_text(res,7,backstory.c_str(),-1,0);
    sqlite3_bind_text(res,8,appearanceDescription.c_str(),-1,0);
    sqlite3_step(res);
    sqlite3_finalize(res);
    sqlite3_close(db);
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
	for (auto i = 1u; i <= 200; i++) {
        expTable.insert(std::make_pair(i, calculateExpToLevel(i)));
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

void Player::receiveDamage(unsigned base_damage) {
    int remaining_hp = hitpoints - base_damage;
    if (remaining_hp < 0) hitpoints = 0;
    else hitpoints = (unsigned) remaining_hp;
}

void Player::saveExpTable()
{
    sqlite3 * db;
    sqlite3_stmt * res;
    sqlite3_open("exp_table.db",&db);
    std::string sql = "CREATE TABLE EXP_TABLE(LEVEL INT PRIMARY KEY, EXP UNSIGNED BIG INT);";
    sqlite3_exec(db, sql.c_str(), NULL, NULL, NULL);
    for (auto i: expTable) {
        sql = "INSERT INTO EXP_TABLE VALUES(?,?);";
        int rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &res,0);
        sqlite3_bind_int(res, 1, i.first);
        sqlite3_bind_int64(res, 2, (sqlite_uint64) i.second);
        int step = sqlite3_step(res);
    }
    sqlite3_finalize(res);
    sqlite3_close(db);
}

void Player::loadExpTable()
{
    sqlite3 * db;
    sqlite3_stmt * res;
    std::cout << "lol" << std::endl;
    sqlite3_open("exp_table.db", &db);
    std::string sql = "SELECT * FROM EXP_TABLE";
    sqlite3_prepare_v2(db, sql.c_str(), -1, &res, 0);
    int step;
    while(1) {
        step = sqlite3_step(res);
        if (step == SQLITE_ROW) {
            expTable.insert(std::make_pair(sqlite3_column_int(res,0), sqlite3_column_int64(res,1)));
        }
        if (step == SQLITE_DONE) break;
    }
    sqlite3_finalize(res);
    sqlite3_close(db);
}

void Player::createDatabases()
{
    //FIXME: Nao ta criando a PORRA do player_stats
    sqlite3 * db;
    sqlite3_open ("player.db", &db);
    const char *sql = "CREATE TABLE PROFICIENCIES (ID INT PRIMARY KEY NOT NULL , VALUE INT NOT NULL);";
    sqlite3_exec(db, sql, NULL,NULL,NULL);
    sql = "CREATE TABLE PLAYER_STATS ( NAME VARCHAR(100) PRIMARY KEY NOT NULL, LEVEL UNSIGNED INT NOT NULL," \
           "EXP UNSIGNED INT NOT NULL, HP UNSIGNED INT NOT NULL, MP UNSIGNED INT NOT NULL," \
           "GOLD UNSIGNED BIG INT NOT NULL,  BACKSTORY TEXT,  APPEARANCE TEXT);";
    sqlite3_exec(db, sql, NULL, NULL, NULL);
    sqlite3_close(db);
}
//temporary for test
int main()
{
    Player p;
    p.createDatabases();
    p.saveInfo();
}
