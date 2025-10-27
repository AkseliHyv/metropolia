from flask import Flask, request
import mysql.connector

# Database credentials
user = "root"
password = "mdbadmin"
cursor = None

app = Flask(__name__)
@app.route("/lentokenttä")
def lentokentän_etsijä():
    # Saa argumentit
    args = request.args

    icao = (args.get("ICAO")).upper()

    cursor.execute("SELECT name, municipality FROM airport WHERE ident=%s", (icao,))
    result = cursor.fetchone()

    if result == None:
        return {"message": f"Could not find airport with ident/ICAO of {icao}"}

    return {"ICAO":icao, "Name":result[0], "Municipality":result[1]}

if __name__ == '__main__':
    try:
        connection = mysql.connector.connect(
            host='127.0.0.1',
            port=3306,
            database="flight_game",
            user=user,
            password=password,
            autocommit=True
        )
        cursor = connection.cursor()
    except mysql.connector.errors.ProgrammingError:
        print('Virheelliset käyttäjätunnukset.')
        exit(0)

    app.run(use_reloader=True, host='127.0.0.1', port=3000)