import requests

while True:
    url = f"http://127.0.0.1:3000/alkuluku?luku={input('Anna luku: ')}"
    try:
        response = requests.get(url).json()
        print(response["message"])
    except requests.exceptions.RequestException:
        print("Error while fetching from API")