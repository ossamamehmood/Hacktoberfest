from math import sqrt


def calc():
    print('Calculate the quadratic equation (ax² + bx + c = 0)')

    numbers = []
    for i in range(3):
        aux = True
        while aux:
            try:
                letter = 'A' if i == 0 else 'B' if i == 1 else 'C' if i == 2 else ''
                num = int(input(f'Type the {letter} number: '))
                numbers.append(num)
                aux = False
            except ValueError:
                print('Type a number!!')
                aux = True

    a = numbers[0]
    b = numbers[1]
    c = numbers[2]

    delta_value = pow(b, 2) - 4 * a * c

    if delta_value < 0:
        print('Delta is less than 0! It is not possible done the equation.')
        return
    elif delta_value == 0:
        print('Delta is 0! It is not possible done the equation.')
        return

    bhaskara_x1 = (0 - b) + sqrt(delta_value) / 2 * a
    bhaskara_x2 = (0 - b) - sqrt(delta_value) / 2 * a

    print('')
    print(f'Delta = {b}² - 4 . {a} . {c}')
    print(f'Bhaskara X1 = -{b} + √{delta_value} / 2 . {a}')
    print(f'Bhaskara X2 = -{b} - √{delta_value} / 2 . {a}\n')
    print(f'X1 = {bhaskara_x1}')
    print(f'X2 = {bhaskara_x2}')


if __name__ == '__main__':
    calc()
