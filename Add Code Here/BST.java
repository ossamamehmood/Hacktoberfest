/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package binary_search_tree;

/**
 *
 * @author ossamamehmood
 */

import java.util.Scanner;

class node
{
    int info;
    node lchild;
    node rchild;
}

class Binary {

    node root=null,parent=null,location=null;
    
void find(int item)
{
	node ptr, ptrsave;
	
	if(root==null)
	{
		location = null;
		parent = null;
		return;
	}
	if(item==root.info)
	{
		location = root;
		parent = null;
		 return;
	}
	if(item<root.info)	ptr=root.lchild;
	else ptr=root.rchild;
	ptrsave=root;

	while(ptr!=null)
	{
		if(item==ptr.info)
		{
			location = ptr;
			parent = ptrsave;
			return;
		}
		ptrsave=ptr;
		if(item<ptr.info)	ptr=ptr.lchild;
		else ptr=ptr.rchild;
	}
location=null;
parent=ptrsave;

}
void insert(int item)
{
	node tmp;
                //,parent=new node(), location=new node();
	
        find(item);
        
	if(root!=null && location!=null  )
	{
            System.out.println("Item already present");
            return;
	}
	tmp=new node();
	tmp.info=item;
	tmp.lchild=null;
	tmp.rchild=null;

	if(parent==null)	
        { root=tmp;
        
        }
	else if(item<parent.info)
        {parent.lchild=tmp;

        }else
        {parent.rchild=tmp;
        }
 }
}
public class BST {
  
    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        int choice, num;
	Binary o=new Binary();
     
	while(true)
	{
		System.out.println("1.Insert");
                System.out.println("2.Quit");
                System.out.println("Enter your choice :");
		choice=in.nextInt();
		
		switch(choice)
		{
			case 1:
                            System.out.println("Enter the number to be inserted");
				num=in.nextInt();
				o.insert(num);
				break;
			case 2:
				return;
			default:
                            System.out.println("Wrong choice");
				}
        }
    }
}