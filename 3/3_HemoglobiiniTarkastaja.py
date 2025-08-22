while True:
    # sukupuolelle on oma while True lauseke, tämän avulla voimme varmistaa
    # että annettu sukupuoli on sallitussa muodossa
    while True:
        sukupuoli = str.lower(input('Anna biologinen sukupuoli (nainen/mies): '))
        # Jos arvo on oikeassa muodossa, käytämme break statementtia karataksemme loopista.
        if (sukupuoli == 'nainen') | (sukupuoli == 'mies'):
            break
        else:
            print('Anna kelvollinen biologinen sukupuoli!')

    # Varmistamme hg_arvon kelpoisuuden while blockin avulla
    while True:
        try:
            hg_arvo = float(input('Anna hemoglobiiniarvo (g/l): '))
            break
        except ValueError:
            print('Annettu arvo ei ole numero!')

    if sukupuoli == 'nainen':
        if hg_arvo > 117 and hg_arvo < 175:
            print('Hemoglobiiniarvot ovat normaalit.')
        else:
            print(f'Hemoglobiiniarvot ovat alhaiset!' if hg_arvo < 117 else 'Hemoglobiiniarvot ovat korkeat!')

    else: # tarkistimme aikaisemmin inputin yhteydessä, joten voimme olla 100% että tämä on mies
        if hg_arvo > 134 and hg_arvo < 195:
            print('Hemoglobiiniarvot ovat normaalit.')
        else:
            print(f'Hemoglobiiniarvot ovat alhaiset!' if hg_arvo < 134 else 'Hemoglobiiniarvot ovat korkeat!')