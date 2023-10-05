#include <deque>
#include <iostream>

using namespace std;

template<typename T>
void show(const char* msg, deque<T> q)
{
    cout << msg << endl;
    for(unsigned i=0; i<q.size(); i++)
        cout << q[i] << " ";
    cout << endl;
}


main()
{
    deque<int> dq(10);
    for(unsigned i=0; i<dq.size(); ++i)     dq[i] = i*i;
    show("Contents of dq: ", dq);

    int sum = 0;
    for(unsigned i=0;i<dq.size();++i)   sum += dq[i];
    double avg = sum / dq.size();
    cout << "The average of dq = " << avg << endl;

    for(unsigned i=0;i<dq.size();++i)   dq.pop_back();
    show("After poping dq contents are: ", dq);

    cout << "\n" << *dq.begin() << "\t" << *(dq.end()-1) << endl << endl;
    cout << "\n" << *dq.rbegin() << "\t" << *(dq.rend()-1) << endl << endl;

    cout << "\n\n";
    deque<int> dq2(dq.begin()+2, dq.end()-2);       // Keep only element 4
    dq2.push_front(3);                              // add 3 in the beginning
    dq2.push_back(5);                               // add 5 in the end 
    show("Contents of dq2 are: ", dq2);
}
