#!/usr/bin/env python3
"""
🔤 Guess the Word Game
A simple word guessing (mini hangman) game in Python.
Author: YourName
License: MIT
"""

import random

WORDS = ["python", "github", "openai", "ubuntu", "docker", "programming", "cloud", "server"]

def choose_word():
    return random.choice(WORDS)

def display_progress(word, guessed_letters):
    return " ".join([letter if letter in guessed_letters else "_" for letter in word])

def play_game():
    print("🎮 Welcome to the Guess the Word Game!\n")
    secret_word = choose_word()
    guessed_letters = set()
    attempts = 6

    while attempts > 0:
        print(f"Word: {display_progress(secret_word, guessed_letters)}")
        print(f"❤️ Attempts left: {attempts}")
        guess = input("👉 Guess a letter: ").lower()

        if not guess.isalpha() or len(guess) != 1:
            print("⚠️ Please enter a single letter.\n")
            continue

        if guess in guessed_letters:
            print("🌀 You already guessed that letter!\n")
            continue

        guessed_letters.add(guess)

        if guess in secret_word:
            print("✅ Correct!\n")
        else:
            print("❌ Wrong guess!\n")
            attempts -= 1

        if all(letter in guessed_letters for letter in secret_word):
            print(f"🎉 You guessed the word! It was '{secret_word}'. 🏆")
            break
    else:
        print(f"💀 Game over! The word was '{secret_word}'.")

if __name__ == "__main__":
    play_game()
