while True:
    try:
     vuosi = int(input('Anna vuosiluku: '))
    except ValueError:
        print('Annettu arvo ei ole vuosiluku!')
        continue

    if vuosi % 100 == 0 and vuosi % 400 != 0: # Jaollinen sadalla mutta ei neljällä sadalla
        print('Vuosi ei ole karkausvuosi.')
    elif vuosi % 4 == 0:
        print('Vuosi on karkausvuosi.')
    else:
        print('Vuosi ei ole karkausvuosi')

    # Sillä alussa tarkistamme onko vuosi tasavuosisata joka ei ole jaollinen luvulla 400,
    # voimme varmistaa että toiseen if lausekkeeseen tulee vain lukuja jotka ovat joko ei tasavuosisatoja,
    # tai tasavuosisatoja toka ovat jaollisia luvulla 400. Sillä 400 on jaollinen neljällä, toinen if
    # lauseke riittää tarkastamaan joka ikisen vuoden.