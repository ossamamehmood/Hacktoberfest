import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.Serializable;
import java.util.ArrayList;

public class SearchCar extends JFrame {
    private static final long serialVersionUID = 1L;
    JLabel l1;
    JTextField t1;
    JButton b1,b2;
    SearchCar(){
        super("Search Existing Cars");
        setVisible(true);
        setSize(350,200);
        setResizable(false);
        setLayout(new BorderLayout());
        JPanel p1 = new JPanel();
        p1.setBackground(Color.gray);
        l1=new JLabel("Enter Car Name:");
        l1.setFont(new Font("Serif", Font.BOLD, 40));
        l1.setForeground(Color.WHITE);
        p1.add(l1);
        add(p1,BorderLayout.NORTH);
        JPanel p2 = new JPanel();
        p2.setLayout(new FlowLayout());
        p2.setBackground(new Color(35,203,167));
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
        JPanel p3 = new JPanel();
        p3.setLayout(new FlowLayout());
        p2.add(t1);
        p3.setBackground(new Color(35,203,167));
        p3.add(b1);
        p3.add(b2);
        add(p2,BorderLayout.CENTER);
        add(p3,BorderLayout.SOUTH);
    }
    public class MyActionListener implements ActionListener, Serializable {
        private static final long serialVersionUID = 1L;

        public void actionPerformed(ActionEvent ae) {
            if(ae.getActionCommand().equals("Search")) {
                ArrayList<Car> CarList= FileHandling.readCarsData();
                boolean check = true;
                for(int i=0;i<CarList.size();i++) {
                    if(CarList.get(i).getCarName().equalsIgnoreCase(t1.getText())) {
                        check = false;
                        JOptionPane.showMessageDialog(new JFrame(),"Car details:  \nID :"+CarList.get(i).getCarNumber()+
                                "\nName :"+CarList.get(i).getCarName()+"\nModel :"+CarList.get(i).getCarModel()+ "\nColor :"+CarList.get(i).getColor()+"\n"+
                                "\nHorse Power :"+CarList.get(i).getHorsePower()+"\nSeating Capacity :"+CarList.get(i).getSeatingCapacity()+
                                "\nFuel Economy :"+CarList.get(i).getFuelEconomy()+" km Per/Litre"+
                                "\nRental cost :"+CarList.get(i).getRentalCost());
                    }
                }
                if(check!=false){
                    JOptionPane.showMessageDialog(new JFrame(),"Sorry Car Does Not Exist" +"\n Try Again");
                    t1.setText("");
                }
            }
            if(ae.getActionCommand().equals("Back")){
                dispose();
                CarRentalSystem f=new CarRentalSystem();
                f.setVisible(true);
            }
        }
    }
}