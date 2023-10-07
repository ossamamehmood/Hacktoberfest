import pyautogui
import time

time.sleep(3)
for i in range(200):
    pyautogui.click(y=980, x=730, duration=0.4)
    pyautogui.write("Your Message")
    pyautogui.press('enter')
