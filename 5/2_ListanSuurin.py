numero_jono = []
while True:
    # Tämä on peräisin aikaisemmasta tehtävästäni 4\3_MerkkijonoTarkastaja.py
    numero = input('Anna numero: ')

    if len(numero) == 0 and len(numero_jono) > 4: break
    elif len(numero) == 0:
        print('Numerojonon täytyy olla ainakin 5 numeroa pitkä!')
        continue

    try:
        numero_jono.append(float(numero))
    except ValueError:
        print('Annettu arvo ei ole numero!')

numero_jono.sort(reverse=True)

print('5 suurinta numeroa:')
for i in range(0,5):
    print(str.removesuffix(str(numero_jono[i]), '.0'))