#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <random>
#include <algorithm>

#define watch(x) std::cout << (#x) << " is " << (x) << std::endl

template <typename T>
void printVector(std::vector<T> vec)
{
    auto itr = vec.begin();
    std::cout << "vec < ";
    for (itr = vec.begin(); itr != vec.end(); itr++)
    {
        std::cout << *itr << " ";
    }
    std::cout << ">";
    std::cout << "\n";
}

template <typename Type1, typename Type2>
void printMap(std::unordered_map<Type1, Type2> map)
{
    auto itr = map.begin();
    for (itr = map.begin(); itr != map.end(); ++itr)
    {
        std::cout << itr->first << " ---> " << itr->second << '\n';
    }
}

bool solveRiddle(const std::unordered_map<long long int, long long int> &ump)
{

    bool foundNumber = false;
    long long int no_of_prisoners = ump.size();
    long long int max_steps = (no_of_prisoners * 0.50);
    long long int ptr = 1;
    long long int steps = 1;

    for (size_t i = 1; i <= no_of_prisoners; i++)
    {
        ptr = i;
        steps = 1;

        while (ump.at(ptr) != i)
        {
            ptr = ump.at(ptr);

            steps++;
        }

        if (steps > max_steps)
            return false;
    }

    return true;
}

int main()
{

    long long int no_of_prisoners = 100;

    std::vector<long long int> vec(no_of_prisoners);
    std::unordered_map<long long int, long long int> ump;

    for (size_t i = 1; i <= vec.size(); i++)
    {
        vec.at(i - 1) = i;
    }

    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(vec.begin(), vec.end(),g);
    for (size_t i = 1; i <= no_of_prisoners; i++)
    {
        ump[i] = vec.at(i - 1);
    }

    // printMap(ump);
    //std::cout << "\n\n";
    size_t testCases = 0;
    std::cout << "Input number of test cases : ";
    std::cin >> testCases;

    size_t test = testCases;
    size_t pass = 0;
    size_t fail = 0;
    double probabilityOfWinning = 0.0;

    while (test-- > 0)
    {
       std::shuffle(vec.begin(), vec.end(),g);

        for (size_t i = 1; i <= no_of_prisoners; i++)
        {
            ump.at(i) = vec.at(i - 1);
        }
        (solveRiddle(ump) == true) ? pass++ : fail++;
    }
    std::cout << "\n";
    watch(pass);
    watch(fail);
    probabilityOfWinning = pass / (testCases * 1.0);

    std::cout << "\n\nRESULTS:-\n\n";
    std::cout << "Probability Of Winning : " << probabilityOfWinning << "\n";
    std::cout << "Probability Of Losing : " << (1.0 - probabilityOfWinning) << "\n";

    return 0;
}
