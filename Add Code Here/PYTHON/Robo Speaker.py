import pyttsx3

def robo_speaker():
    # Initialize the pyttsx3 engine
    engine = pyttsx3.init()

    # Set properties like rate (speed) and volume if desired
    rate = engine.getProperty('rate')
    engine.setProperty('rate', rate - 25)  # Reduce the rate for clearer speech

    volume = engine.getProperty('volume')
    engine.setProperty('volume', volume + 0.25)  # Increase volume slightly

    # Infinite loop to take user input and speak it
    while True:
        # Get user input
        text = input("Enter what you want me to say (or 'exit' to quit): ")

        # Break the loop if the user wants to exit
        if text.lower() == 'exit':
            print("Exiting Robo Speaker. Goodbye!")
            break

        # Use the TTS engine to say the text
        engine.say(text)
        engine.runAndWait()

if __name__ == "__main__":
    robo_speaker()
