# Hangman (C++ Console Game)

A classic console-based Hangman game written in C++. The player tries to guess a hidden word letter by letter before running out of attempts.

## Features
- Word guessing with letter-by-letter input
- ASCII hangman drawing that progresses with wrong guesses
- Word list loaded from an external file (`words.txt`)
- Replay option and basic session statistics

## Requirements
- A C++ compiler (g++ / MinGW / MSVC)
- No external libraries required

## How to Build

```bash
g++ -std=c++17 -o hangman src/main.cpp
```

## How to Run

```bash
./hangman
```

## Project Structure