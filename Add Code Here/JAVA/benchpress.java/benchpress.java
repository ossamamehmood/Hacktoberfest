/* package codechef; // don't place package name! */



import java.util.*;

import java.lang.*;

import java.io.*;



/* Name of the class has to be "Main" only if the class is public. */

class Codechef

{

	public static void main (String[] args) throws java.lang.Exception

	{

		// your code goes here

		Scanner sc=new Scanner(System.in);

		int t=0;

		t=sc.nextInt();

		while(t>0)

		{

		    int n=sc.nextInt();

		    long a[]=new long[n];

		    

		    long maxw=sc.nextLong();

		    long rod=sc.nextLong();

		    

		    for(int i=0;i<n;i++)

		    {

		        a[i]=sc.nextLong();

		    }

		    

		    HashMap<Long,Integer>map=new HashMap<>();

		     for(int i=0;i<n;i++)

		    {

		        map.put(a[i],map.getOrDefault(a[i],0)+1);

		    }

		    long ans=rod;

		    if(ans>=maxw)

		    System.out.println("YES");

		    else{

		     Set<Long> keys =map.keySet();

            for(Long key:keys)

            {

		        if(map.get(key)>1)

		        {

		            if(map.get(key)%2==0)

		            {

		                ans+=map.get(key)*key;

		                

		            }

		            else

		            {

		                 ans+=(map.get(key)-1)*key;

		                

		            }

		        }

		    }

		    if(ans>=maxw)

		    System.out.println("YES");

		    else

		    System.out.println("NO");

		    }

		    

		    t--;

		}

	}

}

