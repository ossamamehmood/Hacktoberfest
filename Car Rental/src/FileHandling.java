import javax.swing.*;
import java.io.*;
import java.util.ArrayList;

public class FileHandling {

    public static void addToCarRecord(ArrayList<Car> cars)
    {
        ObjectOutputStream out = null;

        try {
            out = new ObjectOutputStream(new FileOutputStream("CarRecords.ser"));
            for(int i = 0 ; i < cars.size() ; i++) {
                out.writeObject(cars.get(i));
            }
        } catch(IOException e) {
            JOptionPane.showMessageDialog(new JFrame(),"Error in Opening Process");

        }
        finally {
            try {
                if(out != null) {
                    out.close();
                }
            }
            catch (IOException e) {
                JOptionPane.showMessageDialog(new JFrame(),"Error in Closing Process");

            }
        }
    }
    public static void addToCustomerRecord(ArrayList<Customer> customers)
    {
        ObjectOutputStream outputStream = null;

        try {
            outputStream = new ObjectOutputStream(new FileOutputStream("CustomersRecord.ser"));
            for(int i = 0 ; i < customers.size() ; i++) {
                outputStream.writeObject(customers.get(i));
            }
        } catch(IOException e) {
            JOptionPane.showMessageDialog(new JFrame(),"Error while opening file");

        } finally {
            try {
                if(outputStream != null) {
                    outputStream.close();
                }

            } catch (IOException e) {
                JOptionPane.showMessageDialog(new JFrame(),"Error while closing file");

            }
        }
    }
    public static ArrayList<Car> readCarsData()
    {
        ArrayList<Car> car = new ArrayList<Car>(0);
        ObjectInputStream in = null;
        try
        {
            in = new ObjectInputStream(new FileInputStream("CarRecords.ser"));
            boolean EOF = false;
            while(!EOF) {
                try {
                    Car myObj = (Car) in.readObject();
                    car.add(myObj);
                } catch (ClassNotFoundException e) {
                } catch (EOFException end) {
                    EOF = true;
                }
            }
        }
        catch(FileNotFoundException e) {
        }
        catch (IOException e) {

        } finally {
            try {
                if(in != null)
                    in.close( );
            } catch (IOException e) {
                JOptionPane.showMessageDialog(new JFrame(),"Error in Closing Process");
            }
        }
        return car;
    }
    public static ArrayList<Customer> readCustomerData()
    {
        ArrayList<Customer> customer = new ArrayList<Customer>(0);
        ObjectInputStream in = null;
        try
        {
            in = new ObjectInputStream(new FileInputStream("CustomersRecord.ser"));
            boolean EOF = false;
            while(!EOF) {
                try {
                    Customer myObj = (Customer) in.readObject();
                    customer.add(myObj);
                }
                catch (ClassNotFoundException e) {

                } catch (EOFException end) {
                    EOF = true;
                }
            }
        }
        catch(FileNotFoundException e) {

        }
        catch (IOException e) {

        }
        finally {
            try {
                if(in != null)
                    in.close( );
            } catch (IOException e) {
                JOptionPane.showMessageDialog(new JFrame(),"Error in Closing Process");
            }
        }
        return customer;
    }
    public static ArrayList<SystemModel> readSystemData()
    {
        ArrayList<SystemModel> rent = new ArrayList<SystemModel>(0);
        ObjectInputStream in = null;
        try
        {
            in = new ObjectInputStream(new FileInputStream("CompanyRecord.ser"));
            boolean EOF = false;
            while(!EOF) {
                try {
                    SystemModel myObj = (SystemModel) in.readObject();
                    rent.add(myObj);
                }
                catch (ClassNotFoundException e) {

                } catch (EOFException end) {
                    EOF = true;
                }
            }
        }
        catch(FileNotFoundException e) {

        }
        catch (IOException e) {

        }
        finally {
            try {
                if(in != null)
                    in.close( );
            } catch (IOException e) {
                JOptionPane.showMessageDialog(new JFrame(),"Error in Closing Process");
            }
        }
        return rent;
    }

    public static void addToRentalRecord(ArrayList<SystemModel> rental)
    {
        ObjectOutputStream out = null;
        try {
            out = new ObjectOutputStream(new FileOutputStream("CompanyRecord.ser"));
            for(int i = 0; i < rental.size() ; i++) {
                out.writeObject(rental.get(i));
            }
        } catch(IOException e) {
            JOptionPane.showMessageDialog(new JFrame(),"Error in Opening Process");

        } finally {
            try {
                if(out != null) {
                    out.close();
                }

            } catch (IOException e) {
                JOptionPane.showMessageDialog(new JFrame(),"Error in Closing Process");

            }
        }
    }
}