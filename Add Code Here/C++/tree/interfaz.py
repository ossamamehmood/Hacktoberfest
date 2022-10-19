import tkinter as tk
import tkinter.font
from time import sleep
from abcdario import show_g, show_a, show_n, show_d, show_r, clean, leds_off, show_l, show_z, show_c, show_o, show_j, show_s


root = tk.Tk()
root.geometry("1200x800")
root.title("apellidos MATRIZ DE LEDS")
FUENTE_1 = tkinter.font.Font(family='helvetica', size=20, weight="bold")
FUENTE_2 = tkinter.font.Font(family='helvetica', size=12, weight="bold")
FUENTE_3 = tkinter.font.Font(family='helvetica', size=120, weight="bold")

integrantes = """
Andrés Alcaraz    ???
David Rojas       1017248534
Jorge Luis Granda 1042770436

Ingeniero Hernando Vanegas López
"""
label = tk.Label(text=integrantes, font=FUENTE_1, bg="#000000", fg="#F4845F")
label.pack(fill=tk.X)

granda = [show_g, show_r, show_a, show_n, show_d, show_a]


def btn_granda():
    apellido_granda = ['G', 'R', 'A', 'N', 'D', 'A', '']
    for i in range(len(apellido_granda)):
        lbl_resultado['text'] = apellido_granda[i]
        sleep(0.1)
        root.update_idletasks()
        granda[i]()
        leds_off()


alcaraz = [show_a, show_l, show_c, show_a, show_r, show_a, show_z]


def btn_alcaraz():
    apellido_alcaraz = ['A', 'L', 'C', 'A', 'R', 'A', 'Z', '']
    for i in range(len(apellido_alcaraz)):
        lbl_resultado['text'] = apellido_alcaraz[i]
        sleep(0.1)
        root.update_idletasks()
        alcaraz[i]()
        leds_off()


rojas = [show_r, show_o, show_j, show_a, show_s]


def btn_rojas():
    apellido_rojas = ['R', 'O', 'J', 'A', 'S', '']
    for i in range(len(apellido_rojas)):
        lbl_resultado['text'] = apellido_rojas[i]
        sleep(0.1)
        root.update_idletasks()
        rojas[i]()
        leds_off()


def generar():
    px = 50
    py = 220
    label = ['G', 'R', 'A', 'N', 'D', 'A', 'L', 'C', 'R', 'Z', 'O', 'J', 'S']
    letras_ind = [show_g, show_r, show_a, show_n, show_d, show_a,
                  show_l, show_c, show_r, show_z, show_o, show_j, show_s]
    apellidos = 'GRANDALCRZOJS'
    a = 0
    for letra in apellidos:
        label[a] = tk.Button(text=letra, font=FUENTE_2,
                             command=letras_ind[a], bd=5).place(x=px, y=py, height=70, width=70)
        px = px+100
        if a == 5:
            px = 50
            py = py+100
        elif a == 9:
            px = 50
            py = py+100
        a += 1


def chao_papa():
    root.quit()
    clean()


generar()

lbl_resultado = tk.Label(root, text="", font=FUENTE_3,
                         bg="#000000", fg="#F27059").place(x=850, y=200, height=400, width=400)
boton_granda = tk.Button(text="GRANDA", command=btn_granda, bd=4).place(
    x=850, y=610, height=60, width=70)
boton_alcaraz = tk.Button(text="ALCARAZ", command=btn_alcaraz, bd=4).place(
    x=950, y=610, height=60, width=90)
boton_rojas = tk.Button(text="ROJAS", command=btn_rojas, bd=4).place(
    x=1050, y=610, height=60, width=100)
boton_salir = tk.Button(text="Chao PAPÁ", command=chao_papa, bd=4).place(
    x=850, y=610, height=60, width=100)

root.mainloop()
