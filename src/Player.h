#pragma once // Seems to work fine with both G++ and MSVC so yeah

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cmath>
#include <map>
#include <fstream>
#include <sqlite3.h>

enum PROFICIENCIES {
    SWORDSMANSHIP, // Swords (one handed and two handed), katanas, scimitars, whatever
    AXEFIGHTING, // Axes duh
    ARCHERY, // Bows, crossbows
    GUNSHOOTING, // Pau de fogo
    BRAWLING, // Unarmed combat without the use of martial arts
    DAGGER_COMBAT, // Combat with daggers, shortswords
    RESTORATION_MAGIC, // Heals and buffs
    ELEMENTAL_MAGIC, // FIRABALLZZZZZZ
    CHAOS_MAGIC, // Summoning, curses, that kind of shit
    MARTIAL_ARTS, // Training in martial arts, for both unarmed and armed combat
    COMBAT_ALCHEMY, // Understanding of science, use of it in combat (magic that alters the very nature of things in order to make shit explode)
    STEALTH, // Skills that makes it harder for enemies to detect you
    AWARENESS, // Bonus on finding hidden enemies and traps and treasure and shit like that
    PATHFINDING, // Well, I'm just throwing stats here tbh. This could be used to help find secret passages and shit like that
    STRATEGY, // Strategic thinking
    SURVIVABILITY_JUNGLE, // Knowledge of nature, hability to survive in the jungle WELCOME TO THE JUNGLE
    SURVIVABILITY_DESERT, // Knowledge of nature, hability to survive in the desert OF PLANET DUUUNE
    SURVIVABILITY_MOUNTAINS, // Knowledge of nature, hability to survive in the mountains
    CONSTRUCTION, // Hability to build shelters and shit
    ALCHEMY, // Brewing potions, oils, that kinda shit
    HERBALISM, // Knowledge of plants, useful for alchemy
    MINING, // Knowledge of minerals, metals, and mining skills
    HUNTING, // Making traps, tracking beasts, hunting wild animals, and skinning for leather.
    TAILORING, // Working with cloth
    LEATHERWORKING, // Working with leather
    BLACKSMITHING, // Working with metals, making armor and weapons
    ENCHANTING, // Enchanting items to give them special properties
    INSCRIPTION, // Making scrolls of spells. Requires knowledge on one of the other kinds of magic to actually make the scrolls though
    ARCHAEOLOGY, // Learning history by finding artifacts
    FISHING, // Duh
    ENGINEERING, // Skill to make mechanical tools, and also complex constructions
    LANGUAGE, // Proficience to learn foreign languages
    TEACHING, // Proficience to pass knowledge to other characters
    MATH, // Skill with math. May give bonuses to other professions.
    WOODWORKING, // Skill to work wood, build wooden constructions and artifacts
    LUMBERJACKING, // Cutting wood
    LORE, // Knowledge of history and myths and shit like that
    GEOGRAPHY, // Mapmaking and polictical knowledge
    PHILOSOPHY, // Idk what this will be used for
    LEADERSHIP, // Capacity of working in group as a leader
    SOLOING, // Bonuses for playing alone
    COOKING, // HM GOOD FOODS
    BIRB_MASTERY, // Mastery with berbs and borbs
    EMPATHY, // Worrying about others
    FOCUS, // Well you know what focus is
    MEDICINE, // First aid, disease treatment
    SPEECH, // Hability to speach in public, as well as to write elaborate speeches
    MUSIC, // Overall music sensibility and knowledge
    STRINGED_INSTRUMENTS, // Skill with musical instruments like guitar and lute and stuff 
    WIND_INSTRUMENTS, // Flute and shit like that
    KEY_INSTRUMENTS, // Piano, Organ, Accordeon, whatever
    DRUMMING, // Skill with percussive instruments
    SINGING, // Duh
    STORYTELLING, // Skill on telling stories
    POETRY, // Skill on writing and reciting poems
    ACROBACY, // Duh
    ANIMAL_HANDLING, // Skill with horses and other animals
};

enum STATS { // Temporarily ripping off D&D until I think of something better
    STR, // Strength
    CON, // Constitution
    DEX, // Dexterity
    WIS, // Wisdom
    CHA, // Charisma
    INT, // Intelligence
    CSS // Common sense
};

enum GENDERS {
	MALE,
	FEMALE
};
class Player {
    
public:
    Player();
    void printInfo();
    void loadExpTable();
    void saveExpTable();
    void loadPlayerData();
    std::string getName() { return name; } 
    void setName(std::string _name) { name = _name; }
	void generateExpTable();
    unsigned int getLevel() { return level; }
    void setLevel(int _level) { level = _level; }
	void setGender(GENDERS _gender) { gender = _gender; }
	GENDERS getGender() { return gender; }
    std::vector<unsigned int>  getStats() { return stats; }
    void setStats(std::vector<unsigned> _stats) { 
        if ( _stats.size() == 7 ) stats = _stats;
    }
    std::string getBackstory() { return backstory; }
    void setBackstory(std::string _backstory) { backstory = _backstory; }
    std::string getAppearanceDescription() { return appearanceDescription; }
    void setAppearanceDescription(std::string _appearance) { appearanceDescription = _appearance; }
    std::vector<unsigned int> & getProficiencies() { return proficiencies; }
    void setProficiencies(std::vector<unsigned> _proficiencies) { if (_proficiencies.size() == 57) proficiencies = _proficiencies; }
    unsigned getGoldCoins() { return goldCoins; }
    void setGoldCoins(unsigned _goldCoins) { goldCoins = _goldCoins; }
    unsigned int getExperiencePoints() { return experiencePoints; }
	unsigned long long int calculateExpToLevel(unsigned int targetLevel);
	void saveInfo();
    /*****************************************************************************************************************************/
    std::string listProficiencies();
    std::string listStats();
    std::map<unsigned, unsigned long long int> getExpTable() { return expTable; }
    ///////////////////////////////////////////////////////////////////////////////
    void receiveDamage(unsigned base_damage);
    void saveProficiencies();
    void saveStats();
    void createDatabases();
	
private:
    std::string name;
    std::string backstory; // temporary, simple solution
    std::string appearanceDescription; // temporary, simple solution
    unsigned int level;
    unsigned int experiencePoints;
    unsigned int hitpoints;
    unsigned int magicPoints;
    unsigned long int goldCoins;
	GENDERS gender;
    ///////////////////////////////////////////////////
    std::vector<unsigned int> proficiencies; 
    std::vector<unsigned int> stats;
    std::map<unsigned, unsigned long long> expTable; // turns out it's a better idea than sqlite
    
};
