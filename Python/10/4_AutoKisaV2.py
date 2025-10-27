import random
import time

class Auto:
    def __init__(self, rekisteritunnus, huippunopeus):
        self.rekisteritunnus = rekisteritunnus
        self.huippunopeus = huippunopeus
        self.tämänhetkinen_nopeus = 0
        self.kuljettu_matka = 0
    def kiihdytä(self, muutos):
        self.tämänhetkinen_nopeus = max(min(self.tämänhetkinen_nopeus + muutos, self.huippunopeus), 0)
    def kulje(self, matka):
        self.kuljettu_matka += self.tämänhetkinen_nopeus * matka

class Kilpailu:
    def __init__(self, nimi, kisan_pituus, autot):
        self.nimi = nimi
        self.kisan_pituus = kisan_pituus
        self.autot = autot

    def tunti_kuluu(self):
        for auto in self.autot:
            auto.kiihdytä(random.randint(-10, 15))
            auto.kulje(1)

    def tulosta_tilanne(self):
        final_string = ""
        for auto in self.autot:
            final_string += f"Auto {auto.rekisteritunnus} pituus: {auto.kuljettu_matka}km\n"
        return final_string

    def kilpailu_ohi(self):
        kisa_ohi = False
        for auto in self.autot:
            if auto.kuljettu_matka > self.kisan_pituus:
                kisa_ohi = True
        return kisa_ohi

autot = []
for i in range(1, 11):
    autot.append(Auto(f'ABC-{i}', random.randint(100, 200)))

tunti = 0
while True:
    try:
        kisa = Kilpailu(input("Anna kisan nimi: "), int(input("Anna kisan pituus (km): ")), autot)
        break
    except ValueError:
        print("Virheelliset parametrit!")

print('Paikoillanne...')
time.sleep(1)
print('Valmiina...')
time.sleep(1)
print('...')
time.sleep(2)
print('HEP!')
time.sleep(0.3)

while True:
    tunti += 1
    if tunti % 2 == 0: print(f'----{kisa.nimi}: Tunti {tunti}----')

    kisa.tunti_kuluu()
    print(kisa.tulosta_tilanne())
    if kisa.kilpailu_ohi():
        break

    if tunti % 2 == 0: time.sleep(1)

input("Kisa ohi! Paina enteriä jatkaaksesi...\n")
voittajat = "Kisan voitti "
for auto in kisa.autot:
    print(f"Auto {auto.rekisteritunnus}'n maksiminopeus: {auto.huippunopeus}km/h")
    if auto.kuljettu_matka > kisa.kisan_pituus:
        # Lisää pilkku autojen erottamiseksi
        if not voittajat.endswith("voitti "):
            voittajat += ", "
        voittajat += auto.rekisteritunnus
print(voittajat)

