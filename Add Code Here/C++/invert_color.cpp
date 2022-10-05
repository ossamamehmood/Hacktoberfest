#include <iostream>
#include <vector>

std::vector<int> invert_color(std::vector<int> rgb) {
    std::vector<int> inverted_rgb;
    for (int i = 0; i < rgb.size(); i++) {
        inverted_rgb.push_back(255 - rgb[i]);
    }
    return inverted_rgb;
}



int main(int argc, char const *argv[])
{
    //                        R    G    B
    std::vector<int> color = {17, 121, 130};
    std::cout << "Original color: " << color[0] << ", " << color[1] << ", " << color[2] << std::endl;

    // Invert colors
    std::vector<int> inverted_color = invert_color(color);
    std::cout << "Inverted color: " << inverted_color[0] << ", " << inverted_color[1] << ", " << inverted_color[2] << std::endl;

    return 0;
}
