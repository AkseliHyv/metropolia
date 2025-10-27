import random

oikea_numero = random.randint(1, 10)
while True:
    try:
        arvaus = int(input('Arvaa tasaluku väliltä 1-10: '))
    except ValueError:
        print('Annettu arvo ei ole tasaluku!')
        continue

    if arvaus == oikea_numero: break
    print('Liian suuri arvaus' if arvaus > oikea_numero else 'Liian pieni arvaus')

print('Oikea arvaus!')