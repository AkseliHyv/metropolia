import mysql.connector

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
    icao = input('Anna ICAO-koodi: ')
    cursor.execute("SELECT name, municipality FROM airport WHERE ident=%s", (icao,))
    result = cursor.fetchall()

    if cursor.rowcount > 0:
        print(result[0])
    else:
        print('ICAO tunnus ei ole oikea')