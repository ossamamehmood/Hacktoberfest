import java.util.*;
import java.lang.*;
import java.io.*;
class Element implements Comparable<Element>
{
    int value;
    int count;
    public Element(int value,int count)
    {
        this.value=value;
        this.count=count;
    }
    public int compareTo(Element e)
    {
        if(this.count>e.count)
        {
            return -1;
        }
        else if(this.count<e.count)
        {
            return 1;
        }
        else
        {
            if(this.value<e.value)
            {
                return -1;
            }
            else
            {
                return 1;
            }
        }
    }
}
class GFG {
    
	public static void main (String[] args) {
	    Scanner scanner = new Scanner(System.in);
	    int t=scanner.nextInt();
	    while(t>0)
	    {
	        int n = scanner.nextInt();
	        int array[] = new int[n];
	        for(int i=0;i<n;i++)
	        {
	            array[i] = scanner.nextInt();
	        }
	        HashMap<Integer,Integer> h = new HashMap<>();
	        for(int i=0;i<n;i++)
	        {
	            if(h.containsKey(array[i]))
	            {
	                h.put(array[i],h.get(array[i])+1);
	            }
	            else
	            {
	                h.put(array[i],1);
	            }
	        }
	        ArrayList<Element> list = new ArrayList<>();
	        for(int key:h.keySet())
	        {
	            int value = h.get(key);
	            list.add(new Element(key,value));
	        }
	        Collections.sort(list);
	        for(int i=0;i<list.size();i++)
	        {
	            int value = list.get(i).value;
	            int count = list.get(i).count;
	            for(int j=0;j<count;j++)
	            {
	                System.out.print(value+" ");
	            }
	            
	       
	            
	        }
	        System.out.println("");
	        
	        
	        t--;
	    }
	    
	}
}
