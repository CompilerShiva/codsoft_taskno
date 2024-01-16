#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    // Seed the random number generator with the current time
    srand(static_cast<unsigned int>(time(0)));

    // Generate a random number between 1 and 100
    int secretNumber = rand() % 100 + 1;

    int userGuess;
    int attempts = 0;

    std::cout << "Welcome to the Number Guessing Game!\n";
    std::cout << "Guess the number between 1 and 100\n";

    do {
        // Ask the user to guess the number
        std::cout << "Enter your guess: ";
        std::cin >> userGuess;

        // Increment the attempts counter
        attempts++;

        // Provide feedback on the guess
        if (userGuess < secretNumber) {
            std::cout << "Too low! Try again.\n";
        } else if (userGuess > secretNumber) {
            std::cout << "Too high! Try again.\n";
        } else {
            std::cout << "Congratulations! You guessed the correct number in " << attempts << " attempts.\n";
        }

    } while (userGuess != secretNumber);

    return 0;
}
