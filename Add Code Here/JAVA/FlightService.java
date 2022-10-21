import java.util.Scanner;
import java.util.ArrayList;
import java.util.Arrays;
class FlightService {
    
    String airline;
    int aircraft;

    FlightService(String airline, int aircraft){

        this.airline = airline;
        this.aircraft = aircraft;


    }


}

class PassengerFlight extends FlightService{
   
    String name;
    int id;
  int n;
    PassengerFlight(String airline, int aircraft,String name,int id){
        super(airline, aircraft);

        this.airline = airline;
        this.aircraft = aircraft;
        this.name =name;
        this.id = id;
       
    }

    void PassService()
    {
        
        Scanner sc = new Scanner(System.in);

     
        System.out.println("Enter Passenger Details : ");
        for(int i=0;i<n;i++)
        {
            
            System.out.println("Enter passenger name : ");
            name = sc.next();
            System.out.println("Enter passeger id : ");
            id=sc.nextInt();
            
           
            
        }
    }
    void printPassDetails()
    {
        System.out.println("Name , id of Passenger : "+name+" "+id);
       
        System.out.println("PASSENGER fare");
        int passbill=5000;
        System.out.println(passbill);
        
    }

}

class CargoFlight extends FlightService{
    String cname;
    int cid;
    int n;
    
    CargoFlight(String airline, int aircraft, String cname, int cid) {
        super(airline, aircraft);

        this.airline = airline;
        this.aircraft = aircraft;
        this.cname =cname;
        this.cid = cid;
        
    }
    void CargoService()
    {
        
        Scanner sc = new Scanner(System.in);

     
        System.out.println("Enter Cargo Details : ");
        for(int i=0;i<n;i++)
        {
            
            System.out.println("Enter passenger name : ");
            cname = sc.next();
            System.out.println("Enter passeger id : ");
            cid=sc.nextInt();
            
           
            
        }
    }
    void printDetails()
    {
        System.out.println("Name , id of Passenger : "+cname+" "+cid);
        System.out.println("Cargo fare");
        int Cargobill =2000;
        System.out.println(Cargobill);
        
    }


}

class main{
public static void main(String[] args) {
    
    FlightService fl = new FlightService("Indigo",30);
    System.out.println("Airline"+ fl.airline+" "+ " ID "+ fl.aircraft);

    PassengerFlight pl = new PassengerFlight("Indigo",30, "AMIT", 55);
    CargoFlight cl= new CargoFlight("Indigo",31,"BOXES",44);
    pl.printPassDetails();
    cl.printDetails();
    System.out.println(pl.airline+" "+pl.aircraft+" "+pl.name+" "+ pl.id);
    System.out.println(cl.airline+" "+cl.aircraft+" "+cl.cname+" "+ cl.cid);

}
    

}
