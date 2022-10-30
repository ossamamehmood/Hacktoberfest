import javax.swing.*;
import java.awt.Container;
import java.awt.*;

public class jtf {
    public static void main(String[] args) {
        
        JFrame obj = new JFrame();

        
        obj.setBounds(100,100,1000,500);
        obj.setTitle("Example");
        obj.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        Container c =  obj.getContentPane();
        c.setLayout(null);

        JTextField tf = new JTextField();
        tf.setBounds(100,50,120,30);

        tf.setText("HELLO...");

        Font font = new Font("Arial",Font.BOLD,15);
        tf.setFont(font);

        tf.setForeground(java.awt.Color.RED);
        tf.setBackground(java.awt.Color.pink);

        tf.setEditable(false);
    

        tf.setVisible(true);
        c.add(tf);
        obj.setVisible(true);


        JPasswordField pf = new JPasswordField();
        pf.setBounds(100,100,120,30);
        pf.setVisible(true);
        c.add(pf);



    }
}
