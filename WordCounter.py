def word_counter():
    print("Welcome to the Word Counter program!")

    while True:
        sentence = input("Enter a sentence (or 'exit' to quit): ")

        if sentence.lower() == "exit":
            print("Goodbye! Thanks for using the Word Counter program.")
            break

        words = sentence.split()
        word_count = len(words)
        print(f"Word Count: {word_count}")

if __name__ == "__main__":
    word_counter()
