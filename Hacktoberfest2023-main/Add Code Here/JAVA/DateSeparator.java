//Java program to split the date into day, month and year.

import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.time.format.DateTimeParseException;
import java.util.Scanner;

public class DateSeparator {
    public static void main(String[] args) {
        //scanner for input
        Scanner scanner =new Scanner(System.in);

        //take date as a string
        String date;

        try{
            //take input
            System.out.print("Enter date (Format: YYYY-MM-DD): ");
            date = scanner.next();

            //checks for the date format
            if(isValidDate(date)){
                //split into an array
                String[] dateArray = date.split("-");

                //print date
                System.out.println("Date: " + date);

                //print day,month and year separately
                System.out.println("Year: " + dateArray[0]);
                System.out.println("Month: " + dateArray[1]);
                System.out.println("Day: " + dateArray[2]);
            }
        }catch (Exception e){
            System.out.println("Error: " + e.getMessage());
        }
    }

    private static boolean isValidDate(String date) {
        //date format
        DateTimeFormatter format = DateTimeFormatter.ISO_LOCAL_DATE;

        try{
            LocalDate.parse(date,format);
            return true;
        } catch (DateTimeParseException e) {
            System.out.println("Incorrect date format (YYYY-MM-DD)");
            return false;
        }
    }
}
