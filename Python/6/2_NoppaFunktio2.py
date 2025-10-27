import random

def noppa(max):
    return random.randint(1, max)

while True:
    try:
        maksimi_arvo = int(input('Anna nopan maksimiarvo: '))
        break
    except ValueError:
        print('Annettu arvo ei ole kokonaisluku!')

arvo = 0
while arvo != maksimi_arvo:
    arvo = noppa(maksimi_arvo)
    print(arvo)