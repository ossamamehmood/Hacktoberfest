import java.util.*;

public class movie_ticket_sys 
{
	public static void main(String[] args) 
	{
		int num,opt1;
		Scanner v = new Scanner(System.in);
		System.out.println("*********************WELCOME TO VRB FILMS BOOKING SYSTEM*******************");
		System.out.println("Select The Theatre Of Your Locality");
		System.out.println("1 : INOX:Jai Ganesh, Akurdi");
		System.out.println("2 : INOX:Elpro City Square, Chinchwad ");
		System.out.println("3 : PVR:City One Mall,Pimpri ");
		System.out.println("4 : PVR:Pheonix Market City,Gold Pune");
		System.out.println("5 : VRB Multiplex   ");
		System.out.println("6 : PVR:Kumar Pacific,Pune" );
		System.out.println("7 : PVR:The Pavallion Pune ");
		System.out.println("8 : INOX:Anamora Town Centre,Hadapsar");
		System.out.println("Please Select The Options To Proceed Further");
		opt1 = v.nextInt();
		
	    switch(opt1)
	    {
	    case 1:
	    	System.out.println("You Have Selected 1");
	    	System.out.println("****NOW SHOWING****");
	    	System.out.println("1 : Avengers ");
	    	System.out.println("2 : Vikrant Rona ");
	    	System.out.println("3 : Vikram");
	    	System.out.println("4 : De Dhakka 2");
	    	System.out.println("5 : Shazam 2 "); 
	    	System.out.println("6 : Thor Love and Thunder");
	    	System.out.println("7 : Iron Heart ");
	    	System.out.println("8 : Minions The Rise of Gru"); 
	    	break;
	    case 2:
    	System.out.println("****NOW SHOWING****");
    	System.out.println("1 : Avengers ");
    	System.out.println("2 : Vikrant Rona ");
    	System.out.println("3 : Vikram");
    	System.out.println("4 : De Dhakka 2");
    	System.out.println("5 : Shazam 2 "); 
    	System.out.println("6 : Thor Love and Thunder");
    	System.out.println("7 : Iron Heart ");
    	System.out.println("8 : Minions The Rise of Gru"); 
    	break;
	    case 3:
	    	
	    	System.out.println("****NOW SHOWING****");
	    	System.out.println("1 : Avengers ");
	    	System.out.println("2 : Vikrant Rona ");
	    	System.out.println("3 : Vikram");
	    	System.out.println("4 : De Dhakka 2");
	    	System.out.println("5 : Shazam 2 "); 
	    	System.out.println("6 : Thor Love and Thunder");
	    	System.out.println("7 : Iron Heart ");
	    	System.out.println("8 : Minions The Rise of Gru"); 
	    	break;
	    case 4:
	    	
	    	System.out.println("****NOW SHOWING****");
	    	System.out.println("1 : Avengers ");
	    	System.out.println("2 : Vikrant Rona ");
	    	System.out.println("3 : Vikram");
	    	System.out.println("4 : De Dhakka 2");
	    	System.out.println("5 : Shazam 2 "); 
	    	System.out.println("6 : Thor Love and Thunder");
	    	System.out.println("7 : Iron Heart ");
	    	System.out.println("8 : Minions The Rise of Gru"); 
	    	break;
	    case 5:
	    	System.out.println("****NOW SHOWING****");
	    	System.out.println("1 : Avengers ");
	    	System.out.println("2 : Vikrant Rona ");
	    	System.out.println("3 : Vikram");
	    	System.out.println("4 : De Dhakka 2");
	    	System.out.println("5 : Shazam 2 "); 
	    	System.out.println("6 : Thor Love and Thunder");
	    	System.out.println("7 : Iron Heart ");
	    	System.out.println("8 : Minions The Rise of Gru"); 
	    	break;
	    case 7:
	    	System.out.println("****NOW SHOWING****");
	    	System.out.println("1 : Avengers ");
	    	System.out.println("2 : Vikrant Rona ");
	    	System.out.println("3 : Vikram");
	    	System.out.println("4 : De Dhakka 2");
	    	System.out.println("5 : Shazam 2 "); 
	    	System.out.println("6 : Thor Love and Thunder");
	    	System.out.println("7 : Iron Heart ");
	    	System.out.println("8 : Minions The Rise of Gru"); 
	    	break;
	    case 8:
	    	
	    	System.out.println("****NOW SHOWING****");
	    	System.out.println("1 : Avengers ");
	    	System.out.println("2 : Vikrant Rona ");
	    	System.out.println("3 : Vikram");
	    	System.out.println("4 : De Dhakka 2");
	    	System.out.println("5 : Shazam 2 "); 
	    	System.out.println("6 : Thor Love and Thunder");
	    	System.out.println("7 : Iron Heart ");
	    	System.out.println("8 : Minions The Rise of Gru"); 
	    	break;
	
	    default:
	    	System.out.println("Wrong Opt");
	    }
	    
	    int opt4 = v.nextInt();
	    System.out.println("Select Suitable Option");
	    System.out.println("1 : 3:00  PM ");
	    System.out.println("2 : 6:00  PM ");
	    System.out.println("3 : 12:00 PM ");
	    System.out.println("4 : 6:00  AM ");
	    
	    int opt3= v.nextInt();
	    
	    System.out.println("Select The Number Of Members ");
	    num = v.nextInt();
	   
	    
	    System.out.println("Select The Type Of Seat");
	    System.out.println("1 : Standard = 200 " );
	    System.out.println("2 : Premium = 350 ");
	    System.out.println("3 : Recliner = 500 ");
	    int opt2 = v.nextInt();
	    
	    if(opt2==1)
	    {
	    	System.out.println("The Total is "+(num*200)+" Rupees");
	    }
	    else if(opt2==2)
	    {
	    	System.out.println("The Total is "+(num*350)+" Rupees");
	    }
	    else if(opt2==3)
	    {
	    	System.out.println("The Total is "+(num*500)+" Rupees");
	    }
	    else
	    {
	    	System.out.println("Wrong Option ");
	    }
	    
		
	}
	

}
