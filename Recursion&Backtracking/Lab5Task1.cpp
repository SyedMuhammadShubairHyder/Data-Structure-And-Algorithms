/*
Assume you are developing a program to simulate a game where players take turns to guess a
number between 1 and 100. The program generates a random number between 1 and 100 at
the start of the game, and the player who guesses the correct number wins the game. If a player
guesses incorrectly, the program tells them whether their guess was too high or too low, and
the turn passes to the next player. Solve it using Direct Recursion?
*/
#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
using namespace std;

void playGame(int secretNumber, int currentPlayer)
{
    int guess;

    cout << "Player " << currentPlayer << ", enter your guess: ";
    cin >> guess;

    if (guess == secretNumber)
    {
        cout << "Congratulations! Player " << currentPlayer << " wins! The correct number was " << secretNumber << "." << endl;
        return;
    }

    if (guess < secretNumber)
    {
        cout << "Too low!" << endl;
    }
    else
    {
        cout << "Too high!" << endl;
    }

    playGame(secretNumber, (currentPlayer % 2) + 1);
}

int main()
{
    // time library net se dekhi
    srand(static_cast<unsigned int>(time(0)));
    int secretNumber = rand() % 100 + 1;

    cout << "Welcome to the Number Guessing Game!" << endl;

    cout << "Two players will take turns to guess a number between 1 and 100." << endl;

    playGame(secretNumber, 1);

    return 0;
}
