import random

def noppa():
    return random.randint(1, 6)

arvo = 0
while arvo != 6:
    arvo = noppa()
    print(arvo)