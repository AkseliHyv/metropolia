import requests

api_key = ""

while True:
    paikkakunta = input("Anna paikkakunta: ")
    url = f"http://api.openweathermap.org/geo/1.0/direct?q={paikkakunta}&appid={api_key}"
    try:
        response = requests.get(url).json()
    except requests.exceptions.RequestException:
        print("Error while fetching from API")
        continue
    try:
        lat = response[0]["lat"]
        lon = response[0]["lon"]
        url = f"https://api.openweathermap.org/data/2.5/weather?lat={lat}&lon={lon}&appid={api_key}&units=metric&lang=fi"
        response = requests.get(url).json()
        print(f"Paikkakunnalla {paikkakunta} säätila on {response['weather'][0]['description']},\nja ilma tuntuu olevan {response['main']['feels_like']}°C")
    except IndexError:
        print("Virheellinen paikkakunta!")