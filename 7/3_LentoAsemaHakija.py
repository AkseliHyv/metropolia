lentoasema_db = {}
print('Tervetuloa lentoaseman hakuohjelmaan! Valitse alla olevista vaihtoehdoista:\n'
      '1 - Hae olemassa olevia lentoasemia\n'
      '2 - Lisää uusi lentoasema\n'
      '3 - Lopeta')
while True:
    query = input()

    if query == '1':
        icao = input('Anna lentoaseman ICAO-koodi: ')
        if icao in lentoasema_db:
            print('Lentoaseman nimi:', lentoasema_db[icao])
        else:
            print('Lentoasemaa ei löytynyt kyseisellä ICAO-koodilla')

    elif query == '2':
        lentoasema_db[input('ICAO-koodi: ')] = input('Lentoaseman nimi: ')
        print('Lentoasema lisätty!')

    elif query == '3':
        break