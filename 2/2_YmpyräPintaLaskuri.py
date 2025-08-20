import math

while True:
    säde = input('Anna ympyrän säde: ')

    if säde.isdigit():
        pinta_ala = math.pi * int(säde) ** 2
        print(f'Pinta-ala: {round(pinta_ala, 2)}')
    else:
        print(f'{säde} ei ole numero.')