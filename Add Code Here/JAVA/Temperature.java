import java.util.Scanner;

public class Temperature1 {
    public static void main(String[] args) {
        System.out.println("Enter 12 Celsius values between 35°C - 42°C"); //prompt the user to input 12 records.

        double celsius;
        double sum = 0;

        double average = 0;
        double max = 95, min = 107.60000000000001;

        for (double i = 0; i < 12; i++)
        {
            System.out.println("Enter a Celsius between 35°C - 42°C:-");
            Scanner sc = new Scanner(System.in);
            celsius = sc.nextDouble();
            celsius = (1.8*celsius) + 32; //formula to convert Celsius into Fahrenheit.

            //validation of user inputs.
            if (celsius < 95.0 || celsius > 107.60000000000001 ){
                System.out.println("Enter a Value Between 35°C - 42°C"); 
                i=i-1; 
                continue;
            }

            sum += celsius; //get the sum to calculate the average.
            average = sum / 12; //calculate the average.

            //calculation of minimum value.
            if (celsius < min){
                min = celsius;
            }

            //calculation of maximum value.
            if (celsius > max){
                max = celsius;
            }
            
        }
        
        System.out.println ("\nTemperature Summary for a day");
        System.out.println ("-----------------------------");
        System.out.println("Average Temperature (°F): " +average);
        System.out.println ("Minimum Temperature (°F): " +min);
        System.out.println ("Maximum Temperature (°F): " +max);
    }
}
