#include <iostream>
#include <string>
#include <locale>
#include <cstdlib>
#include <cstdio>
#include <sstream>

using std::cout;
using std::endl;
using std::cin;

enum RACES { HUMAN, ELF, ORC, DWARF };
enum BACKGROUNDS { H_PEASANT, H_NOBLE, D_WARRIOR, D_HUNTER };

typedef struct {
    std::string name;
    RACES race;
    BACKGROUNDS bg;
	std::string appearance;
}player;


void clearScreen()
{
    #ifdef __linux__
    system("clear");
    #elif __unix__
    system("clear");
    #elif __WIN32
    system("cls");
    #elif __WIN64
    system("cls");
    #endif

}

void toUpperCase(std::string &str) {
    std::string upper;
    std::stringstream ss;
    std::locale loc;
    for (std::string::size_type i = 0; i < str.length(); ++i) {
        ss << std::toupper(str[i],loc);
    }
    ss >> upper;
    str = upper;
}
int main() 
{
	clearScreen();
	#ifdef __WIN32
	cout << "Using Windows? Well, we support your crappy OS, but consider giving good old Unix a try ;-)" << endl;
	cout << "TextVenture for Win32 PROTOTYPE" << endl;
	system("COLOR C");
	#elif __WIN64
	cout << "Using Windows? Well, we support your crappy OS, but consider giving good old Unix a try ;-)" << endl;
	cout << "TextVenture for Win64 PROTOTYPE" << endl;
	system("COLOR B");
	#elif __linux__
	cout << "TextVenture for Linux PROTOTYPE" << endl;
	#endif
    player p;

    cout << "========================================================" << endl;
    cout << "This is a prototype of the TEXTVENTURE.\nThis DEMO is not representative of the final product\n" << endl;
    cout << "Actually, TEXTVENTURE might not even be the final name of the bloody thing.\nThe source code of this is just for demonstration too and will most likely not be even used." << endl;
    cout << "\n\nPress any key to procceed (as long as it is enter)...?!" << endl;
	cout << "========================================================" << endl;
    getchar();
    clearScreen();
    
    cout << "Before we get into the actual \"gameplay\", let me talk about some of the features\nthat must be included in this project." << endl;
    cout << "The game will include COMPLEX CHARACTER CUSTOMIZATION.\nA wide variety of attributes and skills,\nas well as a history background which WILL affect gameplay." << endl;
    cout << "Randomly generated worlds, dungeons, contexts\nand even story.Each playthrough will be unique and\nthe possibilities for epic stories being born are many." << endl;
    cout << "The idea of this project is to be more than just a game\n, but a EPIC STORY GENERATOR.\nYou might just wanna chill out and play an RPG\nand end out with the next Lord of the Rings." << endl;
    cout << "Of course the game will include persistency, something that most oldschool text adventures didn't even dream on having.\nTHIS IS A MODERN TEXT ADVENTURE WITH 2016 TECHNOLOGY." << endl;
    cout << "This is not a DOS game. This will run on the most powerful operating systems ever. It will also run on Windows too." << endl;
    cout << "I'm coding this as I listen to Final Fantasy VI soundtrack. The result can only be epic." << endl << endl;
    cout << "This project has many influences from other games such as:\n\nRogue (and other roguelikes)\nFinal Fantasy\nPokemon\nThe Elder Scrolls\nDwarf Fortress\nAnd of course, from all the oldschool DOS text games." << endl;
    cout << "\n\nPress any key to procceed (as long as it's enter)...?!" << endl;
    getchar();
    clearScreen();

    cout << "Greetings, adventurer. What is thy name?" << endl;
    cin.sync();
	getline(cin, p.name);
	
    cout << "Very well. Thy name is " << p.name << "." << endl;

    while (true) {
        cout << p.name << ", art thou a human? Or a dwarf?" << endl;
        std::string race;
		cin.sync();
        getline(cin,race);
        toUpperCase(race);
        if (race.compare("HUMAN") == 0) {
            p.race = HUMAN;
            cout << "Very well. " << p.name << " is a proud human." << endl;
            break;
        } else if (race.compare("DWARF") == 0) {
            p.race = DWARF;
            cout << "Very well. " << p.name << " is a mighty dwarf." << endl;
            break;
        } else {
            cout << "Invalid input." << endl;
        }
    }
    if (p.race == HUMAN) {
        std::string backg;
        while (true) {
            cout << "As a human, born in the mighty Empire of the Clouds,\nthe imposing country in the skies,is " << p.name << " a peasant?\nOr is he a nobleman?" << endl;
            cin.sync();
			getline(cin,backg);
            toUpperCase(backg);
            if (backg.compare("PEASANT") == 0) {
                p.bg = H_PEASANT;
                cout << "As you wish. " << p.name << " is a commoner, born in a humble place, with no noble origins at all." << endl;
                break;
            } else if (backg.compare("NOBLEMAN") == 0) {
                p.bg = H_NOBLE;
                cout << "As you wish. " << p.name << " is a nobleman, born in the rich castles of the Empire capital.\nOf noble origin, your bloodline is one of kings and conquerors." << endl;
                break;
            } else {
                cout << "Invalid input." << endl;
            }
			
		}
			std::string app1 = "Long, brown hair. Deep, black eyes. A scar in the chin.\n A muscular build. Medium height. Thick eyebrows. Angular chin.\n\n";
			std::string app2 = "Bald. A blonde, long beard. A left blue eye, a blind right eye.\n A huge scar near the right eye. Thin eyebrows. A square chin.\n\n";
			std::string app3 = "Short, black hair. Brown eyes. No scars. A square chin. An elegant moustache.";
			
			cout << "As for your appearance, please choose one of the following options." << endl;
			cout << "===================================================================" << endl;
			cout << "1. " << app1 << endl;
			cout << "2. " << app2 << endl;
			cout << "3. " << app3 << endl;
			int choice;
			cin >> choice;
			switch (choice) {
				case 1:
					p.appearance = app1;
					cout << "Very well. " << p.name << " has " << app1 << endl;
					break;
				case 2:
					p.appearance = app2;
					cout << "Very well. " << p.name << " is " << app2 << endl;
					break;
				case 3:
					p.appearance = app3;
					cout << "Very well. " << p.name << " has " << app3 << endl;
					break;
				default:
					p.appearance = "A completely generic look.";
					cout << "Lol. I'm pretty sure that choice wasn't on the menu so..." << endl;
					cout << p.name << " has " << p.appearance << endl;
			}

    } else {
        std::string backg;
        while (true) {
            cout << "As a mighty dwarf from the cold mountains of the north, is " << p.name << " descendant of a powerful warrior or of a smart hunter?" << endl;
            cin >> backg;
            toUpperCase(backg);
            if (backg.compare("WARRIOR") == 0) {
                p.bg == D_WARRIOR;
                cout << "As you wish. " << p.name << " descends from Skolodor, mighty dwarf hero who brandished his axe against all evil." << endl;
                break;
            } else if (backg.compare("HUNTER") == 0) {
                p.bg == D_HUNTER;
                cout << "As you wish. " << p.name << " descends from Argenor, legendary dwarf hunter who used gunpowder to slay monstruous beasts." << endl;
                break;
            } else {
                cout << "Invalid output." << endl;
            }
        }
			std::string app1 = "Gray hair\nPurple eyes\nBronze skin\n67cm of amazing beard\n\n";
			std::string app2 = "Bald\nShort beard\nYellow eyes\nBlue skin\nNo nose (Characteristic of the dwarves of the north)\n\n";
			std::string app3 = "Pink hair\nRed eyes\nPink skin\nTwo noses (Characteristic of the dwarves of the south)\n\n";
			
			cout << "As for your appearance, please choose one of the following options." << endl;
			cout << "===================================================================" << endl;
			cout << "1. " << app1 << endl;
			cout << "2. " << app2 << endl;
			cout << "3. " << app3 << endl;
			int choice;
			cin >> choice;
			switch (choice) {
				case 1:
					p.appearance = app1;
					cout << "Very well. " << p.name << " has " << app1 << endl;
					break;
				case 2:
					p.appearance = app2;
					cout << "Very well. " << p.name << " is " << app2 << endl;
					break;
				case 3:
					p.appearance = app3;
					cout << "Very well. " << p.name << " has " << app3 << endl;
					break;
				default:
					p.appearance = "A completely generic look.";
					cout << "Lol. I'm pretty sure that choice wasn't on the menu so..." << endl;
					cout << p.name << " has " << p.appearance << endl;
			}
    }
    while(true){
        clearScreen();
        cout << "Very well. You have created your character. Display character info? (Y/N)" << endl;
        std::string choice;
        cin >> choice;
        toUpperCase(choice);
        if (choice == "Y") {
            cout << "Name: " << p.name << endl;
            switch (p.bg) {
                case D_HUNTER:
                    cout << "Dwarf, descendant of hunters" << endl;
                    break;
                case D_WARRIOR:
                    cout << "Dwarf, descendant of warriors" << endl;
                    break;
                case H_PEASANT:
                    cout << "Human peasant" << endl;
                    break;
                case H_NOBLE:
                    cout << "Human noble" << endl;
                    break;
                default:
                    break;
                    break;
            }
            cout << p.appearance << endl;
			getchar();
			break;
        } else if (choice == "N") {
            break;
        } else {
            cout << "Invalid choice" << endl;
        }
		 
    }
	cout << "Press enter to continue" << endl;
	getchar();
	clearScreen();
    cout << "You wake up in a dark, unfamiliar room. A young lady is sitting in a chair near your bed." << endl;
    cout << "You are hurt in the chest, yet, bandaged. The lady looks at you, apparently relieved by your awakening." << endl;
    while(true) {
        cout << "What will " << p.name << " do?" << endl;
        cout << "TALK to girl" << endl;
        cout << "ATTACK girl" << endl;
        cout << "EXAMINE girl" << endl;
        cout << "IGNORE girl" << endl;
        std::string choice;
        cin >> choice;
        toUpperCase(choice);
        if (choice == "TALK") {
            cout << "GIRL: \"You are finally awake! I was worried it was too late for you...\"" << endl;
            cout << "What will you say?" << endl;
            cout << "1. Where am I?" << endl;
            cout << "2. What happened to me?" << endl;
            cout << "3. Why hello there! (FLIRT)" << endl;
            int say;
            cin >> say;
            switch (say) {
                case 1:
                    cout << "GIRL: \"In my dungeon. Please do not fear, as I do not intend on causing you harm.\"" << endl;
                    cout << "GIRL: \"I am Gibraltharis, the banished queen of the mountains of Skanathar.\"" << endl;
                    cout << "Gibraltharis: \"I found you unconscious, struck by sinister magic, near my realms.\"" << endl;
                    cout << "Gibraltharis: \"Usually I woudln't bother but... I feel a strong power on you...\"" << endl;
                    break;
                case 2:
                    cout << "GIRL:\"You were struck by sinister magic, causing a wound that could not be healed by normal people\"" << endl;
                    cout << "GIRL: \"I am Gibraltharis, the banished queen of the mountains of Skanathar.\"" << endl;
                    cout << "Gibraltharis: \"I used my forbidden magic to heal your wounds.\"" << endl;
                    cout << "Gibraltharis: \"I apologize for having to recur to such means, but I could not let you just die there.\"" << endl;
                    cout << "Gibraltharis: \"Usually I woudln't bother but... I feel a strong power on you...\"" << endl;
                    break;
                case 3:
                    cout << "GIRL:\"You are really straightforward, aren't you?" << endl;
                    cout << "GIRL: \"I am Gibraltharis, the banished queen of the mountains of Skanathar.\"" << endl;
                    cout << "Gibraltharis: \"I found you unconscious, struck by sinister magic, near my realms.\"" << endl;
                    cout << "Gibraltharis: \"I used my forbidden magic to heal your wounds.\"" << endl;
                    cout << "Gibraltharis: \"I apologize for having to recur to such means, but I could not let you just die there.\"" << endl;
                    cout << "Gibraltharis: \"Usually I woudln't bother but... I feel a strong power on you...\"" << endl;
                    break;
                default:
                    cout <<"GIRL: \"What?, cat got your tongue?\"" << endl;
                    cout << "GIRL: \"I am Gibraltharis, the banished queen of the mountains of Skanathar.\"" << endl;
                    cout << "Gibraltharis: \"I found you unconscious, struck by sinister magic, near my realms.\"" << endl;
                    cout << "Gibraltharis: \"Usually I woudln't bother but... I feel a strong power on you...\"" << endl;
                    break;
            }
            break;
        } else if (choice == "ATTACK") {
            cout << "Without any memories of how you ended up there, your instincts identify the girl as an enemy." << endl;
            cout << "You quickly get up, jumping in the girl's direction with killing intent." << endl;
            cout << "The girl looks at you with a bored look, as she simply\ntouches your chest and you EXPLODE INTO GORE..." << endl;
            cout << "GAME OVER" << endl;
            return 0;
        } else if (choice == "EXAMINE") {
            cout << "You see a silver-haired young elven girl. She has unusually pale skin, is wearing a completely black robe, and her eyes glow a sinister gray." << endl;
            cout << "You can also sense a terribly powerful aura of magic that gives you a chill in the spine..." << endl;
        } else if (choice == "IGNORE") {
            cout << "The girl looks at you paciently. You shouldn't ignore her." << endl;
        } else {
            cout << "Invalid choice. " << endl;
        }
    }
        
}
