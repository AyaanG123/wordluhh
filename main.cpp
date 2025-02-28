#include <iostream>
#include <string>
#include <random>

using namespace std;

int main() {
    char replay;

    do {
        string wordList[7] = {"gyatt", "rizzz", "skibi", "ayaan", "shane", "sigma", "goons"}; // Word list
        string guesses[6]; // Stores user guesses
        char feedback[6][6]; // 2D array for feedback strings
        string guess;
        int g = 0;
        char start;

        // Random word selection
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(0, 6);
        string correctWord = wordList[dis(gen)];

        // Instructions
        cout << "Welcome to Worduhl!!!!" << endl;
        cout << "The instructions are: " << endl;
        cout << "Type in a 5-letter word." << endl;
        cout << "Letters with a 'Y' are in the word but in the wrong spot." << endl;
        cout << "Letters with a 'G' are in the word and in the correct spot." << endl;
        cout << "You get 6 guesses to find the correct word. Good luck!" << endl;
        cout << "Press 'e' to start" << endl;
        cin >> start;

        if (start == 'e' || start == 'E') {
            system("clear");

            for (int i = 0; i < 6; i++) { // 6 attempts
                // Display past attempts
                for (int j = 0; j < i; j++) {
                    cout << feedback[j] << endl;
                }

                cout << "Enter your guess: ";
                cin >> guess;

                // Validate guess length
                if (guess.length() != 5) {
                    cout << "Your guess must be 5 letters long!" << endl;
                    return 0;
                }

                guesses[i] = guess; // Store guess

                // Generate feedback for current guess
                char tempFeedback[6] = "XXXXX"; // Reset feedback for this round

                for (int k = 0; k < 5; ++k) {
                    if (guess[k] == correctWord[k]) {
                        tempFeedback[k] = 'G'; // Correct position
                    } else if (correctWord.find(guess[k]) != string::npos) {
                        tempFeedback[k] = 'Y'; // Correct letter, wrong position
                    }
                }

                // Store feedback in the 2D array
                for (int l = 0; l < 5; l++) {
                    feedback[i][l] = tempFeedback[l];
                }
                feedback[i][5] = '\0'; // Null-terminate the string

                system("clear");

                // Check if guess is correct
                if (guess == correctWord) {
                    for (int j = 0; j <= i; j++) {
                        cout << feedback[j] << endl; // Show final result
                    }
                    cout << "Correct! You guessed the word in " << g + 1 << " guesses." << endl;
                    break;
                }
            }

            cout << "Your tries are up, buddy. The correct word was: " << correctWord << endl;

        } else {
            cout << "Invalid Option" << endl;
            return 0;
        }

        cout << "Do you want to play again? (y/n): ";
        cin >> replay;
        system("clear");

    } while (replay == 'y' || replay == 'Y');

    return 0;
}
