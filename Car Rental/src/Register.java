import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectOutputStream;

public class Register extends JFrame implements ActionListener {
    private JLabel l1,l2,l3,l4,l5,l6;
    private JTextField t1,t2,t3,t4,t5;
    private JPasswordField pass;
    private JButton b1,b2,b3;
    private ImageIcon img,img1,img2;
    public Register(){
        super("Registration");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(400,400);
        setLayout(new BorderLayout());
        JPanel p1 = new JPanel();
        p1.setLayout(new GridLayout(6,2));
        l1 = new JLabel("Name: ");
        p1.add(l1);
        t1 = new JTextField();
        p1.add(t1);
        l2 = new JLabel("Password: ");
        p1.add(l2);
        pass = new JPasswordField(20);
        p1.add(pass);
        l3 = new JLabel("Email: ");
        p1.add(l3);
        t2 = new JTextField();
        p1.add(t2);
        l4 = new JLabel("CNIC: ");
        p1.add(l4);
        t3 = new JTextField();
        p1.add(t3);
        l5 = new JLabel("Contact: ");
        p1.add(l5);
        t4 = new JTextField();
        p1.add(t4);
        l6 = new JLabel("Address");
        p1.add(l6);
        t5 = new JTextField();
        p1.add(t5);
        p1.setBackground(Color.GRAY);
        add(p1,BorderLayout.CENTER);
        JPanel p2 = new JPanel();
        p2.setLayout(new FlowLayout());
        b1 = new JButton("Sign Up");
        b1.addActionListener(this);
        b2 = new JButton("Reset");
        b3 = new JButton("Cancel");
        b2.addActionListener(this);
        b3.addActionListener(this);
        b1.setBackground(Color.GREEN);
        b2.setBackground(Color.PINK);
        b3.setBackground(Color.RED);
        p2.add(b1);
        img1 = new ImageIcon("Customer2.png");
        Image image1 = img1.getImage();
        Image nImg1 = image1.getScaledInstance(40,40, java.awt.Image.SCALE_SMOOTH);
        img1 = new ImageIcon(nImg1);
        b1.setIcon(img1);
        img2 = new ImageIcon("Cancel.png");
        Image image2 = img2.getImage();
        Image nImg2 = image2.getScaledInstance(40,40, java.awt.Image.SCALE_SMOOTH);
        img2 = new ImageIcon(nImg2);
        b3.setIcon(img2);
        p2.add(b2);
        p2.add(b3);
        p2.setBackground(Color.GRAY);
        add(p2,BorderLayout.SOUTH);
        JPanel p = new JPanel();
        img = new ImageIcon("Customer.png");
        Image image = img.getImage();
        Image nImg = image.getScaledInstance(210,130, java.awt.Image.SCALE_SMOOTH);
        img = new ImageIcon(nImg);
        p.add(new JLabel(img));
        p.setBackground(Color.gray);
        add(p,BorderLayout.NORTH);
    }
    public void actionPerformed(ActionEvent e) {
        String a = e.getActionCommand();
        Home h;
        if (a.equals("Cancel")) {
            this.dispose();
            h = new Home();
            h.setResizable(false);
            h.setVisible(true);
        }
        if (a.equals("Sign Up")) {
            if(t1.getText().isEmpty()&&t2.getText().isEmpty()&&t3.getText().isEmpty()&&t4.getText().isEmpty()
                    &&t5.getText().isEmpty()){
                JOptionPane.showMessageDialog(new JFrame(), "Try Again!!! One of the fields is empty");
            }
            else{
                Admin ad = new Admin(t1.getText(),t3.getText());
                try
                {
                    FileOutputStream file = new FileOutputStream("Login.ser");
                    ObjectOutputStream out = new ObjectOutputStream(file);
                    out.writeObject(ad);
                    out.close();
                    file.close();
                }
                catch(IOException ex)
                {
                    JOptionPane.showMessageDialog(new JFrame(), "Sorry!!! Here is I/O Exception");
                }
                JOptionPane.showMessageDialog(new JFrame(), "Signed Up Successfully");
                this.dispose();
                h = new Home();
                h.setResizable(false);
                h.setVisible(true);

            }
        }
        if(a.equals("Reset")){
            t1.setText("");
            t2.setText("");
            t3.setText("");
            t4.setText("");
            t5.setText("");
            pass.setText("");
        }
    }
}