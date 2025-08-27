kevät = (1, 2, 3)
kesä = (4, 5, 6)
syksy = (7, 8, 9)
talvi =  (10, 11, 12)

while True:
    try:
        kuukausi = int(input('Anna kuukausi numerona: '))
        if kuukausi < 1 or kuukausi > 12:
            print('Anna kelvollinen kuukausi!')
            continue
        break
    except ValueError:
        print('Anna kelvollinen kuukausi!')

if kuukausi in kevät:
    print('Kuukausi on kevätkuukausi!')
elif kuukausi in kesä:
    print('Kuukausi on kesäkuukausi!')
elif kuukausi in syksy:
    print('Kuukausi on syksykuukausi!')
else:
    print('Kuukausi on talvikuukausi!')