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
    player p;

    clearScreen();
    cout << "This is a prototype of the TEXTVENTURE.\nThis DEMO is not representative of the final product\n" << endl;
    cout << "Actually, TEXTVENTURE might not even be the final name of the bloody thing.\nThe source code of this is just for demonstration too and will most likely not be even used." << endl;
    cout << "\n\nPress any key to procceed (as long as it is enter)...?!" << endl;
    getchar();
    clearScreen();
    
    cout << "Before we get into the actual \"gameplay\", let me talk about some of the features\nthat must be included in this project." << endl;
    cout << "The game will include COMPLEX CHARACTER CUSTOMIZATION. A wide variety of attributes and skills,\nas well as a history background which WILL affect gameplay." << endl;
    cout << "Randomly generated worlds, dungeons, contexts and even story. Each playthrough will be unique and the possibilities for epic stories being born are many." << endl;
    cout << "The idea of this project is to be more than just a game, but a EPIC STORY GENERATOR.\nYou might just wanna chill out and play an RPG and end out with the next Lord of the Rings." << endl;
    cout << "Of course the game will include persistency, something that most oldschool text adventures didn't even dream on having.\nTHIS IS A MODERN TEXT ADVENTURE WITH 2016 TECHNOLOGY." << endl;
    cout << "This is not a DOS game. This will run on the most powerful operating systems ever. It will also run on Windows too." << endl;
    cout << "I'm coding this as I listen to Final Fantasy VI soundtrack. The result can only be epic." << endl;
    cout << "This project has many influences from other games such as:\nRogue (and other roguelikes)\nFinal Fantasy\nPokémon\nThe Elder Scrolls\nDwarf Fortress\n\nand of course, from all the oldschool DOS text games." << endl;
    cout << "\n\nPress any key to procceed (as long as it's enter)...?!" << endl;
    getchar();
    clearScreen();

    cout << "Greetings, adventurer. What is thy name?" << endl;
    cin >> p.name;
    cout << "Very well. Thy name is " << p.name << "." << endl;

    while (true) {
        cout << p.name << ", art thou a human? Or a dwarf?" << endl;
        std::string race;
        cin >>  race;
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
            cout << "As a human, born in the mighty Empire of the Clouds, the imposing country in the skies, is " << p.name << "a peasant? Or is he a nobleman?" << endl;
            cin >> backg;
            toUpperCase(backg);
            if (backg.compare("PEASANT") == 0) {
                p.bg = H_PEASANT;
                cout << "As you wish. " << p.name << " is a commoner, born in a humble place, with no noble origins at all." << endl;
                break;
            } else if (backg.compare("NOBLEMAN") == 0) {
                p.bg = H_NOBLE;
                cout << "As you wish. " << p.name << " is a nobleman, born in the rich castles of the Empire capital. Of noble origin, your bloodline is one of kings and conquerors." << endl;
                break;
            } else {
                cout << "Invalid input." << endl;
            }
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
    }
        
}
