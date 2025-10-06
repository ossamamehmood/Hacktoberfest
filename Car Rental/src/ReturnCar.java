import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.Serializable;
import java.util.ArrayList;

public class ReturnCar extends JFrame implements ActionListener, Serializable {
    private JLabel lab1, lab2, lab3, lab4, lab6;
    private JTextField t1, t2, t3, t4;
    private JButton jazz, b1, b2, b3, b4;
    private ImageIcon img1;
    public ReturnCar() {
        super("Returning Process");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(400, 400);
        setLayout(new BorderLayout());
        JPanel p1 = new JPanel();
        p1.setLayout(new GridLayout(5, 2));
        p1.setBackground(Color.ORANGE);
        lab1 = new JLabel("Customer Name: ");
        p1.add(lab1);
        t1 = new JTextField();
        t1.setBackground(Color.YELLOW);
        p1.add(t1);
        lab2 = new JLabel("Car : ");
        p1.add(lab2);
        t2 = new JTextField();
        t2.setBackground(Color.YELLOW);
        p1.add(t2);
        lab3 = new JLabel("Renting Duration : ");
        p1.add(lab3);
        t3 = new JTextField();
        t3.setBackground(Color.YELLOW);
        p1.add(t3);
        lab4 = new JLabel("Calculate Bill : ");
        p1.add(lab4);
        t4 = new JTextField();
        t4.setBackground(Color.YELLOW);
        p1.add(t4);
        lab6 = new JLabel();
        jazz = new JButton("Pay Via Jazz Cash");
        jazz.setBackground(Color.RED);
        img1 = new ImageIcon("jazz.jpg");
        Image image1 = img1.getImage();
        Image nImg1 = image1.getScaledInstance(190, 50, java.awt.Image.SCALE_SMOOTH);
        img1 = new ImageIcon(nImg1);
        lab6.setIcon(img1);
        p1.add(lab6);
        jazz.addActionListener(this);
        p1.add(jazz);
        add(p1, BorderLayout.CENTER);
        JPanel p2 = new JPanel();
        p2.setLayout(new FlowLayout());
        b1 = new JButton("Calculate Bill");
        b2 = new JButton("Reset");
        b3 = new JButton("Quit");
        b4 = new JButton("Paid");
        b1.addActionListener(this);
        b2.addActionListener(this);
        b3.addActionListener(this);
        b4.addActionListener(this);
        p2.add(b1);
        p2.add(b2);
        p2.add(b3);
        p2.add(b4);
        p2.setBackground(Color.BLACK);
        add(p2, BorderLayout.SOUTH);
    }
    public void actionPerformed(ActionEvent e) {
        String ac = e.getActionCommand();
        if (ac.equals("Calculate Bill")) {
            int i = 0;
            boolean found = false;
            ArrayList<SystemModel> RentalList = FileHandling.readSystemData();
            for (i = 0; i < RentalList.size(); i++) {
                if (RentalList.get(i).getCustomer().getCustomerName().equalsIgnoreCase(t1.getText())) {
                    found = true;
                    t2.setText(RentalList.get(i).getCar().getCarName());
                    try{
                        Double d = (RentalList.get(i).getCar().getRentalCost())*(Double.parseDouble(t3.getText()));
                        t4.setText(String.valueOf(d));
                        JOptionPane.showMessageDialog(new JFrame(), "You Have To Paid "+t4.getText()+" PKR");
                    }
                    catch(Exception ex){
                        JOptionPane.showMessageDialog(new JFrame(), "Please Enter Duration(Hours)");
                    }

                }
            }
            if (found != true)
                JOptionPane.showMessageDialog(new JFrame(), "Customer not found.");
        }
        else if (ac.equals("Reset")) {
            t1.setText("");
            t2.setText("");
            t3.setText("");
            t4.setText("");
        }
        if (ac.equals("Quit")) {
            this.dispose();
            Login l = new Login();
            l.setVisible(true);
            l.setResizable(false);
        }
        if (ac.equals("Pay Via Jazz Cash")) {
            JazzCash u = new JazzCash();
            this.dispose();
            u.setResizable(false);
            u.setVisible(true);
        }
        if (ac.equals("Paid")) {
            JOptionPane.showMessageDialog(new JFrame(), "Car Returned Successfully");
        }
    }
}