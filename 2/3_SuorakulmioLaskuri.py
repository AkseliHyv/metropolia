while True:
    kanta = input('Anna suorakulmion kanta (senttimetreinä): ')
    korkeus = input('Anna suorakulmion korkeus (senttimetreinä): ')
    # Sama homma kuin aikaisemmassa tehtävässä
    try:
        pinta_ala = float(kanta) * float(korkeus)
        piiri = float(kanta) * 2 + float(korkeus) * 2

        print(f'pinta-ala: {round(pinta_ala, 2)}cm²\npiiri: {round(piiri, 2)}cm')

    except ValueError:
        print('Kannan ja korkeuden täytyy olla numeroita!')