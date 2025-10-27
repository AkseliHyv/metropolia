import requests

while True:
    url = f"http://127.0.0.1:3000/lentokenttä?ICAO={input('Anna ICAO-koodi: ')}"
    response = requests.get(url).json()
    # En siivoa tätä, sillä tehtävänannossa mainittiin mitä sen pitää palauttaa
    print(response)