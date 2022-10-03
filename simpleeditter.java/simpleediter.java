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

        Scanner scanner = new Scanner(System.in);

        int queryNumber = scanner.nextInt();

        scanner.nextLine();

		StringBuffer sb = new StringBuffer();

		for(int i=0; i<queryNumber && scanner.hasNext(); i++){

		    String query = scanner.nextLine();

		    String[] queryArray = query.split(" ");

		    if(queryArray.length>2){

		        String operation = queryArray[0];

		        int startIndex = Integer.valueOf(queryArray[1]);

		        if("+".equals(operation)){

		            String subStr = queryArray[2];

		            sb.insert(startIndex, subStr);

		        }else if("?".equals(operation)){

		            int endIndex = Integer.valueOf(queryArray[2]);

		            System.out.println(sb.substring(startIndex-1, startIndex+endIndex-1));

		        }

		    }

		}        

	}

}

