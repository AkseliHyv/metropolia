import requests

while True:
    url = f"http://127.0.0.1:3000/alkuluku?luku={input('Anna luku: ')}"
    response = requests.get(url).json()
    print(response["message"])