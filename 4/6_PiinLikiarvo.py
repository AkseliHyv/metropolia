import random
import os

while True:
    try:
        dot_amount = int(input('Syötä monta pistettä arvotaan: '))
        valid_number = True
    except ValueError:
        print('Syötetty arvo ei ole kokonaisnumero!')
        valid_number = False

    if not valid_number: continue

    falls_in_range = 0
    for i in range(dot_amount):
        if random.uniform(-1, 1)**2 + random.uniform(-1, 1)**2 < 1:
            falls_in_range += 1

        pi_average = 4 * falls_in_range / (i + 1)   # Syötän pi'n likiarvon koska se olisi
        print(pi_average)                           # tylsä odottaa ilman mitään tietoa