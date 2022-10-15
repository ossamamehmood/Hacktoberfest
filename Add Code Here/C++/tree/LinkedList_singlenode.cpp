#include <iostream>
using namespace std;
struct node {
    int data;
    struct node *link;
};
int main()
{
    struct node *head=NULL;
    head->data=45;
    head->link=NULL;

    cout<<head->data<<endl;
    cout<<head->link<<endl;

    return 0;
}
