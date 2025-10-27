from flask import Flask, request

app = Flask(__name__)
@app.route("/alkuluku")
def alkuluku_selvittäjä():
    # Saa argumentit
    args = request.args

    try:
        luku = int(args.get("luku"))
    except ValueError:
        return {"message": "Luku ei ole integer!", "alkuluku": False}

    if luku == None:
        return {"message": "Lukua ei annettu!", "alkuluku": False}

    if luku <= 1:
        return {"message": "Luku ei ole alkuluku.", "alkuluku": False}
    else:
        alkuluku = True
        for i in range(2, luku - 1):
            if luku % i == 0:
                return {"message": "Luku ei ole alkuluku.", "alkuluku": False}
        return {"message": "Luku on alkuluku.", "alkuluku": True}

if __name__ == '__main__':
    app.run(use_reloader=True, host='127.0.0.1', port=3000)