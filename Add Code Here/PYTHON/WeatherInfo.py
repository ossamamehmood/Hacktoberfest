import requests

def get_weather(city):
    api_key = "YOUR_API_KEY"  # Substitua pelo seu próprio API key do OpenWeatherMap
    base_url = "http://api.openweathermap.org/data/2.5/weather?"

    complete_url = f"{base_url}q={city}&appid={api_key}&units=metric"
    response = requests.get(complete_url)

    if response.status_code == 200:
        data = response.json()
        temperature = data["main"]["temp"]
        description = data["weather"][0]["description"]
        print(f"Weather in {city}:")
        print(f"Temperature: {temperature}°C")
        print(f"Description: {description.capitalize()}")
    else:
        print("City not found. Please check the city name or try again later.")

def weather_info():
    print("Welcome to the Weather Info program!")

    while True:
        city = input("Enter the city name (or 'quit' to exit): ").strip()

        if city.lower() == "quit":
            print("Goodbye! Thanks for using the Weather Info program.")
            break

        get_weather(city)

if __name__ == "__main__":
    weather_info()
