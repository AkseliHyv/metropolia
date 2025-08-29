while True:
    try:
        luku = int(input('Anna luku: '))

        if luku <= 1: print('Luku ei ole alkuluku.')
        else:
            alkuluku = True
            for i in range(2, luku - 1):
                if luku % i == 0:
                    alkuluku = False
                    break
            print('Luku on alkuluku.' if alkuluku else 'Luku ei ole alkuluku.')

    except ValueError:
        print('Annettu luku ei ole kokonaisnumero!')