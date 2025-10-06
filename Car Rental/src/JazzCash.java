import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
public class JazzCash extends JFrame implements ActionListener {
    private JLabel l1,l2,l3,l4;
    private JTextField t1,t2,t3,t4;
    private JButton b1,b2;
    private ImageIcon img;
    public JazzCash(){
        super("Jazz Cash");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(350,400);
        setLayout(new BorderLayout());
        JPanel p1 = new JPanel();
        p1.setLayout(new GridLayout(4,2));
        l1 = new JLabel("Name: ");
        p1.add(l1);
        t1 = new JTextField();
        t1.setBackground(Color.BLACK);
        p1.add(t1);
        l2 = new JLabel("Mobile Number: ");
        p1.add(l2);
        t2 = new JTextField();
        t2.setBackground(Color.BLACK);
        p1.add(t2);
        l3 = new JLabel("MPIN: ");
        p1.add(l3);
        t3 = new JTextField();
        t3.setBackground(Color.BLACK);
        p1.add(t3);
        l4 = new JLabel("CNIC: ");
        p1.add(l4);
        t4 = new JTextField();
        t4.setBackground(Color.BLACK);
        p1.add(t4);
        p1.setBackground(Color.RED);
        add(p1,BorderLayout.CENTER);
        JPanel p2 = new JPanel();
        p2.setLayout(new FlowLayout());
        b1 = new JButton("Pay");
        b2 = new JButton("Back");
        b1.addActionListener(this);
        b2.addActionListener(this);
        p2.add(b1);
        p2.add(b2);
        p2.setBackground(Color.BLACK);
        add(p2,BorderLayout.SOUTH);
        JPanel p = new JPanel();
        img = new ImageIcon("jazz.jpg");
        Image image = img.getImage();
        Image nImg = image.getScaledInstance(340,120, java.awt.Image.SCALE_SMOOTH);
        img = new ImageIcon(nImg);
        p.add(new JLabel(img));
        p.setBackground(Color.BLACK);
        add(p,BorderLayout.NORTH);
    }
    public void actionPerformed(ActionEvent e){
        Jazz j = new Jazz(t1.getText(),t2.getText(),t4.getText(),t3.getText());
        if(e.getActionCommand().equals("Back")){
            this.dispose();
            ReturnCar car = new ReturnCar();
            car.setVisible(true);
            car.setResizable(false);
        }
        if(e.getActionCommand().equals("Pay")){
            if(t1.getText().equals(j.getName())&&t2.getText().equals(j.getMobileNumber())&&
            t4.getText().equals(j.getCnic())&&t3.getText().equals(j.getMpin())){
                JOptionPane.showMessageDialog(new JFrame(),"Thanks for Using Our Service ");
            }
            else{
                JOptionPane.showMessageDialog(new JFrame(),"Record  Not Found. Please Try Again");
            }
        }
    }
}