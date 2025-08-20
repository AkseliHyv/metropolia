import os
import time

def search_projects():
    files = filter(os.path.isfile, os.listdir(os.curdir))
    files_to_return = []

    for file in files:
        if file.endswith('.py') & (file != os.path.basename(__file__)):
            files_to_return.append(file)

    return files_to_return

# Intro welcome
print('---------------------------------------------------------------------------')
print('Welcome to the entry program!')
print('You can use this to access different python projects made within Metropolia.')
print('Type "search" to search for projects, or type "help" for commands. To exit the program type "quit".')

# User input phase
while True:
    userInput = input('')
    if userInput == 'quit': # Quit
        print('Exiting...')
        break

    elif userInput == 'search': # Use search_projects to search and return all .py files
        print('Searching...')
        time.sleep(1)
        projects = search_projects()

        if len(projects) <= 0:
            print('No projects found.')
        else:
            for project in projects:
                print('-', project)
            print('type "open [project name]" without brackets to open a project.\n')

    elif userInput == 'help': # Display all commands
        print("asdasd")

    elif userInput.startswith('open '): # Open a project with the name given
        print("asdasd")

    else:
        print(f'"{userInput}" is not a recognized command. Type "help" to see a list of available commands.')