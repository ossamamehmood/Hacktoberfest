#include <iostream>

struct Rectangle {
    int width;
    int height;
};

bool isValidRectangle(const Rectangle& rect) {
    return rect.width > 0 && rect.height > 0;
}

int main() {
    Rectangle rect1 = {4, 3};  // Valid rectangle
    Rectangle rect2 = {0, 5};  // Invalid rectangle (zero width)
    Rectangle rect3 = {7, -2}; // Invalid rectangle (negative height)

    if (isValidRectangle(rect1)) {
        std::cout << "Rectangle 1 is valid." << std::endl;
    } else {
        std::cout << "Rectangle 1 is not valid." << std::endl;
    }

    if (isValidRectangle(rect2)) {
        std::cout << "Rectangle 2 is valid." << std::endl;
    } else {
        std::cout << "Rectangle 2 is not valid." << std::endl;
    }

    if (isValidRectangle(rect3)) {
        std::cout << "Rectangle 3 is valid." << std::endl;
    } else {
        std::cout << "Rectangle 3 is not valid." << std::endl;
    }

    return 0;
}
