import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.Serializable;
import java.util.ArrayList;
public class SearchCustomer extends JFrame {
    private static final long serialVersionUID = 1L;
    JLabel l1;
    JTextField t1;
    JButton b1,b2;
    SearchCustomer(){
        super("Search Customer");
        setVisible(true);
        setVisible(true);
        setSize(420,200);
        setResizable(false);
        setLayout(new BorderLayout());
        JPanel p1 = new JPanel();
        p1.setBackground(Color.YELLOW);
        l1=new JLabel("Enter Customer Name:");
        l1.setFont(new Font("Serif", Font.BOLD, 40));
        l1.setForeground(Color.BLACK);
        p1.add(l1);
        add(p1,BorderLayout.NORTH);
        JPanel p2 = new JPanel();
        p2.setLayout(new FlowLayout());
        p2.setBackground(new Color(58,83,155));
        t1=new JTextField(10);
        t1.setBackground(Color.gray);
        b1=new JButton("Search");
        b2=new JButton("Back");
        MyActionListener ac = new MyActionListener();
        b1.addActionListener(ac);
        b2.addActionListener(ac);
        b1.setBackground(Color.GREEN);
        b2.setBackground(Color.RED);
        b1.setForeground(Color.WHITE);
        b2.setForeground(Color.WHITE);
        p2.add(t1);
        JPanel p3 = new JPanel();
        p3.setLayout(new FlowLayout());
        p3.setBackground(new Color(58,83,155));
        p3.add(b1);
        p3.add(b2);
        add(p2,BorderLayout.CENTER);
        add(p3,BorderLayout.SOUTH);
    }
    public class MyActionListener implements ActionListener, Serializable {
        private static final long serialVersionUID = 1L;
        public void actionPerformed(ActionEvent ae) {
            int i=0;
            if(ae.getActionCommand().equals("Search")) {
                boolean found =false;
                ArrayList<SystemModel> RentalList= FileHandling.readSystemData();
                for(i=0;i<RentalList.size();i++) {
                    if(RentalList.get(i).getCustomer().getCustomerName().equalsIgnoreCase(t1.getText())) {
                        found = true;
                        JOptionPane.showMessageDialog(new JFrame(),"Customer's Detail :\n\nIssue Number :"+RentalList.get(i).getCustomer().getIssueNumber()+
                                "\nName:"+RentalList.get(i).getCustomer().getCustomerName()+"\nAge:"+RentalList.get(i).getCustomer().getAge()+
                                "\nLicence number:"+RentalList.get(i).getCustomer().getLicenceNum()+"\n\nCar details:  \n\nID :"+RentalList.get(i).getCar().getCarNumber()+
                                "\nName :"+RentalList.get(i).getCar().getCarName()+"\nModel :"+RentalList.get(i).getCar().getCarModel()+
                                "\nHorse Power :"+RentalList.get(i).getCar().getHorsePower()+"\nSeating Capacity :"+RentalList.get(i).getCar().getSeatingCapacity()+
                                "\nColor: "+RentalList.get(i).getCar().getColor()+"\n"+
                                "\nFuel Economy :"+RentalList.get(i).getCar().getFuelEconomy()+" km Per/Litre"+
                                "\nRental cost :"+RentalList.get(i).getCar().getRentalCost());
                    }
                }
                if(found !=true)
                    JOptionPane.showMessageDialog(new JFrame(),"Customer not found.");
                dispose();
                CarRentalSystem r=new CarRentalSystem();
                r.setVisible(true);
            }
            if(ae.getActionCommand().equals("Back")){
                dispose();
                CarRentalSystem r=new CarRentalSystem();
                r.setVisible(true);
            }
        }
    }
}