import phonenumbers
from phonenumbers import geocoder
from test import number
import folium

key ="fd02b55ab13b4eb4a76a0f251937afc9"

number = input("Enter phone number with country code:")
check_num = phonenumbers.parse(number)
number_location = geocoder.description_for_number(check_num,"en")
print(number_location)

from phonenumbers import carrier
check_num = phonenumbers.parse(number)
service_provider = carrier.name_for_number(check_num,"en")
print(service_provider)

from opencage.geocoder import OpenCageGeocode
geocoder = OpenCageGeocode(key)

query = str(number_location)
results = geocoder.geocode(query)

lat = results[0]['geometry']['lat']
lng = results[0]['geometry']['lng']
print(lat,lng)

map_location = folium.Map(location = [lat,lng], zoom_start = 9)
folium.Marker([lat,lng],popup=number_location).add_to(map_location)
map_location.save("mylocation.html")