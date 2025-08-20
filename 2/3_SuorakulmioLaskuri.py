while True:
    kanta = input('Anna suorakulmion kanta: ')
    korkeus = input('Anna suorakulmion korkeus: ')

    if kanta.isdigit() & korkeus.isdigit():
        pinta_ala = int(kanta) * int(korkeus)
        piiri = int(kanta) * 2 + int(korkeus) * 2

        print(f'pinta-ala: {round(pinta_ala, 2)}\npiiri: {round(piiri, 2)}')
    else:
        print('Kannan ja korkeuden täytyy olla numeroita!')