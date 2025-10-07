#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cctype>

using namespace std;

const int MAX_WORDS = 1000;
const int MAX_WORD_LEN = 100;

#ifdef _WIN32
#include <windows.h>
void clearScreen() {
    system("cls");
}
#else
#include <unistd.h>
void clearScreen() {
    system("clear");
}
#endif

int readWords(const char* filename, char words[][MAX_WORD_LEN]) {
    ifstream file(filename);
    if (!file.is_open()) {
        return -1;
    }
    int count = 0;
    while (count < MAX_WORDS && file.getline(words[count], MAX_WORD_LEN)) {
        // Convert word to uppercase for consistent comparison
        for (int i = 0; words[count][i]; ++i) {
            words[count][i] = toupper(words[count][i]);
        }
        count++;
    }
    file.close();
    return count;
}

void displayHangman(int mistakes) {
    cout << "  +---+" << endl;
    cout << "  |   |" << endl;

    switch (mistakes) {
    case 0:
        cout << "      |" << endl;
        cout << "      |" << endl;
        cout << "      |" << endl;
        break;
    case 1:
        cout << "  O   |" << endl;
        cout << "      |" << endl;
        cout << "      |" << endl;
        break;
    case 2:
        cout << "  O   |" << endl;
        cout << "  |   |" << endl;
        cout << "      |" << endl;
        break;
    case 3:
        cout << "  O   |" << endl;
        cout << " /|   |" << endl;
        cout << "      |" << endl;
        break;
    case 4:
        cout << "  O   |" << endl;
        cout << " /|\\  |" << endl;
        cout << "      |" << endl;
        break;
    case 5:
        cout << "  O   |" << endl;
        cout << " /|\\  |" << endl;
        cout << " /    |" << endl;
        break;
    case 6:
        cout << "  O   |" << endl;
        cout << " /|\\  |" << endl;
        cout << " / \\  |" << endl;
        break;
    case 7:
        cout << "  O   |" << endl;
        cout << " /|\\  |" << endl;
        cout << " / \\  |" << endl;
        break;
    }
    cout << "      |" << endl;
    cout << "=========" << endl;
}

int main() {
    const char* filename = "words.txt";
    char words[MAX_WORDS][MAX_WORD_LEN];
    int wordCount = readWords(filename, words);
    if (wordCount <= 0) {
        cerr << "Error: Could not read words from file 'words.txt'." << endl;
        cerr << "Please make sure the file exists in the same directory." << endl;
        return 1;
    }

    srand(static_cast<unsigned int>(time(nullptr)));
    int randomIndex = rand() % wordCount;
    char* targetWord = words[randomIndex];
    int wordLen = strlen(targetWord);

    char currentState[MAX_WORD_LEN];
    for (int i = 0; i < wordLen; ++i) {
        currentState[i] = '_';
    }
    currentState[wordLen] = '\0';

    const int maxMistakes = 7;
    int mistakes = 0;
    bool won = false;
    char guessedLetters[26] = { 0 };
    int guessedCount = 0;

    while (mistakes < maxMistakes && !won) {
        clearScreen();

        // Display header
        cout << "=========================================" << endl;
        cout << "              HANGMAN GAME" << endl;
        cout << "=========================================" << endl;
        cout << endl;

        // Display hangman
        displayHangman(mistakes);
        cout << endl;

        // Display current word state
        cout << "Word: ";
        for (int i = 0; i < wordLen; ++i) {
            cout << currentState[i] << " ";
        }
        cout << endl << endl;

        // Display remaining mistakes
        cout << "Mistakes remaining: " << (maxMistakes - mistakes) << endl;

        // Display guessed letters
        if (guessedCount > 0) {
            cout << "Guessed letters: ";
            for (int i = 0; i < guessedCount; ++i) {
                cout << guessedLetters[i] << " ";
            }
            cout << endl;
        }
        cout << endl;

        // Get player's guess
        cout << "Enter your guess (a single letter): ";
        char guess;
        cin >> guess;

        // Convert to uppercase
        if (guess >= 'a' && guess <= 'z') {
            guess = guess - 'a' + 'A';
        }

        // Validate input
        if (guess < 'A' || guess > 'Z') {
            cout << "Invalid input! Please enter a letter from A-Z." << endl;
            cout << "Press Enter to continue...";
            cin.ignore();
            cin.get();
            continue;
        }

        // Check if already guessed
        bool alreadyGuessed = false;
        for (int i = 0; i < guessedCount; ++i) {
            if (guessedLetters[i] == guess) {
                alreadyGuessed = true;
                break;
            }
        }

        if (alreadyGuessed) {
            cout << "You already guessed '" << guess << "'! Try a different letter." << endl;
            cout << "Press Enter to continue...";
            cin.ignore();
            cin.get();
            continue;
        }

        // Add to guessed letters
        guessedLetters[guessedCount++] = guess;

        // Check if guess is correct
        bool correctGuess = false;
        for (int i = 0; i < wordLen; ++i) {
            if (targetWord[i] == guess) {
                currentState[i] = guess;
                correctGuess = true;
            }
        }

        if (!correctGuess) {
            mistakes++;
            cout << "Incorrect! '" << guess << "' is not in the word." << endl;
        }
        else {
            cout << "Good guess! '" << guess << "' is in the word." << endl;
        }

        cout << "Press Enter to continue...";
        cin.ignore();
        cin.get();

        // Check if player has won
        won = true;
        for (int i = 0; i < wordLen; ++i) {
            if (currentState[i] == '_') {
                won = false;
                break;
            }
        }
    }

    clearScreen();
    cout << "=========================================" << endl;
    cout << "              GAME OVER" << endl;
    cout << "=========================================" << endl;
    cout << endl;

    displayHangman(mistakes);
    cout << endl;
    cout << "The word was: " << targetWord << endl;
    cout << endl;

    if (won) {
        cout << "Congratulations! You won! " << endl;
        cout << "You guessed the word with " << mistakes << " mistake(s)." << endl;
    }
    else {
        cout << " Game over! You lost." << endl;
        cout << "Better luck next time!" << endl;
    }

    cout << endl;
    cout << "Thank you for playing Hangman!" << endl;

    return 0;
}