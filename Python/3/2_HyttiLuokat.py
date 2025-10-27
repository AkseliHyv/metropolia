print('Tervetuloa käyttämään hyttiluokkien info-sovellusta!')
print('Kirjoita yksi seuraavista hyttiluokista sadaaksesi infoa siitä:')
print('-LUX\n-A\n-B\n-C')

while True:
    hytti_luokka = str.lower(input(''))

    if hytti_luokka == 'lux':
        print('LUX on parvekkeellinen hytti yläkannella.')
    elif hytti_luokka == 'a':
        print('A on ikkunallinen hytti autokannen yläpuolella.')
    elif hytti_luokka == 'b':
        print('B on ikkunaton hytti autokannen yläpuolella.')
    elif hytti_luokka == 'c':
        print('C on ikkunaton hytti autokannen alapuolella.')
    else:
        print(f'{hytti_luokka} ei ole olemassa oleva hytti-luokka, ole hyvä ja valitse jokin seuraavista:')
        print('-LUX\n-A\n-B\n-C')