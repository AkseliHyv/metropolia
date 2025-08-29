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

autot = []
for i in range(1, 11):
    autot.append(Auto(f'ABC-{i}', random.randint(100, 200)))

print('Paikoillanne...')
time.sleep(1)
print('Valmiina...')
time.sleep(1)
print('...')
time.sleep(2)
print('HEP!')
time.sleep(0.3)

tunti = 0
voittaja = ""

while True:
    tunti += 1
    if tunti % 2 == 0: print(f'------Tunti {tunti}------')

    for auto in autot:
        auto.kiihdytä(random.randint(-10, 15))
        auto.kulje(1)

        if tunti % 2 == 0: print(f'Auto {auto.rekisteritunnus} pituus: {auto.kuljettu_matka}km')

        if auto.kuljettu_matka >= 3000: # 10000 on liikaa ehkä
            print(f'Auto {auto.rekisteritunnus} voitti!')
            voittaja = auto.rekisteritunnus
            break

    if voittaja != "": break

    if tunti % 2 == 0: time.sleep(1)

for auto in autot:
    print(f"Auto {auto.rekisteritunnus}'n maksiminopeus: {auto.huippunopeus}km/h")
