#include <iostream>

class Vector
{
private:
    int x, y, z;
    bool isRow;

public:
    Vector(int x = 0, int y = 0, int z = 0, bool isRow = 0) : x(x), y(y), z(z), isRow(isRow) {}

    int getX() { return x; }
    int getY() { return y; }
    int getZ() { return z; }
    bool checkRow() { return isRow; }

    friend std::istream &operator>>(std::istream &, Vector &);
    friend std::ostream &operator<<(std::ostream &, const Vector &);

    Vector operator+=(const Vector &);
};

Vector operator+(Vector &u1, Vector &u2)
{
    if (u1.checkRow() == u2.checkRow())
    {
        int x, y, z;

        x = u1.getX() + u2.getX();
        y = u1.getY() + u2.getY();
        z = u1.getZ() + u2.getZ();

        return Vector(x, y, z);
    }
    else
    {
        std::cout << "The vectors are of different types so addition is not possible. The result is default to [0 0 0].\n";
        return Vector(0, 0, 0);
    }
}

Vector operator-(Vector &u1, Vector &u2)
{
    if (u1.checkRow() == u2.checkRow())
    {
        int x, y, z;

        x = u1.getX() - u2.getX();
        y = u1.getY() - u2.getY();
        z = u1.getZ() - u2.getZ();

        return Vector(x, y, z);
    }
    else
    {
        std::cout << "The vectors are of different types so substraction is not possible. The result is default to [0 0 0].\n";
        return Vector(0, 0, 0);
    }
}

Vector operator*(Vector &u1, Vector &u2)
{
    if (u1.checkRow() != u2.checkRow())
    {
        int x, y, z;

        x = u1.getX() * u2.getX();
        y = u1.getY() * u2.getY();
        z = u1.getZ() * u2.getZ();

        return Vector(x, y, z);
    }
    else
    {
        std::cout << "The vectors are of same type so multiplication is not possible. The result is default to [0 0 0].\n";
        return Vector(0, 0, 0);
    }
}

std::istream &operator>>(std::istream &inputStream, Vector &u)
{
    return inputStream >> u.x >> u.y >> u.z >> u.isRow;
}

std::ostream &operator<<(std::ostream &outputStream, const Vector &u)
{
    return outputStream << "[" << u.x << " " << u.y << " " << u.z << "]";
}

Vector Vector::operator+=(const Vector &u)
{
    if (this->isRow == u.isRow)
    {
        this->x += u.x;
        this->y += u.y;
        this->z += u.z;
        return *this;
    }
    else
    {
        std::cout << "Since the vectors are of different type, the operation is not possible. The result is default to " << *this << std::endl;
        return *this;
    }
}

bool operator==(Vector &u1, Vector &u2)
{
    if (u1.getX() == u2.getX() && u1.getY() == u2.getY() && u1.getZ() == u2.getZ() && u1.checkRow() == u2.checkRow())
        return true;
    else
        return false;
}

bool operator>(Vector &u1, Vector &u2)
{
    if (u1.getX() > u2.getX() && u1.getY() > u2.getY() && u1.getZ() > u2.getZ() && u1.checkRow() == u2.checkRow())
        return true;
    else
        return false;
}

int main()
{
    Vector v1, v2;
    std::cout << "Enter vectors in the format [x y z 0/1], put 0 for row and 1 for column vector.\n";
    std::cout << "Enter vector 1: ";
    std::cin >> v1;
    std::cout << "Enter vector 2: ";
    std::cin >> v2;

    Vector v3, v4, v5;

    v3 = v1 + v2;
    std::cout << "Sum of vectors is: " << v3 << std::endl;

    v4 = v1 - v2;
    std::cout << "Difference of vectors is: " << v4 << std::endl;

    v5 = v1 * v2;
    std::cout << "Product of vectors is: " << v5 << std::endl;

    Vector v6(1, 0, -1);
    std::cout << "Using += operator on " << v6 << " and " << v1 << std::endl;
    
    v6 += v1;
    std::cout << v6 << std::endl;

    if (v1 == v2)
        std::cout << "Vector 1 is equal to vector 2." << std::endl;
    else
        std::cout << "Vector 1 is not equal to vector 2." << std::endl;

    if (v1 > v2)
        std::cout << "Vector 1 is greater than vector 2." << std::endl;
    else
        std::cout << "Vecotr 1 is not greater than vector 2." << std::endl;
}

