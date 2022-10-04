import java.util.Scanner;

public class ATM_Transaction{
	public static void main(String[] args){
		int balance = 999999;
		int password = 7895, choose_no,withdraw, deposit;
		
		Scanner s = new Scanner(System.in);
		
		System.out.print("Please enter your password: ");
		int check_pw = s.nextInt();
		
		if(check_pw == 7895){
			while(true){
				System.out.println("-------Automated Teller Machine-------");
				System.out.println("        Type 1 - Check Balance         ");
				System.out.println("        Type 2 - Withdraw Money         ");
				System.out.println("        Type 3 - Deposit Money        ");
				System.out.println("        Type 4 - EXIT         ");
				System.out.print("Choose the operation you want: ");
				choose_no = s.nextInt();
				
				switch(choose_no){
					case 1: System.out.println("Your current balance is: "+balance);
							break;
					case 2: System.out.println("Enter the withdrawl money amount: ");
							withdraw = s.nextInt();
							if(balance >= withdraw){
								balance = balance-withdraw;
								System.out.println("Please collect your money");
							}
							else{
								System.out.println("Insufficient Balance");
							}
							break;
					case 3: System.out.println("Enter the deposit money amount: ");
							withdraw = s.nextInt();
							balance = balance + withdraw;
							System.out.println("Your money has been successfully deposited");
							break;
					case 4: System.exit(0);		
				}
			}
		}
		else{
			System.out.println("Incorrect Password");
		}
	}
}