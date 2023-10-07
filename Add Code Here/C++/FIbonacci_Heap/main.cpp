#include<iostream>
#include "fib_heap.hpp"
using namespace std;

// Driver function
int main(){

    heap h;
    initHeap(&h);
    int n, d, c, b;
    node *min;
    int potential;

    while(true){

        // Display menu
        cout << endl << "1. Insert" << endl;
        cout << "2. Extract min" << endl;
        cout << "3. Traverse" << endl;
        cout << "4. Decrease key" << endl;
        cout << "5. Display" << endl;
        cout << "6. Exit" << endl << endl;
        cout << "Enter your choice: ";
        cin >> n;
        cout << endl;

        potential = h.potential;

        switch(n){

            // Insert
            case 1:
                cout << endl <<"Heap : ";
                printHeap(h);
                cout << "Enter a number: ";
                cin >> d;
                while(cin.fail()){
                    cout << endl << "Enter valid input !" << endl << endl << "Try again: ";
                    cin.clear();
                    cin.ignore(256, '\n');
                    cin >> d;
                }
                insert(&h, d);
                cout << endl << d << " is inserted." << endl << endl;
                cout << "New heap : ";
                printHeap(h);
                cout << "Change in potential : " << h.potential - potential << endl << endl;
                break;


            // Extract min
            case 2:

                if(h.min){
                    cout << "Heap : ";
                    printHeap(h);
                    min = extractMin(&h);
                    cout <<  endl << "Min is extracted." << endl << endl;
                    printHeap(h);
                    cout << "Change in potential : "<< h.potential - potential << endl << endl;
                }
                else
                    cout << "Queue is empty."<< endl << endl;
                break;


            // Print heap
            case 3:

                printHeap(h);
                break;


            // Decrease key
            case 4:

                cout << endl <<"Heap : ";
                printHeap(h);

                cout << "Which key you want to decrease : ";
                cin >> c;
                while(cin.fail()){
                    cout << endl << "Enter valid input !" << endl << endl << "Try again: ";
                    cin.clear();
                    cin.ignore(256, '\n');
                    cin >> c;
                }
                cout << endl << "Enter new key : ";
                cin >> b;
                while(cin.fail()){
                    cout << endl<< "Enter valid input !" << endl << endl << "Try again: ";
                    cin.clear();
                    cin.ignore(256, '\n');
                    cin >> b;
                }

                if(findNode(h.min, c))
                    cout << "YES" << endl;

                decreaseKey(&h, findNode(h.min, c), b);
                cout << endl << "key decreased." << endl <<endl;
                cout << "New heap : ";
                printHeap(h);
                cout << "Change in potential : " << h.potential - potential << endl << endl;
                break;


            // Display
            case 5:
                display(h);
                break;


            // Exit
            case 6:
                exit(0);


            default:
                cout << "Enter valid choice." << endl << endl;
        }

    }

    return 0;
}
