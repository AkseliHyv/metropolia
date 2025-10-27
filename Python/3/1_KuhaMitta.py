while True:
    # Pistän inputin jo suoraan try catchin sisälle sillä teen muunnoksen välittömästi
    try:
        mitta = float(input('Ilmoita kuhan pituus (senttimetreinä): '))
        if mitta < 37:
            print(f'Vapauta kuha takaisin veteen, se on {37-mitta}cm liian pieni napattavaksi.')
        else:
            print('Kuha on tarpeeksi iso napattavaksi!')

    except ValueError:
        print('Annettu arvo ei ole numero!')