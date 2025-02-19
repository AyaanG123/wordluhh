#include <iostream>
#include <string>
#include <random>
using namespace std;
int main(){
    string wordList[7] = {"gyatt", "rizzz", "skibi", "ayaan", "shane", "sigma", "goons"};//initializing a list of words to be picked from
    string guesses[6][5];//creates a 2d array with nothing in it 
    string guess;
    string xxxxx = "XXXXX";//base feedback to give the user; changes based on user input
    
    //makes random device
    random_device rd;
    //generates the random number
    mt19937 gen(rd());
    //makes the random number limits
    uniform_int_distribution<> dis(1, 7);
    //assigns the random number to a variable
    int random = dis(gen);
    
    //random word from list
    string correctWord = wordList[random-1];
    
    cout << "Welcome to Worduhl!!!!" << endl;
    cout << "The instructions are: " << endl;
    cout << "Type in a 5 letter word \nLetters with a 'Y' means that they are in the word, but in the wrong spot \nLetters with a 'G' means that they are in the word and in the correct spot." << endl;
    cout << "You get 6 guesses to guess the correct word." << endl;
    cout << "Good Luck!" << endl;
    
    
    for (int i = 0; i < 6; i++) {//gives the user 6 guesses
        cout << "Enter your guess: ";
        cin >> guess;
        if (guess.length() != 5){//checks to see if the word is 5 letters long
            cout << "your so dumb bro..." << endl;
            return 0;
        }
        
        
        
        
     for (int i = 0; i < 5; ++i) {//loops through the whole word
            if (guess[i] == correctWord[i]) {//checks each individual let
                xxxxx[i] = 'G';// changes the string to give feeback
            } else if (correctWord.find(guess[i]) != string::npos) {//checks to see if the correct letter is somewhere else in the word
                xxxxx[i] = 'Y'; 
            }
        }
        
    
    
     cout << xxxxx << endl;//prints feedback after each guess
     
    if(guess == correctWord){//if the guess is equal to the word it prints correct and ends the program
        cout << "Correct!" << endl;
        return 0;
    }
    }
    cout << "Your tries are up buddy. I'm dissapointed"<<endl;
    return 0;
}
