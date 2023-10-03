#include <iostream>
#include <vector>
#include <string>
#include <ctime>

struct PullRequest {
    std::string name;
    std::string domain;
    std::string language;
    std::string date;

    PullRequest(const std::string& n, const std::string& d, const std::string& l)
        : name(n), domain(d), language(l) {
        std::time_t now = std::time(nullptr);
        date = std::asctime(std::localtime(&now));
    }
};

int main() {
    std::vector<PullRequest> pullRequests;
    char addAnother;

    do {
        std::string name, domain, language;

        std::cout << "Enter the name of the contributor: ";
        std::cin >> name;

        std::cout << "Enter the domain of the project: ";
        std::cin >> domain;

        std::cout << "Enter the programming language used: ";
        std::cin >> language;

        pullRequests.push_back(PullRequest(name, domain, language));

        std::cout << "Pull request added successfully.\n";
        std::cout << "Do you want to add another pull request? (y/n): ";
        std::cin >> addAnother;
    } while (addAnother == 'y' || addAnother == 'Y');

    std::cout << "\nPull Requests:\n";
    for (const PullRequest& pr : pullRequests) {
        std::cout << "Name: " << pr.name << "\n";
        std::cout << "Domain: " << pr.domain << "\n";
        std::cout << "Language: " << pr.language << "\n";
        std::cout << "Date: " << pr.date << "\n";
        std::cout << "------------------------\n";
    }

    return 0;
}
