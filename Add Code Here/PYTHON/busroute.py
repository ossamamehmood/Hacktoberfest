import urllib.request
from xml.etree.ElementTree import parse

daves_latitude = 41.98062

candidates = []

with urllib.request.urlopen('https://alerts.weather.gov/cap/us.php?x=1') as url:
    data = url.read()
    f = open('rt22.xml', "wb")
    f.write(data)
    f.close()

doc = parse('rt22.xml')
for bus in doc.findall('bus'):
    lat = float(bus.findtext('lat'))
    if lat > daves_latitude:
        direction = bus.findtext('d')
        if direction.startswith("North"):
            busid = bus.findtext('id')
            if busid not in candidates:
                candidates.insert(0, busid)
            print (busid, lat)
