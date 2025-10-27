while True:
    leiviskat = input('Anna leiviskät: ')
    naulat = input('Anna naulat: ')
    luodit = input('Anna luodit: ')

    try:
        naulat = float(leiviskat) * 20 + float(naulat)
        luodit = float(naulat) * 32 + float(luodit)
        g = float(luodit) * 13.3

        kg = g // 1000
        g = g % 1000

        print(f'Massa on nykymitoilla:\n{kg}kg {round(g,2)}g')

    except ValueError:
        print('Arvojen täytyy olla numeroita!')