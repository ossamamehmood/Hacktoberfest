from cmath import exp
from getpass import getpass
import stdiomask
import re
def passwordValidator(password):
    if(not(password and password.strip())):
        return 0
    if(bool(re.match(r"^[0-9]*$",password))):
        digit=0.8
    elif(bool(re.match(r"^[a-zA-Z0-9]*$",password))):
        digit=1.5
    elif(bool(re.match(r"^[a-z]*$",password))):
        digit=1.0
    elif(bool(re.match(r"^[a-zA-Z]*$",password))):
        digit=1.3
    elif(bool(re.match(r"^[a-z\-_!?]*$",password))):
        digit=1.3
    elif(bool(re.match(r"^[a-z0-9]*$",password))):
        digit=1.2
    else:
        digit=1.8

    def logF(x):
        return 1.0/(1.0+exp(-x))
    def logC(x):
        return logF((x/2.0)-4.0)
    pass_strength=logC(len(password)*digit)
    return pass_strength
def main():
    password=stdiomask.getpass()
    passwordStrength=passwordValidator(password)
    #print(passwordStrength)
    floatStrength=float(('{0.real:.5f}'.format(passwordStrength)))*1.0
    print(floatStrength)
    #print(type(strStrength))
    if(floatStrength<=0.6):
        print("The Password is Weak")
    elif(floatStrength>0.6 and floatStrength<=0.9):
        print("The Password is Good")
    else:
        print("The Password is Strong")
if __name__ == "__main__":
    main()