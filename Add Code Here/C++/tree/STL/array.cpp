#include<iostream>
#include<array>

int main(){

    // initialising a regular array
    int regularArray [] = {}; // all elements = 0

    // initializing STL aray
    std::array<int, 5> stlArray {10, 20 ,30, 40};
    std::cout << "Memory occupied by the array --> "<< sizeof(stlArray) << " bytes." << std::endl; // 5 elements * 4 bytes of int ==> 20 

    int size = stlArray.size(); // give the number of elements of the array i.e LENGTH of Array
    // std::cout << size << std::endl;
    
    // MAX SIZE
    std::cout << "Max Size that array can hold " << stlArray.max_size() << std::endl;

    // ELEMENT ACCESS
    std::cout << "Element at index 1 --> " << stlArray.at(1) << std::endl;

    // GET FIRST ELEMENT
    std::cout << "First element --> " << stlArray.front() << std::endl;

    // GET LAST ELEMENT
    std::cout << "Last element --> " << stlArray.back() << std::endl;
       
    
    
    std::cin.get();
    return 0;
}