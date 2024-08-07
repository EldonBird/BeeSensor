from flask import Flask, request

app = Flask(__name__)

def SaveInfo(info):

    with open(f"Info.txt", "a") as file:
        file.write(f"\n{info}")
        

# Define the route to handle POST requests at the root URL
@app.route('/')
def root():

    Incriment = 0
    # Extract the 'info' field from the JSON data in the request
    data = request.json['info']

    SaveInfo(data)
    

    # Return a response indicating the operation was successful
    return "OK"

if __name__ == "__main__":
    app.run(host="0.0.0.0", port=24640)
