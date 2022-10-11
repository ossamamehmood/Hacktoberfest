import pyautogui,time

time.sleep(5)

f = open('spam.txt','r')
for w in f:
    pyautogui.typewrite(w)
    pyautogui.press('enter')


