import tkinter as tk
import requests
import datetime
import timezone
import tkinter.font as tkFont

# Define a function to convert Fahrenheit to Celsius
def fahrenheit_to_celsius(f):
    return (f - 32) * 5 / 9

# Define a function to get the weather data
def getWeather(canvas):
    city = textField.get()
    api = "https://api.openweathermap.org/data/2.5/weather"
    params = {"q": city, "appid": "06c921750b9a82d8f5d1294e1586276f"}
    
    # Get the response as a dictionary
    json_data = requests.get(api, params=params).json()
    condition = json_data['weather'][0]['main']
    temp = fahrenheit_to_celsius(json_data['main']['temp'])
    min_temp = fahrenheit_to_celsius(json_data['main']['temp_min'])
    max_temp = fahrenheit_to_celsius(json_data['main']['temp_max'])
    pressure = json_data['main']['pressure']
    humidity = json_data['main']['humidity']
    wind = json_data['wind']['speed']
    
    # Get the sunrise and sunset times as datetime objects
    sunrise = datetime.datetime.fromtimestamp(json_data['sys']['sunrise'])
    sunset = datetime.datetime.fromtimestamp(json_data['sys']['sunset'])
    
    # Adjust the time zone according to the user's location
    tz = timezone.timezone(json_data['timezone'])
    sunrise = sunrise.astimezone(tz)
    sunset = sunset.astimezone(tz)
    
    # Format the datetime objects as strings
    sunrise = sunrise.strftime('%I:%M:%S %p')
    sunset = sunset.strftime('%I:%M:%S %p')

    # Create formatted strings with placeholders
    final_info = "{}\n{:.1f}°C".format(condition, temp)
    final_data = "\nMin Temp: {:.1f}°C\nMax Temp: {:.1f}°C\nPressure: {}\nHumidity: {}\nWind Speed: {}\nSunrise: {}\nSunset: {}".format(min_temp, max_temp, pressure, humidity, wind, sunrise, sunset)
    label1.config(text = final_info)
    label2.config(text = final_data)

# Create the main window
canvas = tk.Tk()
canvas.geometry("600x500")
canvas.title("Weather App")

# Create font objects
f = tkFont.Font(family="poppins", size=15, weight="bold")
t = tkFont.Font(family="poppins", size=35, weight="bold")

# Create the entry widget
textField = tk.Entry(canvas, justify='center', width = 20, font = t)
textField.pack(pady = 20)
textField.focus()

# Bind the return key to the getWeather function
textField.bind('<Return>', lambda event: getWeather(canvas))

# Create the label widgets
label1 = tk.Label(canvas, font=t)
label1.pack()
label2 = tk.Label(canvas, font=f)
label2.pack()

# Start the main loop
canvas.mainloop()
