import mysql.connector
import geopy.distance

user = input('Anna käyttäjänimi: ')
password = input('Anna salasana: ')

try:
    connection = mysql.connector.connect(
         host='127.0.0.1',
         port= 3306,
         database="flight_game",
         user=user,
         password=password,
         autocommit=True
    )
    cursor = connection.cursor()
except mysql.connector.errors.ProgrammingError:
    print('Virheelliset käyttäjätunnukset.')
    exit(0)

while True:
    icao1 = input('Anna ensimmäisen lentokentän ICAO-koodi: ')
    icao2 = input('Anna toisen lentokentän ICAO-koodi: ')

    cursor.execute("SELECT name, latitude_deg, longitude_deg FROM airport WHERE ident=%s OR ident=%s", (icao1,icao2,))
    results = cursor.fetchall()

    locations = {name: (lat, lon) for name, lat, lon in results}

    if len(locations) < 2:
        print('Jompikumpi ICAO-koodeista oli virheellinen!')
        continue

    distance = geopy.distance.great_circle(list(locations.values())[0], list(locations.values())[1]).km

    print(f'Etäisyys {list(locations)[0]} ja {list(locations)[1]} välillä on {round(distance,2)}km')