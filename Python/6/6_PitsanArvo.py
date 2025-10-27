import math

# Luodaan class pitsoille, sillä niitten data on samaa
class Pitsa:
    hinta = 0.0
    halkaisia = 0.0

def pitsa_laskuri(pitsa1, pitsa2):
    # Lasketaan hinta per neliömetri
    pitsa1_hinta_nm = round(pitsa1.hinta / (math.pi * (pitsa1.halkaisia / 2) ** 2), 2)
    pitsa2_hinta_nm = round(pitsa2.hinta / (math.pi * (pitsa2.halkaisia / 2) ** 2), 2)

    # Arvioidaan
    print(f"Pitsa nro 1'n arvo: {pitsa1_hinta_nm}€/m²\nPitsa nro 2'n arvo: {pitsa2_hinta_nm}€/m²")
    print("Pitsa 1'n vastine on parempi" if pitsa1_hinta_nm < pitsa2_hinta_nm else "Pitsa 2'n vastine on parempi"
        if pitsa2_hinta_nm < pitsa1_hinta_nm else "Pitsat ovat saman hintaisia")

while True:
    try:
        pitsa1 = Pitsa()
        pitsa1.hinta = round(float(input("Anna pitsa nro 1'n hinta: ")),2)
        pitsa1.halkaisia = float(input("Anna pitsa nro 1'n halkaisia senttimetreinä: ")) / 100

        pitsa2 = Pitsa()
        pitsa2.hinta = round(float(input("Anna pitsa nro 2'n hinta: ")), 2)
        pitsa2.halkaisia = float(input("Anna pitsa nro 2'n halkaisia senttimetreinä: ")) / 100

        # 0 aiheuttaa ongelmia, eikä ole järkevä verrata ilmaisen sekä maksullisen, taikka olemattoman ja olemassa olevan pitsan hintaeroja
        if pitsa1.hinta == 0 or pitsa1.halkaisia == 0 or pitsa2.hinta == 0 or pitsa2.halkaisia == 0:
            print('Pitsojen hinnan ja halkaisian täytyy olla suurempi kuin 0!')
            continue

        break

    except ValueError:
        print('Anna kelvolliset lukumäärät!')

pitsa_laskuri(pitsa1, pitsa2)