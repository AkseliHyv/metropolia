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
    types = {}
    iso = input('Anna ISO-maakoodi: ')
    cursor.execute("SELECT type FROM airport WHERE iso_country=%s", (iso,))
    result = cursor.fetchall()

    if cursor.rowcount > 0:
        for type in result:
            types[type[0]] = types.get(type[0], 0) + 1
    else:
        print('ISO tunnus ei ole oikea')

    for type in types:
        print(types[type], type)