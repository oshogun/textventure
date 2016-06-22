#include "Player.h"

Player::Player(): level(1), experiencePoints(0), goldCoins(100), proficiencies(57,5), stats(6,5)
{
    name = "Test Dude";
    backstory = "This dude was created for testing purposes.\n";
    appearance_description = "He looks like a bunch of pixels\n";
}

void Player::printStats() 
{
    std::cout << name << "\n" << backstory << appearance_description << level << "\n";
    std::cout << experiencePoints << "\n" << goldCoins << "\n";
    for (auto i: proficiencies) {
        std::cout << proficiencies[i] << " ";
    }
    std::cout << "\n";

}
//temporary for test
int main()
{
    Player p;
    p.printStats();    
}
