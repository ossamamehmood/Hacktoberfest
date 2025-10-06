import javax.imageio.ImageIO;
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.image.BufferedImage;
import java.io.File;

public class CarRentalSystem extends JFrame implements ActionListener {
    BufferedImage car;
    private JButton b1, b2, b3, b4, b5,b6;
    CarRentalSystem() {
        super("Rental System");
        setSize(500, 500);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new BorderLayout());
        getContentPane().setBackground(new Color(139,0,139));
        try{
            car = ImageIO.read(new File("cars.jpg"));
        }
        catch (Exception e){
            System.out.println(e.toString());
        }
        DrawPannel dpnl = new DrawPannel(car);
        add(dpnl,BorderLayout.CENTER);
        b1 = new JButton("Rent A Car");
        b2 = new JButton("Add New Car");
        b3 = new JButton("Return Car");
        b4 = new JButton("Search Car");
        b5 = new JButton("Search Customer");
        b6 = new JButton("Logout");
        b1.setBackground(new Color(112,128,144));
        b2.setBackground(new Color(112,128,144));
        b3.setBackground(new Color(112,128,144));
        b4.setBackground(new Color(112,128,144));
        b5.setBackground(new Color(112,128,144));
        b6.setBackground(new Color(112,128,144));
        b1.setBounds(20, 30, 100, 20);
        b2.setBounds(20, 30, 100, 20);
        b3.setBounds(20, 30, 100, 20);
        b4.setBounds(20, 30, 150, 20);
        b5.setBounds(20, 30, 100, 20);
        b6.setBounds(20, 30, 100, 20);
        b1.addActionListener(this);
        b2.addActionListener(this);
        b3.addActionListener(this);
        b4.addActionListener(this);
        b5.addActionListener(this);
        b6.addActionListener(this);
        JPanel p1 = new JPanel();
        p1.setLayout(new GridLayout(3,1));
        p1.add(b1);
        p1.add(b2);
        p1.add(b3);
        add(p1,BorderLayout.WEST);
        JPanel p2 = new JPanel();
        p2.setLayout(new GridLayout(3,1));
        p2.add(b4);
        p2.add(b5);
        p2.add(b6);
        add(p2,BorderLayout.EAST);
    }
    private class DrawPannel extends JPanel {
        Image img;
        public DrawPannel(Image img) {
            this.img = img;
            setPreferredSize(new Dimension(350, 500));
        }
        public void paintComponent(Graphics g) {
            super.paintComponent(g);
            Graphics2D g2d = (Graphics2D) g;
            g2d.drawImage(this.img, 0, 0, 350, 500, null);
        }
    }
    public void actionPerformed(ActionEvent ae){
        if(ae.getActionCommand().equals("Rent A Car")) {
            this.dispose();
            IssueCar c =new IssueCar();
            c.setVisible(true);
        }
        else if(ae.getActionCommand().equals("Add New Car")) {
            this.dispose();
            AddCar cf=new AddCar();
            cf.setVisible(true);
        }
        else if(ae.getActionCommand().equals("Search Car")) {
            this.dispose();
            SearchCar s=new SearchCar();
            s.setVisible(true);
        }
        else if(ae.getActionCommand().equals("Search Customer")) {
            this.dispose();
            SearchCustomer cu=new SearchCustomer();
            cu.setVisible(true);
        }
        else if(ae.getActionCommand().equals("Return Car")){
            this.dispose();
            ReturnCar rc = new ReturnCar();
            rc.setResizable(false);
            rc.setVisible(true);
        }
        else if(ae.getActionCommand().equals("Logout")) {
            this.dispose();
            Home h = new Home();
            h.setVisible(true);
            h.setResizable(false);
        }
    }
}