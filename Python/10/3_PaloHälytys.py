import time

class Hissi:
    def __init__(self, nimi, alin_kerros, ylin_kerros):
        self.nimi = nimi
        self.alin_kerros = alin_kerros
        self.ylin_kerros = ylin_kerros
        self.kerros = alin_kerros

    def siirry_kerrokseen(self, kerros):
        while True:
            if self.kerros < kerros:
                self.kerros_ylös()
            elif self.kerros > kerros:
                self.kerros_alas()
            else:
                break

            print(f"{self.nimi} on kerroksessa {self.kerros}")
            time.sleep(0.3)

    def __str__(self):
        return self.nimi

    def kerros_ylös(self):
        self.kerros = min(self.kerros + 1, self.ylin_kerros)

    def kerros_alas(self):
        self.kerros = max(self.kerros - 1, self.alin_kerros)

class Talo:
    def __init__(self, nimi, alin_kerros, ylin_kerros, hissien_määrä):
        self.nimi = nimi
        self.alin_kerros = alin_kerros
        self.ylin_kerros = ylin_kerros
        self.hissien_määrä = hissien_määrä
        self.hissit = []

        for i in range(hissien_määrä):
            self.hissit.append(Hissi(f"hissi {i}", alin_kerros, ylin_kerros))

    def __str__(self):
        return self.nimi

    def aja_hissiä(self, hissin_nro, haluttu_kerros):
        for hissi in self.hissit:
            if hissi.nimi == f"hissi {hissin_nro}":
                hissi.siirry_kerrokseen(haluttu_kerros)

    def palohälytys(self):
        for i in range(len(self.hissit)):
            self.aja_hissiä(i, self.alin_kerros)

def luo_talo():
    try:
        nimi = input("Talon nimi: ")
        alin_kerros = int(input("Anna talon alin kerros: "))
        ylin_kerros = int(input("Anna talon ylin kerros: "))
        hissien_määrä = int(input("Anna talon hissien määrä: "))

        return Talo(nimi, alin_kerros, ylin_kerros, hissien_määrä)
    except ValueError:
        print("Annettu arvo ei ole numero!")
        return None

def valitse_talo():
    try:
        # -1 so we get correct index, (aka 0-x, not 1-x)
        index = int(input("Valitse talo: ")) - 1

        if index < 0 or index >= len(talot):
            print("Annettu talo ei ole olemassa!")
            return None

        return talot[index]

    except ValueError:
        print("Annettu arvo ei ole numero!")
        return None

# Initially returned the elevator directly, modified to fill requirement of task
def valitse_hissi(talo):
    try:
        # Same thing
        index = int(input("Valitse hissi: ")) - 1

        # Allow one index over limit (for fire alarm)
        if index < 0 or index > len(talo.hissit):
            print("Annettu hissi ei ole olemassa!")
            return None

        return index

    except ValueError:
        print("Annettu arvo ei ole numero!")
        return None

def käytä_hissiä(hissi_nro, talo):
    try:
        # Get elevator via given index
        hissi = talo.hissit[hissi_nro]
        kerros = int(input(f"Anna kerros johon siirtyä (alin: {hissi.alin_kerros}, ylin: {hissi.ylin_kerros}): "))
        # Check and ensure floor exists
        if kerros < hissi.alin_kerros or kerros > hissi.ylin_kerros:
            print("Annettua kerrosta ei ole olemassa!")
            return None
        # If fine, then move them to floor
        talo.aja_hissiä(hissi_nro, kerros)
    except ValueError:
        print("Annettu arvo ei ole numero!")

talot = []
while True:
    # Get initial values
    valinta = input("Valitse vaihtoehto: \n1. Luo talo\n2. Valitse talo\n")
    if valinta not in ("1", "2"):
        print("Valitse vaihtoehto!")
        continue

    # Luo talo
    if valinta == "1":
        talo = luo_talo()
        if talo is None: continue
        talot.append(talo)

    # Select house and operate elevator
    elif valinta == "2":
        # Print houses
        for i in range(len(talot)):
            print(f"{i + 1}. {talot[i]}")

        # Select house
        talo = valitse_talo()

        if talo is None:
            continue

        # Print elevators in house
        if len(talo.hissit) == 0:
            print("Talolla ei ole hissejä!")
            continue
        for i in range(len(talo.hissit)):
            print(f"{i + 1}. {talo.hissit[i]}")
            # Print new option for fire alarm
            if i == len(talo.hissit) - 1:
                print(f"{i + 2}. Paina palohälytysnappia")


        # Select the wanted elevator's number
        hissi_nro = valitse_hissi(talo)

        if hissi_nro is None:
            continue

        # Check if using fire alarm
        if hissi_nro == len(talo.hissit):
            talo.palohälytys()
            continue

        # Use elevator
        käytä_hissiä(hissi_nro, talo)