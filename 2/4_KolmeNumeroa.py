while True:
    num1 = input('Anna numero 1: ')
    num2 = input('Anna numero 2: ')
    num3 = input('Anna numero 3: ')

    if num1.isdigit() & num2.isdigit() & num3.isdigit():
        summa = int(num1) + int(num2) + int(num3)
        tulo = int(num1) * int(num2) * int(num3)
        keskiarvo = (int(num1) + int(num2) + int(num3)) / 3

        print(f'summa: {summa}\ntulo: {tulo}\nkeskiarvo: {round(keskiarvo, 2)}')
    else:
        print('Arvojen täytyy olla numeroita!')