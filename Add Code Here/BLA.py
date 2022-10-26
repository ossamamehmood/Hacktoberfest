#Bresenham's Algorithm
from matplotlib import pyplot as plt


def bresenham(x1, y1, x2, y2):
    x, y = x1, y1
    dx = abs(x2 - x1)
    dy = abs(y2 - y1)
    xinc = 1 if (x2 > x1) else -1
    yinc = 1 if (y2 > y1) else -1
    x_coordinates = [x]
    y_coordinates = [y]
    print("k x y p")
    if dx > dy:
        p = 2 * dy - dx
        for i in range(dx):
            x = x + xinc
            if p < 0:
                p = p + 2 * dy
            else:
                p = p + 2 * dy - 2 * dx
                y = y + yinc
            print(i, x, y, p)
            x_coordinates.append(x)
            y_coordinates.append(y)
    else:
        p = 2 * dx - dy
        for i in range(dy):
            y = y + yinc
            if p < 0:
                p = p + 2 * dx
            else:
                p = p + 2 * dx - 2 * dy
                x = x + xinc
            print(i, x, y, p)
            x_coordinates.append(x)
            y_coordinates.append(y)

#Plot the line with coordinates list
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
    bresenham(2, 1, 8, 6)