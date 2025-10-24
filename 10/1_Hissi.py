import time

class Hissi:
    def __init__(self, alin_kerros, ylin_kerros):
        self.alin_kerros = alin_kerros
        self.ylin_kerros = ylin_kerros
        self.kerros = alin_kerros

    def siirry_kerrokseen(self, kerros):
        while True:
            if self.kerros < kerros:
                self.kerros += 1
            elif self.kerros > kerros:
                self.kerros -= 1
            else:
                break

            print(f"Hissi on kerroksessa {self.kerros}")
            time.sleep(0.3)

    def kerros_ylös(self):
        self.kerros = min(self.kerros + 1, self.ylin_kerros)

    def kerros_alas(self):
        self.kerros = max(self.kerros - 1, self.alin_kerros)


h = None
while True:
    # Get initial values
    try:
        if h is None:
            alin_kerros = int(input("Anna alin kerros: "))
            ylin_kerros = int(input("Anna ylin kerros: "))
            h = Hissi(alin_kerros, ylin_kerros)
    except ValueError:
        print("Annettu arvo ei ole numero!")
        continue

    # Ask user for floor between the max and min floors, and take them there
    try:
        kerros = int(input(f"Anna kerros johon siirtyä (alin: {h.alin_kerros}, ylin: {h.ylin_kerros}): "))
        # Check and ensure floor exists
        if kerros < h.alin_kerros or kerros > h.ylin_kerros:
            print("Annettua kerrosta ei ole olemassa!")
            continue
        # If fine, then move them to floor
        h.siirry_kerrokseen(kerros)
    except ValueError:
        print("Annettu arvo ei ole numero!")