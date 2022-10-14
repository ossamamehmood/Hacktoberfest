/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

struct Node *head;

void
Insert (int data)
{
  struct Node *temp = (struct Node *) malloc (sizeof (struct Node *));


  temp->data = data;
  temp->next = NULL;

  if (head == NULL)
    {
      head = temp;
      return;
    }

  struct Node *temp2 = head;
  while (temp2->next != NULL)
    {
      temp2 = temp2->next;
    }
  temp2->next = temp;
}

void
Print ()
{
  struct Node *temp = head;
  while (temp != NULL)
    {
      printf (" %d", temp->data);
      temp = temp->next;
    }
  printf ("\n");

}


int
main ()
{
  head = NULL;
  Insert (4);
  Insert (6);
  Insert (8);
  Insert (2);
  Print ();

  return 0;
}
