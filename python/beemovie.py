import time, requests
import subprocess
import sys

def install(package):
    subprocess.check_call([sys.executable, "-m", "pip", "install", package])

print("Installing required libs...")

install("pyautogui")

import pyautogui

print("Getting the script...")

page = requests.get('https://gist.githubusercontent.com/MattIPv4/045239bc27b16b2bcf7a3a9a4648c08a/raw/2411e31293a35f3e565f61e7490a806d4720ea7e/bee%2520movie%2520script')
script = page.text

print("\n\n\nClick on a text window. Quick! You have 5 seconds.")
time.sleep(5)

for word in script:
    pyautogui.write(word)