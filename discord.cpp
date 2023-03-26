#include <iostream>
#include <cmath>
#include <string>

using namespace std;

// Global Variables
int score = 0;

// Function Declarations
void intro();
int jump();
int duck();
void gameover();

// Function Definitions
int main()
{
    intro();
    while (score < 5)
    {
        int choice = 0;
        cout << "jump or duck? ";
        cin >> choice;
        if (choice == 1)
        {
            score += jump();
        }
        else if (choice == 2)
        {
            score += duck();
        }
    }
    gameover();
    return 0;
}

void intro()
{
    cout << "Welcome to the Dinosaur Game!" << endl;
    cout << "Jump over the cacti and duck under the pterodactyls!" << endl;
    cout << "Earn 5 points to win!" << endl;
    cout << "Good luck!" << endl << endl;
}

int jump()
{
    int num = rand() % 5 + 1;
    if (num == 3)
    {
        cout << "You jumped too high and got hit by a pterodactyl!" << endl;
        return -1;
    }
    else
    {
        cout << "You jumped over a cactus!" << endl;
        return 1;
    }
}

int duck()
{
    int num = rand() % 5 + 1;
    if (num == 3)
    {
        cout << "You ducked too low and got hit by a cactus!" << endl;
        return -1;
    }
    else
    {
        cout << "You ducked under a pterodactyl!" << endl;
        return 1;
    }
}

void gameover()
{
    cout << "Congratulations! You won the game!" << endl;
    cout << "Your final score is: " << score << endl;
}