def lista_karsia(lista):
    for i in lista:
        if i % 2 != 0:
            lista.remove(i)
    return lista

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

print(lista_karsia(lista))