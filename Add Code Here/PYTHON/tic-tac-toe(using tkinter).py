import tkinter as tk
import tkinter.font as tkFont

# from trial2 import *
fr2 = 0
lb_scorex, lb_scoreo = 0, 0
scorex, scoreo = 0, 0
c = 0


def startmain():
    window = tk.Toplevel(win2)
    window.resizable(False, False)
    f = tkFont.Font(family="Hero", size=50)
    window.geometry('386x482')
    fr = tk.Frame(background='#000000', master=window)
    fr.grid(row=0, column=0)

    lst1 = [[False, False, False], [False, False, False], [False, False, False]]
    lst2 = [[False, False, False], [False, False, False], [False, False, False]]

    def x_won():
        global scorex

        # lb = tk.Label(text='X won', master=fr)
        # lb.grid(row=1, column=3)

        window.destroy()
        print("X won this game")
        scorex += 1
        print(scorex)

        lb_scorex.config(text=scorex)

    def o_won():
        global scoreo
        # lb = tk.Label(text='O won', master=fr)
        # lb.grid(row=1, column=4)
        window.destroy()
        print("O won this game")
        scoreo += 1
        lb_scoreo.config(text=scoreo)

    def start(bid, bname, ro, co):
        global c

        if c % 2 == 0:  # c is even X plays first
            bname.destroy()
            lb = tk.Label(text='X', font=f, master=fr, width=3, height=2, background='#000000', borderwidth=2,
                          fg='#ff008d')
            lb.grid(row=ro, column=co)
            if bid <= 3:
                # bid==bid
                # print(bid)
                lst1[0][bid - 1] = True
                # print(lst1)
            elif bid > 3 and bid <= 6:
                bid = bid - 3
                # print(bid)
                lst1[1][bid - 1] = True
                # print(lst1)
            elif bid > 6:
                bid = bid - 6
                # print(bid)
                lst1[2][bid - 1] = True
                # print(lst1)
            for i in range(0, 3):
                if lst1[i][0] == lst1[i][1] == lst1[i][2] == True:
                    # print("X won in row")
                    x_won()

                    break
                elif lst1[0][i] == lst1[1][i] == lst1[2][i] == True:
                    # print("X won in column")
                    x_won()

                    break
                elif lst1[0][0] == lst1[1][1] == lst1[2][2] == True:
                    # print('X won diagonally')
                    x_won()

                    break
                elif lst1[0][2] == lst1[1][1] == lst1[2][0] == True:
                    # print('X won reverse diagonally ')
                    x_won()

                    break
            c += 1
        else:  # for O
            bname.destroy()
            lb = tk.Label(text='O', font=f, master=fr, width=3, height=2, background='#000000', fg='#001eff')
            lb.grid(row=ro, column=co)
            if bid <= 3:
                # bid==bid
                # print(bid)
                lst2[0][bid - 1] = True
            elif bid > 3 and bid <= 6:
                bid = bid - 3
                # print(bid)
                lst2[1][bid - 1] = True

            elif bid > 6:
                bid = bid - 6
                # print(bid)
                lst2[2][bid - 1] = True
                # print(lst2)
            for i in range(0, 3):
                if lst2[i][0] == lst2[i][1] == lst2[i][2] == True:
                    # print("O won in row")
                    o_won()

                    break
                elif lst2[0][i] == lst2[1][i] == lst2[2][i] == True:
                    # print("O won in column")
                    o_won()

                    break
                elif lst2[0][0] == lst2[1][1] == lst2[2][2] == True:
                    # print('O won diagonally')
                    o_won()

                    break
                elif lst2[0][2] == lst2[1][1] == lst2[2][0] == True:
                    # print('O won reverse diagonally ')
                    o_won()

                    break
            c += 1

    b1 = tk.Button(height=10, width=17, master=fr, background='#000000', command=lambda: start(1, b1, 0, 0))
    b2 = tk.Button(height=10, width=17, master=fr, background='#000000', command=lambda: start(2, b2, 0, 1))
    b3 = tk.Button(height=10, width=17, master=fr, background='#000000', command=lambda: start(3, b3, 0, 2))
    b4 = tk.Button(height=10, width=17, master=fr, background='#000000', command=lambda: start(4, b4, 1, 0))
    b5 = tk.Button(height=10, width=17, master=fr, background='#000000', command=lambda: start(5, b5, 1, 1))
    b6 = tk.Button(height=10, width=17, master=fr, background='#000000', command=lambda: start(6, b6, 1, 2))
    b7 = tk.Button(height=10, width=17, master=fr, background='#000000', command=lambda: start(7, b7, 2, 0))
    b8 = tk.Button(height=10, width=17, master=fr, background='#000000', command=lambda: start(8, b8, 2, 1))
    b9 = tk.Button(height=10, width=17, master=fr, background='#000000', command=lambda: start(9, b9, 2, 2))

    b1.grid(row=0, column=0)
    b2.grid(row=0, column=1)
    b3.grid(row=0, column=2)
    b4.grid(row=1, column=0)
    b5.grid(row=1, column=1)
    b6.grid(row=1, column=2)
    b7.grid(row=2, column=0)
    b8.grid(row=2, column=1)
    b9.grid(row=2, column=2)
    window.mainloop()


win2 = tk.Tk()
win2.resizable(False, False)


def game_start():
    global win2

    startmain()


def score():
    global fr2
    global lb_scorex
    global lb_scoreo
    win2.geometry('410x355')
    fontStyle2 = tkFont.Font(family="Hero", size=50)
    fr2 = tk.Frame(background='#000000', master=win2)
    fr2.grid(row=0, column=0)
    lb_title = tk.Label(width=10, text='Tic-Tac-Toe', font=fontStyle2, master=fr2, background='#000000',
                        fg='pink')
    lb_title.grid(row=0, column=0, columnspan=4)
    lb = tk.Label(text='X', font=fontStyle2, fg='white', master=fr2, background='#000000', height=2)
    lb2 = tk.Label(text='O', font=fontStyle2, fg='white', master=fr2, background='#000000')
    lb.grid(row=1, column=0)
    lb2.grid(row=1, column=3)

    lb_scorex = tk.Label(text=scorex, font=fontStyle2, fg='light blue', master=fr2, background='#000000')
    lb_scoreo = tk.Label(text=scoreo, font=fontStyle2, fg='light blue', master=fr2, background='#000000')
    lb_scorex.grid(row=2, column=0)
    lb_scoreo.grid(row=2, column=3)
    but_start = tk.Button(width=8, fg='white', bg='#000000', text='START', font=tkFont.Font(family="Hero", size=25),
                          master=fr2, command=lambda: game_start())
    but_start.grid(row=4, column=1)

    win2.mainloop()


score()
