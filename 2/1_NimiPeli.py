import string

while True:
    name = input('What is your name?: ')

    if name.isdigit():
        print('I asked for your name, not your favorite number.')
    elif (str.isspace(name)) | (len(name) == 0):
        print('Do you not have a name?')
    elif any(not c.isalnum() for c in name):
        print('What an interesting name.')
    else:
        print(f'Hello, {name}!')