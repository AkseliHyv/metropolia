print('Kolmella jaolliset luvut:')

# Käyttäisin tässä for looppia, mutta tehtäväannon mukaan:
jaolliset_kolmella = []
numero = 1

while numero <= 1000:
    if numero % 3 == 0:
        jaolliset_kolmella.append(numero)
    numero += 1

print(jaolliset_kolmella)