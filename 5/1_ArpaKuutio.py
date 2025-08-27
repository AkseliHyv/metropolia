import random

while True:
    try:
        arpa_maara = int(input('Anna arpakuutioiden lukumäärä: '))
        arpa_numerot = []

        for i in range(arpa_maara):
            arpa_numerot.append(random.randint(1,6))

        print(f'Arpakuutiot heitti numerot {arpa_numerot},\njoiden summa on {sum(arpa_numerot)}')

    except ValueError:
        print('Annettu arvo ei ole kokonaisluku!')
