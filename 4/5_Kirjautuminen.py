correct_user = 'python'
correct_pass = 'rules'
guesses = 0

while True:
    user = input('Anna käyttäjänimi: ')
    password = input('Anna salasana: ')

    if correct_user == user and correct_pass == password:
        print('Tervetuloa!')
        break
    else:
        guesses += 1
        print(f'Virheelliset kirjautumistiedot. Yrityskertoja jäljellä: {5-guesses}')

    if guesses == 5:
        print('Pääsy evätty.')
        break