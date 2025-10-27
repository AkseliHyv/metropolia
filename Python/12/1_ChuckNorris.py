import requests

url = "https://api.chucknorris.io/jokes/random"

while True:
    input("Press enter for a joke...")
    response = requests.get(url).json()
    print(response["value"])