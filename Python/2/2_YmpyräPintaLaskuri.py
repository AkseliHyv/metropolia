import math

while True:
    säde = input('Anna ympyrän säde (senttimetreinä): ')
    # Käytämme try exceptiä laskussa, täten voimme hoitaa errorin joka tapahtuu virheellisen arvon vuoksi
    try:
        pinta_ala = math.pi * float(säde) ** 2
        print(f'Pinta-ala: {round(pinta_ala, 2)}cm²')

    except ValueError:
        print(f'{säde} ei ole numero.')