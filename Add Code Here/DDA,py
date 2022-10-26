# Digital Differential Line Drawing Algorithm
from matplotlib import pyplot as plt


def DDA(x1, y1, x2, y2):
    dx = x2 - x1
    dy = y2 - y1
    if abs(dx) > abs(dy):
        step = abs(dx)
    else:
        step = abs(dy)
    xinc = dx / step
    yinc = dy / step

    x, y = x1, y1
    # Make a list for co-ordinates
    x_coordinates = [x]
    y_coordinates = [y]

    for i in range(step):
        x = x + xinc
        y = y + yinc
        print(i, x, y)
        x_coordinates.append(round(x))
        y_coordinates.append(round(y))

    # Plot the line with coordinates list
    plt.plot(
        x_coordinates,
        y_coordinates,
        marker="o",
        linestyle="dotted",
        markersize=10,
        markerfacecolor="red",
    )
    plt.show()


if __name__ == "__main__":
    fig, ax = plt.subplots()
    ax.grid()
    ax.xaxis.tick_top()
    ax.invert_yaxis()
    DDA(5, 10, 1, 7)