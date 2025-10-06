import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
public class IssueCar extends JFrame {
    private static final long serialVersionUID = 1L;
    JLabel l1,l2,l3,l4,l5,l6;
    JTextField t1,t2,t3,t4,t5;
    JButton b1,b2;
    IssueCar(){
        super("Register Customer");
        setSize(600,460);
        setLayout(new BorderLayout());
        l1=new JLabel("Issue Number:");
        l2=new JLabel("Customer Name:");
        l3=new JLabel("Age:");
        l4=new JLabel("Licence number:");
        l5=new JLabel("Car:");
        l1.setFont(new Font("Serif", Font.PLAIN, 17));
        l2.setFont(new Font("Serif", Font.PLAIN, 17));
        l3.setFont(new Font("Serif", Font.PLAIN, 17));
        l4.setFont(new Font("Serif", Font.PLAIN, 17));
        l5.setFont(new Font("Serif", Font.PLAIN, 17));
        l1.setForeground(Color.WHITE);
        l2.setForeground(Color.WHITE);
        l3.setForeground(Color.WHITE);
        l4.setForeground(Color.WHITE);
        l5.setForeground(Color.WHITE);
        t1=new JTextField(10);
        t2=new JTextField(10);
        t3=new JTextField(10);
        t4=new JTextField(10);
        t5=new JTextField(10);
        t1.setForeground(Color.WHITE);
        t2.setForeground(Color.WHITE);
        t3.setForeground(Color.WHITE);
        t4.setForeground(Color.WHITE);
        t5.setForeground(Color.WHITE);
        t1.setForeground(Color.WHITE);
        t1.setBackground(Color.GRAY);
        t2.setBackground(Color.GRAY);
        t3.setBackground(Color.GRAY);
        t4.setBackground(Color.GRAY);
        t5.setBackground(Color.GRAY);
        b1=new JButton("Register Customer");
        b2=new JButton("Back");
        MyActionListener ac = new MyActionListener();
        b1.addActionListener(ac);
        b2.addActionListener(ac);
        JPanel p1 = new JPanel();
        p1.setLayout(new GridLayout(5,2));
        p1.setBackground(new Color(44,62,80));
        p1.add(l1);
        p1.add(t1);
        p1.add(l2);
        p1.add(t2);
        p1.add(l3);
        p1.add(t3);
        p1.add(l4);
        p1.add(t4);
        p1.add(l5);
        p1.add(t5);
        JPanel p2 = new JPanel();
        p2.setBackground(new Color(44,62,80));
        p2.setLayout(new FlowLayout());
        b1.setBackground(Color.RED);
        b2.setBackground(new Color(100,149,237));
        b1.setForeground(Color.WHITE);
        b2.setForeground(Color.WHITE);
        p2.add(b2);
        p2.add(b1);
        add(p1,BorderLayout.CENTER);
        add(p2,BorderLayout.SOUTH);
        JPanel p3 = new JPanel();
        p3.setBackground(new Color(248,148,6));
        l6 = new JLabel("Customer Registration");
        l6.setFont(new Font("Serif", Font.BOLD, 40));
        l6.setForeground(Color.WHITE);
        p3.add(l6);
        add(p3,BorderLayout.NORTH);
    }
    public class MyActionListener implements ActionListener {
        ArrayList<Car> carList = FileHandling.readCarsData();
        public void actionPerformed(ActionEvent ae) {
            if(ae.getActionCommand().equals("Register Customer")) {
                boolean check = false;
                for(int i=0;i<carList.size();i++) {
                    if(carList.get(i).getCarName().equalsIgnoreCase(t5.getText())) {
                        check = true;
                        Customer cus = new Customer(t1.getText(),t2.getText(),t3.getText(),t4.getText());
                        SystemModel ren = new SystemModel(carList.get(i),cus);
                        FileHandling.addToCarRecord(carList);
                        ArrayList<SystemModel> rent = FileHandling.readSystemData();
                        ArrayList<Customer> CustomerList= FileHandling.readCustomerData();
                        rent.add(ren);
                        FileHandling.addToRentalRecord(rent);
                        CustomerList.add(cus);
                        FileHandling.addToCustomerRecord(CustomerList);
                        JOptionPane.showMessageDialog(new JFrame(),"Customer has been Registered Successfully.");
                    }
                }
                if(check!=true){
                    JOptionPane.showMessageDialog(new JFrame(),"Sorry Demanding Car Is Not Available");
                }
            }
            else if(ae.getActionCommand().equals("Back")) {
                dispose();
                CarRentalSystem f=new CarRentalSystem();
                f.setVisible(true);
            }
        }
    }
}