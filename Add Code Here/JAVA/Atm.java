20.	import java.util.Scanner;  
21.	public class Atm
22.	{  
23.	     public static void main(String args[] )  
24.	    {  
25.	              int balance = 100000, withdraw, deposit;  
26.	          
27.	            Scanner sc = new Scanner(System.in);  
28.	          
29.	        while(true)  
30.	        {  
31.	            System.out.println("Automated Teller Machine");  
32.	            System.out.println("Choose 1 for Withdraw");  
33.	            System.out.println("Choose 2 for Deposit");  
34.	            System.out.println("Choose 3 for Check Balance");  
35.	            System.out.println("Choose 4 for EXIT");  
36.	            System.out.print("Choose the operation you want to perform:");  
37.	              
38.	                     int choice = sc.nextInt();  
39.	            switch(choice)  
40.	            {  
41.	                case 1:  
42.	        System.out.print("Enter money to be withdrawn:");  
43.	                      
44.	              withdraw = sc.nextInt();           
45.	        if(balance >= withdraw)  
46.	        {  
47.	                   balance = balance - withdraw;  
48.	            System.out.println("Please collect your money");  
49.	        }  
50.	        else  
51.	        {  
52.	                      System.out.println("Insufficient Balance");  
53.	        }  
54.	        System.out.println("");  
55.	        break;  
56.	   
57.	                case 2:  
58.	                      
59.	        System.out.print("Enter money to be deposited:");  
60.	                      
61.	             deposit = sc.nextInt();  
62.	                      
63.	               balance = balance + deposit;  
64.	        System.out.println("Your Money has been successfully depsited");  
65.	        System.out.println("");  
66.	        break;  
67.	   
68.	                case 3:   
69.	        System.out.println("Balance : "+balance);  
70.	        System.out.println("");  
71.	        break;  
72.	   
73.	                case 4:  
74.	        System.exit(0);  
75.	            }  
76.	        }  
77.	    }  
78.	}  
