import requests
import tkinter as tk
from tkinter import ttk

# Create a function to fetch COVID-19 data from an API
def fetch_covid_data():
    try:
        url = "https://api.covid19api.com/summary"  # API endpoint for global COVID-19 data
        response = requests.get(url)
        data = response.json()

        # Extract data
        global_data = data['Global']

        # Update the labels in the GUI with the latest data
        confirmed_label.config(text=f"Confirmed: {global_data['TotalConfirmed']}")
        deaths_label.config(text=f"Deaths: {global_data['TotalDeaths']}")
        recovered_label.config(text=f"Recovered: {global_data['TotalRecovered']}")

    except Exception as e:
        print("Error fetching data:", e)

# Create a GUI window
root = tk.Tk()
root.title("COVID-19 Tracker")

# Create labels to display COVID-19 data
confirmed_label = ttk.Label(root, text="Confirmed: ")
deaths_label = ttk.Label(root, text="Deaths: ")
recovered_label = ttk.Label(root, text="Recovered: ")

confirmed_label.pack()
deaths_label.pack()
recovered_label.pack()

# Create a button to fetch data
update_button = ttk.Button(root, text="Update Data", command=fetch_covid_data)
update_button.pack()

# Fetch data when the program starts
fetch_covid_data()

# Start the GUI main loop
root.mainloop()


