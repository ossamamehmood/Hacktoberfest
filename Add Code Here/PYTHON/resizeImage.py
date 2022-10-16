import cv2
def resizeImg():
    imgPath = input("Enter image path: ")
    name = input("Enter image name: ")
    img = cv2.imread(imgPath+"/"+name, cv2.IMREAD_UNCHANGED)

    newSize = int(input("Please enter scale percent: "))
    width = int(img.shape[1]*newSize/100)
    height = int(img.shape[0]*newSize/100)

    newImg = cv2.resize(img,(width,height), interpolation = cv2.INTER_AREA)
    cv2.imwrite(imgPath+"/new.jpg",newImg)

    cv2.imshow("Resized image", newImg)
    cv2.waitKey(0)
    cv2.destroyAllWindows()
    return newImg