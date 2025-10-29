import requests

url = "https://api.chucknorris.io/jokes/random"

while True:
    input("Press enter for a joke...")
    try:
        response = requests.get(url).json()
        print(response["value"])
    except requests.exceptions.RequestException:
        print("Error while fetching from API")