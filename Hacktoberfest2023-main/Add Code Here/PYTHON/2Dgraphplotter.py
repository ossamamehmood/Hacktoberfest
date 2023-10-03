import matplotlib.pyplot as plt
from tkinter import Tk, Entry, Label, Button

class GraphPlotter:
    def __init__(self, master):
        self.master = master
        master.title("Graph Plotter")
        master.geometry("500x400")  # Set the dimensions of the window

        # Font size for labels and entries
        font_size = 14

        self.x_coordinates = []
        self.y_coordinates = []

        self.x_label = Label(master, text="Enter x-coordinate:", font=("Arial", font_size))
        self.x_label.pack()

        self.x_entry = Entry(master, font=("Arial", font_size))
        self.x_entry.pack()

        self.y_label = Label(master, text="Enter y-coordinate:", font=("Arial", font_size))
        self.y_label.pack()

        self.y_entry = Entry(master, font=("Arial", font_size))
        self.y_entry.pack()

        self.plot_button = Button(master, text="Plot", command=self.plot_graph, font=("Arial", font_size))
        self.plot_button.pack()

        self.quit_button = Button(master, text="Quit", command=master.quit, font=("Arial", font_size))
        self.quit_button.pack()

    def plot_graph(self):
        x_input = self.x_entry.get()
        y_input = self.y_entry.get()

        try:
            x_value = float(x_input)
            y_value = float(y_input)
            self.x_coordinates.append(x_value)
            self.y_coordinates.append(y_value)

            self.x_entry.delete(0, 'end')
            self.y_entry.delete(0, 'end')
        except ValueError:
            print("Invalid input. Please enter valid numbers.")

        plt.plot(self.x_coordinates, self.y_coordinates, marker='o')
        plt.xlabel('X-axis', fontsize=14)
        plt.ylabel('Y-axis', fontsize=14)
        plt.title('Graph Plot', fontsize=16)
        plt.grid(True)
        plt.show()

if __name__ == '__main__':
    root = Tk()
    graph_plotter = GraphPlotter(root)
    root.mainloop()
