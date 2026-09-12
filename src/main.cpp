#include <iostream>
#include <fstream>
#include <random>
#include <stdexcept>
#include <string>
#include <vector>
#include <cctype>
#include "HangmanGame.h"

// Ucitava listu reci iz fajla, jedna rec po redu
std::vector<std::string> loadWords(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Ne mogu da otvorim fajl: " + filename);
    }

    std::vector<std::string> words;
    std::string line;
    while (std::getline(file, line)) {
        if (!line.empty()) {
            words.push_back(line);
        }
    }

    if (words.empty()) {
        throw std::runtime_error("Fajl sa recima je prazan: " + filename);
    }

    return words;
}

// Bira nasumicnu rec iz liste
std::string pickRandomWord(const std::vector<std::string>& words) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<size_t> dist(0, words.size() - 1);
    return words[dist(gen)];
}

int main() {
    std::vector<std::string> wordList;
    try {
        wordList = loadWords("words.txt");
    } catch (const std::exception& e) {
        std::cerr << "Greska: " << e.what() << "\n";
        return 1;
    }

    int wins = 0;
    int losses = 0;

    while (true) {
        std::string secretWord = pickRandomWord(wordList);
        HangmanGame game(secretWord);
        bool won = game.play();

        if (won) {
            wins++;
        } else {
            losses++;
        }

        std::cout << "\nStatistika ove sesije - Pobede: " << wins << " | Porazi: " << losses << "\n";
        std::cout << "Zelis li da igras ponovo? (d/n): ";

        std::string answer;
        std::cin >> answer;

        char first = std::tolower(static_cast<unsigned char>(answer[0]));
        if (first != 'd') {
            break;
        }
    }

    std::cout << "\nHvala na igri! Ukupno - Pobede: " << wins << " | Porazi: " << losses << "\n";
    return 0;
}