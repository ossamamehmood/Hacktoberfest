/*Here's a Java code snippet that reads a CSV file and displays its contents in a tabular format using 
the Apache Commons CSV library. You'll need to add the Apache Commons CSV library to your project for this code 
to work. You can typically do this by including the library JAR file in your project's classpath.*/

import org.apache.commons.csv.CSVFormat;
import org.apache.commons.csv.CSVParser;
import org.apache.commons.csv.CSVRecord;

import java.io.FileReader;
import java.io.IOException;
import java.io.Reader;

public class CSVReaderExample {
    public static void main(String[] args) {
        String csvFilePath = "your_csv_file.csv"; // Replace with the path to your CSV file

        try {
            Reader reader = new FileReader(csvFilePath);
            CSVParser csvParser = new CSVParser(reader, CSVFormat.DEFAULT);

            // Print headers
            for (String header : csvParser.getHeaderNames()) {
                System.out.print(header + "\t");
            }
            System.out.println(); // Newline after headers

            // Print data
            for (CSVRecord csvRecord : csvParser) {
                for (String value : csvRecord) {
                    System.out.print(value + "\t");
                }
                System.out.println(); // Newline after each row
            }

            // Close the reader and parser
            reader.close();
            csvParser.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
