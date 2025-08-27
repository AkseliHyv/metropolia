def lista_summaaja(lista):
    return sum(lista)

lista = []

while True:
    try:
        arvo = input('Anna luku (tai kirjoita "end" jatkaaksesi): ')

        if arvo == 'end':
            break
        else:
            lista.append(float(arvo))
            print('Tämänhetkinen lista:', lista)

    except ValueError:
        print('Anna kelvollinen luku!')

print(lista_summaaja(lista))