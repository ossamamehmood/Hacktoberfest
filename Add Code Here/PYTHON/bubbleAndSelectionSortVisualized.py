import time
from tkinter import Tk, Canvas, Frame, BOTH, Widget
import math
import random
import tkinter
import argparse
from typing import Text

# Window and drawing properties
WINDOW_WIDTH = 1920 // 2
WINDOW_HEIGHT = 1080 // 2

SORTING_LIST = []
# Animation speed in ms
ANIM_SPEED = 100

# Drawing class


class Window(Frame):

    # Canvas used in this class
    canvas = None

    def __init__(self):
        # Initialize tkinter
        super().__init__()

        # Assign canvas
        self.canvas = Canvas(self)

    def displayList(self, sortingList):
        canvas = self.canvas
        canvas.delete("all")
        self.pack(fill=BOTH, expand=1)
        cnt = 0
        width = (WINDOW_WIDTH / len(sortingList))

        outline = "white"
        if width < 2:
            outline = "black"

        for i in reversed(SORTING_LIST):
            x0 = int(cnt * width)
            x1 = int(x0 + (width))

            y0 = WINDOW_HEIGHT
            y1 = mapRange(i, min(SORTING_LIST), max(
                SORTING_LIST), 0, WINDOW_HEIGHT - 10)

            cnt += 1

            canvas.create_rectangle(
                x0, y0, x1, y1, outline=outline, fill="black")

        canvas.pack(fill=BOTH, expand=1)


def mapRange(value, inMin, inMax, outMin, outMax):
    return outMin + (((value - inMin) / (inMax - inMin)) * (outMax - outMin))


def PopulateList(n, lowerBound, upperBound):
    newList = []
    for i in range(n):
        newList.append(random.randrange(lowerBound, upperBound))

    SORTING_LIST[:] = newList


def bubbleSort(root, window, lst):
    n = len(lst)

    swapped = False
    # Traverse through all list elements
    for i in range(n-1):
        for j in range(0, n-i-1):

            # traverse the list from 0 to n-i-1
            # Swap if the element found is greater
            if lst[j] > lst[j + 1]:
                swapped = True
                lst[j], lst[j + 1] = lst[j + 1], lst[j]

        root.after(ANIM_SPEED, window.displayList(lst), window)
        root.update()

        if not swapped:
            # No swap needed, list is sorted
            return


def selectionSort(root, window, lst):
    size = len(lst)

    # Loop through list
    for ind in range(size):
        min_index = ind

        for j in range(ind + 1, size):
            # select the minimum element in every iteration
            if lst[j] < lst[min_index]:
                min_index = j

         # swapping the elements to sort the array
        (lst[ind], lst[min_index]) = (lst[min_index], lst[ind])
        root.after(ANIM_SPEED, window.displayList(lst), window)
        root.update()


def main():
    global ANIM_SPEED
    # Add argument parser
    parser = argparse.ArgumentParser()

    # -n can be used to set list size
    parser.add_argument('-n', type=int, required=False)

    # -s can be used to define the animation speed
    parser.add_argument('-s', type=int, required=False)

    # -selection can be used to sort using selection sort
    parser.add_argument('-selection', action=argparse.BooleanOptionalAction)
    args = parser.parse_args()

    useSelection = False
    elementCount = 100

    if args.n != None and args.n >= 1:
        elementCount = args.n

    if args.s != None and args.s >= 1:
        ANIM_SPEED = args.s

    if args.selection != None:
        useSelection = True

    PopulateList(elementCount, 0, 100)

    # Set up Tkinter window
    root = Tk()
    root.title("Sorting Algorithms")

    # Init window class
    window = Window()

    # Set window size
    root.geometry("%sx%s" % (WINDOW_WIDTH, WINDOW_HEIGHT))
    window.displayList(SORTING_LIST)
    root.update()

    if useSelection:
        root.after(10, selectionSort(root, window, SORTING_LIST), window)
    else:
        root.after(10, bubbleSort(root, window, SORTING_LIST), window)

    # Update window
    root.update()
    root.mainloop()


# Call main function
if __name__ == "__main__":
    main()
