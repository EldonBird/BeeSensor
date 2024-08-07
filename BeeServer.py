from flask import Flask, request
from datetime import datetime
app = Flask(__name__)

def outputstuff(data):
    with open("output.txt", "a") as f:
        print(f"{str(datetime.now())} @ {str(data)}", file=f)


@app.post('/Submit')
def submit():
    global temp

    
    temp = float(request.form.get('temp'))
    hum = float(request.form.get('hum'))

    outputstuff(temp)
    return str(temp)

if __name__ == "__main__":
    app.run(host='0.0.0.0', port=24640) 