from fractions import Fraction


class Rational:
    def __init__(self, num=1, denum=1):
        if denum == 0:
            raise ZeroDivisionError()
        if not isinstance(num, int) or not isinstance(denum, int):
            raise TypeError()
        self.num = num
        self.denum = denum

    def drib(self):
        return f'{Fraction(self.num, self.denum)}'

    def ration(self):
        return f'{self.num / self.denum}'

    def __str__(self):
        return f'{self.num}/{self.denum}'

    def __truediv__(first, second):
        return Rational(first.num * second.denum, first.num * second.denum)

    def __sub__(first, second):
        return Rational(first.num * second.denum - first.denum * second.num, first.denum * second.denum)

    def __add__(first, second):
        return Rational(first.num * second.denum + first.denum * second.num, first.denum * second.denum)

    def __mul__(first, second):
        return Rational(first.num * second.num, first.denum * second.denum)


try:
    first = Rational(3, 8)
    second = Rational(denum=4)
except ZeroDivisionError:
    print("Denumerator mustn't be 0")
except TypeError:
    print('Numerator and denumerator must be integers')

print(f'Fraction: first = {first.drib()} second = {second.drib()}')
print(f'Ration: first = {first.ration()} second = {second.ration()}')
print(first+second)
print(first-second)
print(first*second)
print(first/second)
