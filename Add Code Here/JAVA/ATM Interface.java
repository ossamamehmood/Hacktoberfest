import java.util.*;  
  
class ATM
{  
    public static void main(String args[])  
    {  
        int balance = 50000, withdraw, deposit;  
          
        Scanner sc = new Scanner(System.in);  
          
        while(true)  
        {  
            System.out.println("ATM INTERFACE\n");  
            
            System.out.print("Choose 1 for Check Balance\t"); 
            System.out.print("2 for Withdraw\t");  
            System.out.print("3 for Deposit\t");  
            System.out.print("4 for Transfer\t"); 
            System.out.print("5 for Quit\n"); 
            System.out.println(""); 
            System.out.print("Choose the operation you want to perform: ");
              
            int choice = sc.nextInt();  
            switch(choice)  
            {  
                case 1:
                    System.out.println("Balance : " + balance);  
                    System.out.println("");  
                    break;
                
                case 2:  
                    System.out.print("How much Amount you want to withdraw:");  
                       
                     withdraw = sc.nextInt();  
                      
                    if(balance >= withdraw)  
                    {  
                        balance = balance - withdraw;  
                        System.out.println("Please, Collect your Amount!");  
                    }  
                    else  
                    {  
                        System.out.println("Sorry! Insufficient Balance!");  
                    }  
                    System.out.println("");  
                    break;  
   
                case 3:  
                      
                    System.out.print("Enter Amount to be deposited:");  
                      
                    deposit = sc.nextInt();  
                      
                    balance = balance + deposit;  
                    System.out.println("Your Amount has been deposited successfully!");  
                    System.out.println("");  
                    break;  
   
                case 4:  
                    System.out.println("Account Based Tranfer");
                    System.out.print("Enter Account Number : 4");
                    int account = sc.nextInt();
                    
                    System.out.print("Enter Amount : ");
                    int amount = sc.nextInt();
                    
                    if(amount > balance)
                        System.out.println("Oops! Balance is not sufficient!");
                    else {  
                        System.out.println("The Amount is tranferred successfully!");
                        balance = balance - amount;
                    }
                    System.out.println("");
                    break;  
   
                case 5:  
                    System.exit(0); 
                default:
                    System.out.println("Pick the right Option!");
            }
        }
        
    }  
}  
