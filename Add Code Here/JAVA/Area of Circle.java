import java.util.Scanner;

public class Ex12AreaofCircle{

    public static void main(String args[]){
		
		Scanner userIn = new Scanner(System.in);
		
		System.out.println("Enter radius of circle: ");
		float radius = userIn.nextFloat();
		
		double areacircle = Math.PI * radius * radius;
		
		System.out.println("The area of the circle is: " + areacircle);
        
    }
}



