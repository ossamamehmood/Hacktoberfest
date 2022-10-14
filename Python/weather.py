import requests


def get_weather(city: str):
    # Enter your API key here
    api_key = "Your_API_Key"
    url = "https://api.openweathermap.org/data/2.5/weather?q=" + \
        city + "&appid=" + api_key + "&units=metric"

    response = requests.get(url).json()

    if response["cod"] == "404":
        print('City not found.')
    else:
        weather = response["main"]
        description = response["weather"][0]["description"]
        print("Location: " + city.capitalize())
        print(description.capitalize())
        print("Temperature: " + str(weather["temp"]) + " C" + "\u00B0")
        print("Feel like: " + str(weather["feels_like"]) + " C" + "\u00B0")
        print("Humidity: " + str(weather["humidity"]) + " %")


city = input("Enter your city: ")
get_weather(city)
