while True:
    num1 = input('Anna numero 1: ')
    num2 = input('Anna numero 2: ')
    num3 = input('Anna numero 3: ')
    # Jälleen sama asia. Käytän tätä if-else lausekkeiden sijasta koska
    # se on näin pienessä sovelluksessa helpompaa ja yksinkertaisempaa.
    try:
        summa = float(num1) + float(num2) + float(num3)
        tulo = float(num1) * float(num2) * float(num3)
        keskiarvo = (float(num1) + float(num2) + float(num3)) / 3

        print(f'summa: {summa}\ntulo: {round(tulo, 2)}\nkeskiarvo: {round(keskiarvo, 2)}')

    except ValueError:
        print('Arvojen täytyy olla numeroita!')