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

class Sähköauto(Auto):
    def __init__(self, rekisteritunnus, huippunopeus, akkukapasiteetti):
        super().__init__(rekisteritunnus, huippunopeus)
        self.akkukapasiteetti = akkukapasiteetti

class Polttomoottoriauto(Auto):
    def __init__(self, rekisteritunnus, huippunopeus, bensatankin_koko):
        super().__init__(rekisteritunnus, huippunopeus)
        self.bensatankin_koko = bensatankin_koko

sähköauto = Sähköauto("ABC-15", 180, 52.5)
polttomoottoriauto = Polttomoottoriauto("ACD-123", 165, 32.3)

sähköauto.kiihdytä(180)
polttomoottoriauto.kiihdytä(165)
sähköauto.kulje(3)
polttomoottoriauto.kulje(3)
print(f"\nSähköauto kulkenut: {sähköauto.kuljettu_matka}km\nPolttomoottoriauto kulkenut: {polttomoottoriauto.kuljettu_matka}km")