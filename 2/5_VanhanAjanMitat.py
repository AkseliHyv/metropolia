while True:
    leiviskät = input('Anna leiviskät: ')
    naulat = input('Anna naulat: ')
    luodit = input('Anna luodit: ')

    if leiviskät.isdigit() & naulat.isdigit() & luodit.isdigit():
        naulat = int(leiviskät) * 20 + int(naulat)
        luodit = int(naulat) * 32 + int(luodit)
        g = int(luodit) * 13.3

        kg = g // 1000
        g = g % 1000

        print(f'Massa on nykymitoilla:\n{kg}kg {g}g')
    else:
        print('Arvojen täytyy olla numeroita!')