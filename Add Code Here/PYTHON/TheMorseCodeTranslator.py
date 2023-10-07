# Dicionário de tradução de código Morse
morse_code_dict = {
    'A': '.-', 'B': '-...', 'C': '-.-.', 'D': '-..', 'E': '.', 'F': '..-.', 'G': '--.', 'H': '....', 'I': '..', 'J': '.---',
    'K': '-.-', 'L': '.-..', 'M': '--', 'N': '-.', 'O': '---', 'P': '.--.', 'Q': '--.-', 'R': '.-.', 'S': '...', 'T': '-',
    'U': '..-', 'V': '...-', 'W': '.--', 'X': '-..-', 'Y': '-.--', 'Z': '--..',
    '0': '-----', '1': '.----', '2': '..---', '3': '...--', '4': '....-', '5': '.....', '6': '-....', '7': '--...', '8': '---..', '9': '----.',
    ' ': ' '
}

# Função para traduzir texto para código Morse
def text_to_morse(text):
    text = text.upper()
    morse_code = ''
    for char in text:
        if char in morse_code_dict:
            morse_code += morse_code_dict[char] + ' '
    return morse_code

# Função para traduzir código Morse para texto
def morse_to_text(morse_code):
    morse_code = morse_code.split(' ')
    text = ''
    for code in morse_code:
        for char, morse in morse_code_dict.items():
            if code == morse:
                text += char
                break
    return text

def morse_code_translator():
    print("Welcome to the Morse Code Translator program!")

    while True:
        print("\nMenu:")
        print("1. Text to Morse Code")
        print("2. Morse Code to Text")
        print("3. Quit")

        choice = input("Enter your choice (1/2/3): ")

        if choice == "3":
            print("Goodbye! Thanks for using the Morse Code Translator program.")
            break

        if choice == "1":
            text = input("Enter the text to translate to Morse Code: ")
            morse_code = text_to_morse(text)
            print(f"Morse Code: {morse_code}")
        elif choice == "2":
            morse_code = input("Enter the Morse Code to translate to text (use spaces between symbols): ")
            text = morse_to_text(morse_code)
            print(f"Text: {text}")
        else:
            print("Invalid choice. Please choose a valid option (1/2/3).")

if __name__ == "__main__":
    morse_code_translator()
