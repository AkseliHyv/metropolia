import random

while True:
    password = []
    option = input(f'Onko lukkosi kolmenumeroinen (1) vai nelinumeroinen (2)?: ')

    if (str.lower(option) == '1') | (str.lower(option) == 'kolmenumeroinen'):
        for i in range(3):
            password.append(random.randint(0, 9))
        print(f'Salasanasi: {password}')

    elif (str.lower(option) == '2') | (str.lower(option) == 'nelinumeroinen'):
        for i in range(4):
            password.append(random.randint(0, 6))
        print(f'Salasanasi: {password}')

    else:
        print(f'{option} ei ole vaihtoehto!')