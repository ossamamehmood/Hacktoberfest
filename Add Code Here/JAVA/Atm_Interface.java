import java.util.Scanner;

class BankAccount {

    String name;
    String userName;
    String password;
    String accountNo;
    float balance = 100000f;
    int transactions = 0;
    String transactionHistory = "";

    public void register() {
        Scanner sc = new Scanner(System.in);
        System.out.print("\nEnter Your Name - ");
        this.name = sc.nextLine();
        System.out.print("\nEnter Your Username - ");
        this.userName = sc.nextLine();
        System.out.print("\nEnter Your Password - ");
        this.password = sc.nextLine();
        System.out.print("\nEnter Your Account Number - ");
        this.accountNo = sc.nextLine();
        System.out.println("\nRegistration completed..kindly login");
    }

    public boolean login() {
        Scanner sc = new Scanner(System.in);
        boolean isLogin = false;

        while (!isLogin) {
            System.out.print("\nEnter Your Username - ");
            String enteredUsername = sc.nextLine();

            if (enteredUsername.equals(userName)) {
                System.out.print("\nEnter Your Password - ");
                String enteredPassword = sc.nextLine();

                if (enteredPassword.equals(password)) {
                    System.out.print("\nLogin successful!!");
                    isLogin = true;
                } else {
                    System.out.println("\nIncorrect Password");
                }
            } else {
                System.out.println("\nUsername not found");
            }
        }

        return isLogin;
    }

    public void withdraw() {
        Scanner sc = new Scanner(System.in);
        System.out.print("\nEnter amount to withdraw - ");
        float amount = sc.nextFloat();

        try {
            if (balance >= amount) {
                transactions++;
                balance -= amount;
                System.out.println("\nWithdraw Successfully");
                String str = amount + " Rs Withdrawn\n";
                transactionHistory = transactionHistory.concat(str);
            } else {
                System.out.println("\nInsufficient Balance");
            }

        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    // Other methods remain unchanged...
}

public class AtmInterface {

    public static int takeIntegerInput(int limit) {
        int input = 0;
        boolean flag = false;

        while (!flag) {
            try {
                Scanner sc = new Scanner(System.in);
                input = sc.nextInt();

                if (input > limit || input < 1) {
                    System.out.println("Choose the number between 1 to " + limit);
                } else {
                    flag = true;
                }
            } catch (Exception e) {
                System.out.println("Enter only integer value");
            }
        }
        return input;
    }

    public static void main(String[] args) {
        System.out.println("\n**********WELCOME TO SBI ATM SYSTEM**********\n");
        System.out.println("1.Register \n2.Exit");
        System.out.print("Enter Your Choice - ");
        int choice = takeIntegerInput(2);

        if (choice == 1) {
            BankAccount b = new BankAccount();
            b.register();

            while (true) {
                System.out.println("\n1.Login \n2.Exit");
                System.out.print("Enter Your Choice - ");
                int ch = takeIntegerInput(2);

                if (ch == 1) {
                    if (b.login()) {
                        System.out.println("\n\n**********WELCOME BACK " + b.name + " **********\n");
                        boolean isFinished = false;

                        while (!isFinished) {
                            System.out.println(
                                    "\n1.Withdraw \n2.Deposit \n3.Transfer \n4.Check Balance \n5.Transaction History \n6.Exit");
                            System.out.print("\nEnter Your Choice - ");
                            int c = takeIntegerInput(6);

                            switch (c) {
                                case 1:
                                    b.withdraw();
                                    break;
                                case 2:
                                    b.deposit();
                                    break;
                                case 3:
                                    b.transfer();
                                    break;
                                case 4:
                                    b.checkBalance();
                                    break;
                                case 5:
                                    b.transHistory();
                                    break;
                                case 6:
                                    isFinished = true;
                                    break;
                            }
                        }
                    }
                } else if (ch == 2) {
                    break; // Exit the program
                }
            }
        }
    }
}
