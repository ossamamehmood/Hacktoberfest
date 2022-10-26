# Prénom : Emmanuel
# Nom : Diatta
# Second Degree equation solving
from math import sqrt


def find_delta(a, b, c):

    return b**2 - (4 * a * c)


def equation_2deg_solve(a, b, c):

    delta = find_delta(a, b, c)

    print("delta = " + str(delta))

    # Two imaginary roots x1,x2
    if delta < 0:
        abs_delta = abs(delta)
        x1 = complex(-b, -sqrt(abs_delta)) / (2 * a)
        x2 = complex(-b, sqrt(abs_delta)) / (2 * a)

        print(
            "Given equation has two imaginary roots: \n x1 = "
            + str(x1)
            + ", x2 = "
            + str(x2)
        )

    # Only one root x0
    if delta == 0:
        x0 = -b / (2 * a)
        print("Given equation has only one root: \n x0 = " + str(round(x0, 5)))

    # Two distinct real roots x1,x2
    if delta > 0:
        x1 = -b - sqrt(delta) / (2 * a)
        x2 = -b + sqrt(delta) / (2 * a)

        print(
            "Given equation has two distinct real roots: \n x1 = "
            + str(round(x1, 5))
            + ", x2 = "
            + str(round(x2, 5))
        )


# Exec
a = float(input("Enter 1st term: "))
b = float(input("Enter 2e term: "))
c = float(input("Enter 3e term: "))

equation_2deg_solve(a, b, c)
