kaupungit = []

for i in range(5):
    while True:
        kaupunki = input('Anna kaupungin nimi: ')
        if len(kaupunki) < 3:
            print('Anna kelvollinen nimi!')
        else:
            break

    kaupungit.append(kaupunki)

for kaupunki in kaupungit:
    print(kaupunki)