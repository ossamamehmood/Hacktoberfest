import requests

API_KEY = "YOUR_API_KEY"  # Replace with your OpenWeatherMap API key
BASE_URL = "http://api.openweathermap.org/data/2.5/weather"

def get_weather(city):
    params = {
        "q": city,
        "appid": API_KEY,
        "units": "metric"
    }
    response = requests.get(BASE_URL, params=params)
    if response.status_code == 200:
        data = response.json()
        main = data["main"]
        weather = data["weather"][0]
        print(f"\nWeather in {city.title()}:")
        print(f"Temperature: {main['temp']}°C")
        print(f"Feels Like: {main['feels_like']}°C")
        print(f"Humidity: {main['humidity']}%")
        print(f"Weather: {weather['main']} - {weather['description']}")
        print(f"Wind Speed: {data['wind']['speed']} m/s")
    else:
        print("City not found or API request failed.")

def main():
    print("=== Weather App ===")
    while True:
        city = input("\nEnter city name (or 'exit' to quit): ").strip()
        if city.lower() == "exit":
            print("Exiting Weather App.")
            break
        get_weather(city)

if __name__ == "__main__":
    main()
