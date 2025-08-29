class Auto:
    def __init__(self, rekisteritunnus, huippunopeus):
        self.rekisteritunnus = rekisteritunnus
        self.huippunopeus = huippunopeus
        self.tämänhetkinen_nopeus = 0
        self.kuljettu_matka = 0

while True:
    try:
        auto = Auto(input('Anna rekisteritunnus: '), float(input('Anna huippunopeus (km/h): ')))
        print(f'Rekisteritunnus: {auto.rekisteritunnus:s}\nHuippunopeus: {auto.huippunopeus}km/h\n'
              f'Tämänhetkinen nopeus: {auto.tämänhetkinen_nopeus}km/h\nKuljettu matka: {auto.kuljettu_matka}km')
    except ValueError:
        print('Virheelliset parametrit!')