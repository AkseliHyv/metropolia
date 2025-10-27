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

while True:
    try:
        auto = Auto(input('Anna rekisteritunnus: '), float(input('Anna huippunopeus (km/h): ')))
        print(f'Rekisteritunnus: {auto.rekisteritunnus:s}\nHuippunopeus: {auto.huippunopeus}km/h\n'
              f'Tämänhetkinen nopeus: {auto.tämänhetkinen_nopeus}km/h\nKuljettu matka: {auto.kuljettu_matka}km')

        for i in [30, 70, 50, -200]:
            auto.kiihdytä(i)
            if i != -200:
                print(f'Auto kiihtyy, tämänhetkinen nopeus: {auto.tämänhetkinen_nopeus}km/h')
                auto.kulje(float(input('Kauan auto kulkee? (h): ')))
                print(f'Auto on nyt kulkenut {auto.kuljettu_matka}km')
            else:
                print(f'Hätäjarrutus! Tämänhetkinen nopeus: {auto.tämänhetkinen_nopeus}km/h')

    except ValueError:
        print('Virheelliset parametrit!')