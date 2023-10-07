import random

def choose_random_word():
    word_list = ["apple", "banana", "chocolate", "dolphin", "elephant", "giraffe", "hamburger", "kangaroo", "parrot", "strawberry"]
    return random.choice(word_list)

def hangman():
    print("Welcome to the Hangman game!")
    
    secret_word = choose_random_word()
    guessed_word = ['_'] * len(secret_word)
    attempts = 6

    while attempts > 0:
        print("\nWord:", ' '.join(guessed_word))
        print("Attempts left:", attempts)

        guess = input("Guess a letter or the whole word: ").lower()

        if len(guess) == 1 and guess.isalpha():
            if guess in secret_word:
                for i in range(len(secret_word)):
                    if secret_word[i] == guess:
                        guessed_word[i] = guess
                if '_' not in guessed_word:
                    print("\nCongratulations! You guessed the word:", secret_word)
                    break
            else:
                print("Incorrect guess.")
                attempts -= 1
        elif guess == secret_word:
            print("\nCongratulations! You guessed the word:", secret_word)
            break
        else:
            print("Invalid input. Please guess a single letter or the whole word.")

    if attempts == 0:
        print("\nGame over! The word was:", secret_word)

if __name__ == "__main__":
    hangman()
