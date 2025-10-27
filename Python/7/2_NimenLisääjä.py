nimet = set()

def nimen_lisääjä(nimi):
    if nimi in nimet:
        print('Nimi on jo joukossa')
    else:
        nimet.add(nimi)
        print('Uusi nimi lisätty')

while True:
    nimi = input('Anna nimi: ')
    if nimi == "": break
    nimen_lisääjä(nimi)

print(nimet)