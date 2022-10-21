//animals.cpp: Rishabh Dev
//Description: Computes combinations of animals under constrainsts.

#include <iostream>

using namespace std;

int main(){
    for(int horses = 0; horses < 100; horses++)
        for(int pigs = 0; pigs < 100; pigs++)
            for(int rabbits = 0; rabbits < 100; rabbits ++)
                if(horses +  pigs + rabbits == 100)
                    if(((10 * horses) +  (3 * pigs) + (0.5 * rabbits)) == 100)
                        cout << "Found one! " << horses << " horses " << pigs << " pigs " << rabbits << " rabbits." << endl;

    return 0;
}