import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Login extends JFrame implements ActionListener {
    JLabel l1, l2;
    JTextField t1, t2, t3;
    JButton b1, b2;

    Login() {
        l1 = new JLabel("User-ID");
        l2 = new JLabel("Password");

        t1 = new JTextField();
        t2 = new JTextField();
        t3 = new JTextField();

        b1 = new JButton("Login");
        b2 = new JButton("Register");

        b1.addActionListener(this);
        b2.addActionListener(this);
    }

    public void actionPerformed(ActionEvent ae) {
        if (ae.getmodel() == b1)
            t3.setText(t1.getText() + t2.getText());

        else
            t3.setText(" ");
        t1.setText(" ");
        t2.setText(" ");
    }


    public static void main(String[] args) {
        Login obj = new Login();
        obj.setBounds(300,300,500,500);
        obj.setVisible(true);
        obj.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

}