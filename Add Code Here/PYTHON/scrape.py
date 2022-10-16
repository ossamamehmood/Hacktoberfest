import cv2
import numpy as np
import urllib.request
import time
starttime = time.time()
#myurl = 'https://assets.pokemon.com/assets/cms2/img/pokedex/detail/001.png'
try:

    for i in range(1,6):
        myurl = 'https://assets.pokemon.com/assets/cms2/img/pokedex/detail/'+\
        '{:03d}'.format(i) +'.png'
        request = urllib.request.Request(myurl)
        response = urllib.request.urlopen(request)
        binary_string = response.read()
        byte_array = bytearray(binary_string)
        numpy_array = np.asarray(byte_array,dtype = "uint8")
        image = cv2.imdecode(numpy_array,cv2.IMREAD_UNCHANGED)
        cv2.imwrite("images/" + '{:03d}'.format(i) + ' .png' ,image)
        print("saved")
        #        print(myurl)

except Exception as e:
    print(str(e))        
endtime = time.time()
time_taken = ("time taken " + str(starttime - endtime) + "sec")
print(time_taken)