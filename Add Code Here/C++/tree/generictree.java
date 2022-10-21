import java.util.ArrayList;
import java.util.Stack;

public class generictree{
public static void main(String[] args)
{
    int[] arr={10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 100, -1, 110, -1, -1, 90, -1, -1, 40, 120, 140, -1, 150, -1, -1, -1,-1};
       Node root=create(arr);
       display(root);
       System.out.println(height(root));
      System.out.println(find(root,1101));
      ArrayList<Node> path=new ArrayList<>();
      findpath(root,110,path);
      for(Node p: path)
      {
        System.out.println( p.data); 
      }
} 
public static class Node
{
    int data;
    ArrayList<Node> child=new ArrayList<>();

    Node(int data)
    {
        this.data=data;
    }
    Node(){};
}
public static Node create(int[] arr)
{
    Stack<Node> stack=new Stack<>();
      
    for(int i=0;i<arr.length-1;i++)
    {
        if(arr[i]!=-1)
        {
            Node n=new Node(arr[i]);
            stack.push(n);

        }
        else
        {
            Node n=stack.pop();
             stack.peek().child.add(n);
        }
    }
    return stack.peek();
}

public static void preorder(Node node)
{
   System.out.print(node.data + "");

   for(Node ch: node.child)
   preorder(ch);
}

public static void display(Node node)
{
    String str="";
    str+=node.data+"->";

    for(Node ch: node.child)
      str+=ch.data+" ";

      System.out.println(str);

      for(Node ch: node.child)
      display(ch);
}


public static int  height(Node node)
{
    int h=0;
    for(Node ch: node.child)
    {
        h=Math.max(h,height(ch));

    }
    return h+1;
}
public static boolean find(Node node, int val)
{
    if(node.data== val)
    {
        return true;
    }
    boolean res=false;
     
     for(Node ch: node.child)
       {res=res||find(ch,val);
       }

       return res;
}

public static boolean findpath(Node node,int val,ArrayList<Node> path)
{
      if(node.data== val)
    {
        path.add(node);
        return true;
    }
    boolean res=false;

    path.add(node);

    for(Node ch : node.child)
    {
        res=res|| findpath(ch,val,path);
        if(!res)
        path.remove(path.size()-1);
    }

    return res;
}

public static 
}