import requests

while True:
    url = f"http://127.0.0.1:3000/lentokenttä?ICAO={input('Anna ICAO-koodi: ')}"
    try:
        response = requests.get(url).json()
        print(response)
    except requests.exceptions.RequestException:
        print("Error while fetching from API")