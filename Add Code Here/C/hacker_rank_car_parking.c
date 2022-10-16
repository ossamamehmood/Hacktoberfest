/* A car parking system keeps track of cars entering and leaving the parking area. There is only one gate to enter and exit the parking. 
There are N cars entering at a time one after the other. In-charge of the car parking system allows all the cars to be parked. 
After one hour, 2 cars leave from the parking from same gate. In-charge also wants to know how many cars are parked. 
Later he noticed, one car was standing for more than 5 days, in-charge decided to inform the car owner. He notes the car number and finds out the owner name. 
The parking charge is Rs. 50 per day. Compute and display the Parking Charges of each car based on number of days parked. 
Also determine total parking charges of all cars. Help the in-charge of car parking system to perform these operations.
Input Format
First line – N is number of cars arriving at parking system.
Next N lines is car details.
Next 2 lines is Name of Car owners who leave the parking.
Last line is car number to find the car owner name.
INPUT DETAILS OF EACH CAR: CAR NUMBER, OWNER NAME, NUMBER OF DAYS OF PARKING.
Constraints
NIL
Output Format
Display details of all the cars along with parking charges of each car.
Display the remaining cars in the parking.
Display the car owner name.
Display the total parking charges of the car that were parked.
OUTPUT DETAILS OF EACH CAR: CAR NUMBER, OWNER NAME, NUMBER OF DAYS OF PARKING, PARKING CHARGE.
Sample Input 1
7
mh03cd4994 sohan 3
ka01m3322 bikram 4
dl4ccd1234 vicky 4
ka25m1111 rajkumar 7
ka25ab2222 rajesh 6
dl9q4d1234 Rocky 6
pb98c134 rakesh 2
sohan
rakesh
ka25ma9900
Sample Output 1
mh03cd4994 sohan 3 150
ka01m3322 bikram 4 200
dl4ccd1234 vicky 4 200
ka25m1111 rajkumar 7 350
ka25ab2222 rajesh 6 300
dl9q4d1234 Rocky 6 300
pb98c134 rakesh 2 100
ka01m3322 bikram 4 200
dl4ccd1234 vicky 4 200
ka25m1111 rajkumar 7 350
ka25ab2222 rajesh 6 300
dl9q4d1234 Rocky 6 300
Car not found in parking.
Total Car Parking charges = Rs. 1600
COde:   */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
struct node
{
    char car_no[30],name[30];
    int days,ch;
    struct node *rl;
    struct node *ll;
};
struct node * create_node();
struct node * insert_end(struct node * head);
void display(struct node * head);
struct node * search_delete(struct node * head);
void search(struct node * head);
int charge(struct node * head);
struct node *cur;
struct node *prev;
int main()
{
    struct node * head=NULL;
    int n,i,sum=0;
    scanf("%d",&n);
    if(n>0)
    {
        for(i=0;i<n;i++)
        {
            head=insert_end(head);
        }
        display(head);
        sum=charge(head);
        printf("\n");
        for(i=0;i<2;i++) { 
          head=search_delete(head); } 
      display(head); 
      search(head);
      printf("Total Car Parking charges = Rs. %d",sum); } 
  return 0; } 
struct node * create_node() { 
  struct node *newnode;
  newnode=(struct node *)malloc(sizeof(struct node));
  if(newnode==NULL) { 
    printf("NO memory allocated"); } 
  scanf("%s %s %d",newnode->car_no,newnode->name,&newnode->days);
   newnode->ch=newnode->days*50;
   newnode->rl=NULL;
   newnode->ll=NULL;
   return newnode;
}
struct node * insert_end(struct node * head)
{
    struct node * newnode;
    newnode=create_node();
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        cur=head;
        while(cur->rl!=NULL)
        {
            cur=cur->rl;
        }
        newnode->ll=cur;
        cur->rl=newnode;
    }
    return head;
}
void display(struct node * head)
{
    cur=head;
    while(cur!=NULL)
    {
        printf("%s %s %d %d\n",cur->car_no,cur->name,cur->days,cur->ch);
        cur=cur->rl;
    }
}
struct node * search_delete(struct node * head)
{
    int status=0;
    char key[30];
    struct node * temp;
    struct node * prev=NULL;
    scanf("%s",key);
    if(strcmp(head->name,key)==0)
    {
        temp=head;
        head=head->rl;
        head->ll=NULL;
        free(temp);
    }
    else
    {
        cur=head;
        while(cur!=NULL)
        {
            if(strcmp(cur->name,key)==0)
            {
                status=1;
                break;
            }
            prev=cur;
            cur=cur->rl;
        }
        if(status==1)
        {
            prev->rl=cur->rl;
            free(cur);
        }
    }
    return head;
}
void search(struct node * head)
{
    char key[30];
    int status=0;
    scanf("%s",key);
    cur=head;
    while(cur!=NULL)
    {
        if(strcmp(cur->car_no,key)==0)
        {
            status=1;
            break;
        }
        cur=cur->rl;
    }
    if(status==0)
    {
        printf("\nCar not found in parking.\n");
    }
    else if(status==1)
    {
        printf("Car found. Owner name is %s\n",cur->name);
    }
}
int charge(struct node * head)
{
    int sum=0;
    cur=head;
    while(cur!=NULL)
    {
        sum=sum+cur->ch;
        cur=cur->rl;
    }
    return sum;
}
