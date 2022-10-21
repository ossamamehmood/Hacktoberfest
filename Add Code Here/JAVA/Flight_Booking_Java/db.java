import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;

public class db {
   static final String DB_URL = "jdbc:mysql://localhost:3306?user=root&password=root";
   static final String USER = "guest";

   static final String PASS = "guest123";

   public static void main(String[] args) {
      // Open a connection
//      try(Connection conn = DriverManager.getConnection(DB_URL, USER, PASS);
      try(Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306?user=root&password=root");

          Statement stmt = conn.createStatement();
      ) {		      
         String sql = "CREATE DATABASE STUDENTS";
         stmt.executeUpdate(sql);
         System.out.println("Database created successfully...");   	  
      } catch (SQLException e) {
         e.printStackTrace();
      } 
   }
}