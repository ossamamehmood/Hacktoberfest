
class Book{
    private String title, author;   //Declaration of variable title and author
    private double price;           //Declaration of variable price
    private static double totalprice=0.0;       //Declaration and initialization of variable totalprice to store total amount 
    Book(){}
    Book(String title, String author, double price){        //Constructor to iniliazitation of variables title, author and price of book
        this.title = title;
        this.author = author;
        this.price = price;
    }
    public String display(){            //The method to return the data of book which are initialized by constructor 
        return (title+"\t"+author+"\t"+price).toString();
    }
    public double totalPrice(){     //This method is count a total price of all books 
        return totalprice += price;     
    }
}
public class Library {

    public static void main(String[] args) {
        Book bookshelf[] = new Book[5];     //Array to get the data for 5 books

        //set the information of books by array
        bookshelf[0] = new Book("Starwars","Luke Skywalker",30.0);
        bookshelf[1] = new Book("HarryPotter","J.K Rawling",300.0);
        bookshelf[2] = new Book("Matilda Rose","Roald Dahl",45.0);
        bookshelf[3] = new Book("Java First","Donald Trump",500.0);
        bookshelf[4] = new Book("Core Java","Cayla Sally",50.0);

        Double totalprice=0.0;  // Variable to store the returned value of totalPrice method

        System.out.println("The Library book list as follows:\n");
        System.out.println("Title\t\tAuthor\t\tPrice");
        for(int i=0; i<5; i++){             
            String row = bookshelf[i].display();            //to display the data of bookshelf
            System.out.println(row);           
            totalprice = bookshelf[i].totalPrice();     // to count the total price of all books
        }

        System.out.println("\nThe total number of books: 5");
        System.out.println("The total price of books: "+totalprice+"$");

    }
}