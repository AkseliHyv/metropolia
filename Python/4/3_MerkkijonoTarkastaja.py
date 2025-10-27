numero_jono = []
while True:
    numero = input('Anna numero: ')

    if len(numero) == 0: break
    try:
        numero_jono.append(float(numero))
    except ValueError:
        print('Annettu arvo ei ole numero!')

print(f'Suurin numero: {max(numero_jono)}\nPienin numero: {min(numero_jono)}')