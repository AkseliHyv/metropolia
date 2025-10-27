while True:
    try:
        tuuma = float(input('Anna tuumat: '))
        if tuuma < 0: break
        
        print(f'{tuuma} tuumaa on {round(tuuma * 2.54, 2)}cm')

    except ValueError:
        print('Annettu arvo ei ole luku!')
        continue
