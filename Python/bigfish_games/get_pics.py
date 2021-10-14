import requests
import shutil

fi = open("names.txt", "r")

# get all the icons of every game on bigfishgames in 3 different sizes

for name in fi.readlines():
    name = name[:-1]

    failed = False

    small_url = "https://bigfishgames-a.akamaihd.net/en_" + name + "/" + name + "_80x80.jpg"
    feature_url = "https://bigfishgames-a.akamaihd.net/en_" + name + "/" + name + "_feature.jpg"
    screen1 = "https://bigfishgames-a.akamaihd.net/en_" + name + "/" + "screen1.jpg"
    
    try:
        img = requests.get(small_url, stream = True)
        img.raw.decode_content = True

        with open(".\\80x80\\" + name + ".jpg",'wb') as f:
            shutil.copyfileobj(img.raw, f)
    except:
        failed = True

    try:
        img = requests.get(feature_url, stream = True)
        img.raw.decode_content = True

        with open(".\\features\\" + name + ".jpg",'wb') as f:
            shutil.copyfileobj(img.raw, f)
    except:
        failed = True

    try:
        img = requests.get(screen1, stream = True)
        img.raw.decode_content = True

        with open(".\\screen1\\" + name + ".jpg",'wb') as f:
            shutil.copyfileobj(img.raw, f)
    except:
        failed = True

    if failed == True: print(name + (66 - len(name)) *"." + "[OK]")
    else: print(name + (66 - len(name)) *"." + "[OK]")

fi.close()