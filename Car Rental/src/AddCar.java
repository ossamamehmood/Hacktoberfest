import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;

public class AddCar extends JFrame {
    private static final long serialVersionUID = 1L;
    JLabel l1,l2,l3,l4,l5,l6,l7,l8,lab;
    JTextField t1,t2,t3,t4,t5,t6,t7,t8;
    JButton b1,b2;
    AddCar(){
        super("Add Car");
        setSize(600,400);
        setLayout(new BorderLayout());
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        l1=new JLabel("Car Number:");
        l2=new JLabel("Car Name:");
        l3=new JLabel("Car Model:");
        l4=new JLabel("Horsepower:");
        l5=new JLabel("Seating Capacity:");
        l6=new JLabel("Fuel Economy:");
        l7=new JLabel("Rental Cost:");
        l8=new JLabel("Car Color:");
        l1.setForeground(Color.WHITE);
        l1.setFont(new Font("Serif", Font.PLAIN, 20));
        l2.setForeground(Color.WHITE);
        l2.setFont(new Font("Serif", Font.PLAIN, 20));
        l3.setForeground(Color.WHITE);
        l3.setFont(new Font("Serif", Font.PLAIN, 20));
        l4.setForeground(Color.WHITE);
        l4.setFont(new Font("Serif", Font.PLAIN, 20));
        l5.setForeground(Color.WHITE);
        l5.setFont(new Font("Serif", Font.PLAIN, 20));
        l6.setForeground(Color.WHITE);
        l6.setFont(new Font("Serif", Font.PLAIN, 20));
        l7.setForeground(Color.WHITE);
        l7.setFont(new Font("Serif", Font.PLAIN, 20));
        l8.setForeground(Color.WHITE);
        l8.setFont(new Font("Serif", Font.PLAIN, 20));
        t1=new JTextField(10);
        t2=new JTextField(10);
        t3=new JTextField(10);
        t4=new JTextField(10);
        t5=new JTextField(10);
        t6=new JTextField(10);
        t7=new JTextField(10);
        t8=new JTextField(10);
        t1.setBackground(Color.GRAY);
        t2.setBackground(Color.GRAY);
        t3.setBackground(Color.GRAY);
        t4.setBackground(Color.GRAY);
        t5.setBackground(Color.GRAY);
        t6.setBackground(Color.GRAY);
        t7.setBackground(Color.GRAY);
        t8.setBackground(Color.GRAY);
        JPanel p1 = new JPanel();
        p1.setLayout(new GridLayout(8,2));
        p1.setBackground(new Color(246,36,89));
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
        p1.add(l6);
        p1.add(t6);
        p1.add(l7);
        p1.add(t7);
        p1.add(l8);
        p1.add(t8);
        JPanel p2 = new JPanel();
        p2.setLayout(new FlowLayout());
        p2.setBackground(new Color(246,36,89));
        b1=new JButton("Add Car");
        b2=new JButton("Cancel");
        b1.setBackground(Color.GREEN);
        b2.setBackground(Color.RED);
        b1.setForeground(Color.WHITE);
        b2.setForeground(Color.WHITE);
        MyActionListener act =new MyActionListener();
        b1.addActionListener(act);
        b2.addActionListener(act);
        p2.add(b1);
        p2.add(b2);
        add(p1,BorderLayout.CENTER);
        add(p2,BorderLayout.SOUTH);
        JPanel p3 = new JPanel();
        p3.setBackground(Color.BLACK);
        lab = new JLabel("Add New Car");
        lab.setFont(new Font("Serif", Font.BOLD, 40));
        lab.setForeground(Color.WHITE);
        p3.add(lab);
        add(p3,BorderLayout.NORTH);
    }
    public class MyActionListener implements ActionListener {
        public void actionPerformed(ActionEvent ae) {
            if(ae.getActionCommand().equals("Add Car")) {
                Car c=new Car(t1.getText(),t2.getText(),t3.getText(),t4.getText(),Integer.parseInt(t5.getText()),
                        Double.parseDouble(t6.getText()),Double.parseDouble(t7.getText()),t8.getText());
                ArrayList<Car> car = FileHandling.readCarsData();
                car.add(c);
                FileHandling.addToCarRecord(car);
                JOptionPane.showMessageDialog(new JFrame(),"Car has been added!!!");
            }
            if(ae.getActionCommand().equals("Cancel")) {
                dispose();
                CarRentalSystem f=new CarRentalSystem();
                f.setVisible(true);
            }
        }
    }
}