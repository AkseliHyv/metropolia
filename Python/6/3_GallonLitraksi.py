def gallon_converter(gallons):
    return gallons * 3.785

while True:
    try:
        gallonit = float(input('Anna bensiinin määrän Yhdysvaltain nestegallonoina: '))
        if gallonit < 0: break
        print(round(gallon_converter(gallonit), 3))

    except ValueError:
        print('Anna kelvollinen lukumäärä!')

print('Heippa!')