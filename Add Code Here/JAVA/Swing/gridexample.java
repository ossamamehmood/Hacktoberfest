import java.awt.Container;
import java.awt.LayoutManager;
import java.awt.*;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.*;

public class gridexample {
    
    public static void main(String[] args) {
        JFrame f = new JFrame();
        f.setVisible(true);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        f.setBounds(300,300,500,500);
      

       JButton b1 = new JButton("Button 1");
       JButton b2 = new JButton("Button 2");
       JButton b3 = new JButton("Button 3");
       JButton b4 = new JButton("Button 4");
       JButton b5 = new JButton("Button 5");

       f.add(b1);
       f.add(b2);
       f.add(b3);
       f.add(b4);
       f.add(b5);

       f.setLayout(new GridLayout());

    }
}
