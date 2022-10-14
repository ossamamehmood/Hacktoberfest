Finding Intersection of two linked list:

1. Calculate the length of both ll as L1 and L2
2. Calculate the difference 
3. Move d Nodes in longer Linkedlist;
4. then move by one both linked if it become equal then that is the intersection point.


SECOND APPROUCH FOR FINDING INTERSECTION
USING STACK

1. Push the addresses in respective stacks;
2. Pop and compare till we find intersection
    a     if equal, strore in temporary variable
    b     if not equal the addresses in temporary variable are the 	
           intersection points.


Source Code:
-----------------------------------------------------------------------------------------

First of All create Node Class and then create 2 other functions

1. Find Length
2, Find Intersection

1. int find_length(node *start)
{
	int count = 0;
	node *p;
	p = start;
	while(p!=NULL)
	{
		count ++;
		p = p->next;
	}

return count;
}


---------------------------------Finding Intersection--------------------------

node *find_intersection(node *p , node *q)
{
	node *larger , *smaller;
	int m , n , d , count;
	m = find_length(p);   //calculate length
	n = find_length(q);
	
	d = m-n;  //find difference
	if(d < 0)  //find absolute value
	{
		d = d * -1;
	}
	
	if(m > n) //   find larger length linked list
		{
			larger = p;
			smaller = q;
		}
	else
		{
			larger = q;
			smaller = p;
		}
		
	count = 0;
	while(count < d)    // move d nodes in larger linked list
	{
		larger = larger->next;
		count++;
	}
	
	while(larger != smaller)   // then move one step each in both linked lists
	{
		larger = larger->next;
		smaller= smaller->next;
	}
	
	return larger;   // this is the intersection
	
}

--------------------------------------The Main Program--------------------------
int main()
{
	node *p , *q , *intersection;
	p = newNode(1);
	p->next = newNode(2);
	p->next->next = newNode(3);
	p->next->next->next = newNode(4);
	intersection = p->next->next->next;
	p->next->next->next->next = newNode(5);
	p->next->next->next->next->next = newNode(6);
	
	q = newNode(7);
	q->next = newNode(8);
	q->next->next = intersection;
	
	cout<<"The Intersection of nodes is<<find-intersection(q, p)->data;
return 0;
}





1 pass tow node as parameter in function
2 create four variables m n count larger and smaller
larger and smaller will be pointer variable
3 call the length pass two argument store the function in m and n.
4. find the difference d= m-n;
5 find absolute value
if d<0 d= d*-1;

6 find the larger linked list if m>n largerb=p else q

7.
		
	cnt = 0;
	while(cnt < d)    // move d nodes in larger linked list
	{
		larger = larger->next;
		cnt++;
	}
	
	while(larger != smaller)   // then move one step each in both linked lists
	{
		larger = larger->next;
		smaller= smaller->next;
	}
	
	return larger;   // this is the intersection
	

