#include <iostream>
#include <regex>
#include <string>

bool validateEmail(const std::string& email) {
    // Regular expression for validating an Email
    std::regex emailRegex(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");
    return std::regex_match(email, emailRegex);
}

bool validatePassword(const std::string& password) {
    // Password should be at least 8 characters long
    return password.length() >= 8;
}

std::string sanitizeString(std::string input) {
    // Simple sanitization: Replace special characters with '_'
    for (char& c : input) {
        if (!isalnum(c)) {
            c = '_';
        }
    }
    return input;
}

int main() {
    std::string name, email, password;

    // Get user input
    std::cout << "Enter your name: ";
    std::getline(std::cin, name);
    std::cout << "Enter your email: ";
    std::getline(std::cin, email);
    std::cout << "Enter your password: ";
    std::getline(std::cin, password);

    // Validate and sanitize user input
    if (validateEmail(email) && validatePassword(password)) {
        // Sanitize name
        std::string sanitizedName = sanitizeString(name);
        std::cout << "Name: " << sanitizedName << std::endl;
        std::cout << "Email: " << email << std::endl;
        std::cout << "Password: ********" << std::endl;
        std::cout << "Registration successful!" << std::endl;
    } else {
        std::cout << "Invalid email or password. Please try again." << std::endl;
    }

    return 0;
}
