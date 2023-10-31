import nltk
from nltk.chat.util import Chat, reflections

# Define patterns for the chatbot
pairs = [
    [
        r"my name is (.*)",
        ["Hello %1, how can I help you today?",]
    ],
    [
        r"what is your name?",
        ["I am a chatbot created with NLTK.",]
    ],
    [
        r"how are you?",
        ["I'm doing good, thank you!",]
    ],
    [
        r"what can you do?",
        ["I can answer simple questions. Try asking me something.",]
    ],
    [
        r"quit",
        ["Goodbye!", "It was nice talking to you. Goodbye!"]
    ],
]

# Create the chatbot
def chatbot():
    print("Hi, I'm your chatbot. You can ask me anything. Type 'quit' to exit.")
    chat = Chat(pairs, reflections)
    chat.converse()

if __name__ == "__main__":
    nltk.download('punkt')
    nltk.download('averaged_perceptron_tagger')
    nltk.download('vader_lexicon')
    chatbot()
