import random

while True:
    password = []
    option = str.lower(input(f'Onko lukkosi kolmenumeroinen (3) vai nelinumeroinen (4)?: '))

    # Python 3.9 ei tue match statementteja, joten käytän vain if else lausekkeita tässä
    if option == '3' or option == 'kolmenumeroinen' or option == 'kolme':
        for i in range(3):
            password.append(random.randint(0, 9))
        print(f'Salasanasi: {password}')

    elif option == '4' or option == 'nelinumeroinen' or option == 'neljä':
        for i in range(4):
            password.append(random.randint(0, 6))
        print(f'Salasanasi: {password}')

    else:
        print(f'{option} ei ole vaihtoehto!')