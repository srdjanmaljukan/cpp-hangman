#pragma once

#include <string>
#include <vector>

class HangmanGame {
public:
    static const int MAX_WRONG_GUESSES = 6;

    // Konstruise igru sa zadatom tajnom recju
    explicit HangmanGame(const std::string& secretWord);

    // Odigrava celu rundu (interaktivno, preko konzole); vraca true ako je igrac pobedio
    bool play();

private:
    std::string secretWord;
    std::vector<char> guessedLetters;
    int wrongGuesses;

    void displayWord() const;
    void displayHangman() const;
    bool isWordGuessed() const;
    char getPlayerGuess() const;
};