#include "HangmanGame.h"
#include <iostream>
#include <algorithm>
#include <cctype>

HangmanGame::HangmanGame(const std::string& secretWord)
    : secretWord(secretWord), wrongGuesses(0) {
}

void HangmanGame::displayWord() const {
    for (char c : secretWord) {
        bool found = std::find(guessedLetters.begin(), guessedLetters.end(), c) != guessedLetters.end();
        std::cout << (found ? c : '_') << ' ';
    }
    std::cout << '\n';
}

bool HangmanGame::isWordGuessed() const {
    for (char c : secretWord) {
        bool found = std::find(guessedLetters.begin(), guessedLetters.end(), c) != guessedLetters.end();
        if (!found) {
            return false;
        }
    }
    return true;
}

char HangmanGame::getPlayerGuess() const {
    std::string input;
    while (true) {
        std::cout << "Unesi slovo: ";
        std::cin >> input;

        if (input.length() != 1) {
            std::cout << "Molim unesi tacno jedno slovo.\n";
            continue;
        }

        char guess = std::tolower(static_cast<unsigned char>(input[0]));

        if (!std::isalpha(static_cast<unsigned char>(guess))) {
            std::cout << "Molim unesi samo slovo.\n";
            continue;
        }

        bool alreadyGuessed = std::find(guessedLetters.begin(), guessedLetters.end(), guess) != guessedLetters.end();
        if (alreadyGuessed) {
            std::cout << "To slovo si vec probao/la.\n";
            continue;
        }

        return guess;
    }
}

void HangmanGame::displayHangman() const {
    static const std::vector<std::string> stages = {
        "  +---+\n  |   |\n      |\n      |\n      |\n      |\n=========",
        "  +---+\n  |   |\n  O   |\n      |\n      |\n      |\n=========",
        "  +---+\n  |   |\n  O   |\n  |   |\n      |\n      |\n=========",
        "  +---+\n  |   |\n  O   |\n /|   |\n      |\n      |\n=========",
        "  +---+\n  |   |\n  O   |\n /|\\  |\n      |\n      |\n=========",
        "  +---+\n  |   |\n  O   |\n /|\\  |\n /    |\n      |\n=========",
        "  +---+\n  |   |\n  O   |\n /|\\  |\n / \\  |\n      |\n========="
    };

    int index = std::min(wrongGuesses, static_cast<int>(stages.size()) - 1);
    std::cout << stages[index] << "\n";
}

bool HangmanGame::play() {
    std::cout << "\n=== HANGMAN ===\n";
    std::cout << "Pogodi rec! Imas " << MAX_WRONG_GUESSES << " pogresnih pokusaja.\n";

    while (wrongGuesses < MAX_WRONG_GUESSES && !isWordGuessed()) {
        std::cout << "\n";
        displayHangman();
        std::cout << "Rec: ";
        displayWord();
        std::cout << "Pogresni pokusaji: " << wrongGuesses << " / " << MAX_WRONG_GUESSES << "\n";

        char guess = getPlayerGuess();
        guessedLetters.push_back(guess);

        if (secretWord.find(guess) != std::string::npos) {
            std::cout << "Tacno!\n";
        } else {
            wrongGuesses++;
            std::cout << "Netacno!\n";
        }
    }

    bool won = isWordGuessed();

    std::cout << "\n";
    if (won) {
        std::cout << "Cestitam, pogodio/la si rec: " << secretWord << "\n";
    } else {
        displayHangman();
        std::cout << "Izgubio/la si. Tacna rec je bila: " << secretWord << "\n";
    }

    return won;
}