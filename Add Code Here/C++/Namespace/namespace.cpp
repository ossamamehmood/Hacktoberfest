#include <iostream>
using namespace std;
namespace first
{
void fun(){
    cout << "first";

}    
} // namespace fist

namespace second
{
    
void fun(){
    cout << "second";
}
} // namespace second
using namespace second;


int main(){
    fun();
    return 0;
}