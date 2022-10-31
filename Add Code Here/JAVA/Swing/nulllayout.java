import javax.swing.JButton;
import javax.swing.JFrame;
import java.awt.Container;

public class nulllayout {
    public static void main(String[] args) {
        JFrame f = new JFrame();
        f.setVisible(true);

        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        f.setBounds(300,300,500,500);

        Container c = f.getContentPane();
        c.setLayout(null);

        JButton b1 = new JButton("Button 1");
        JButton b2 = new JButton("Button 2");
        JButton b3 = new JButton("Button 3");
        JButton b4 = new JButton("Button 4");
        JButton b5 = new JButton("Button 5");

        b1.setBounds(20,20,80,30);
        b2.setBounds(120,20,80,30);
        b4.setBounds(20,100,80,30);
        b3.setBounds(220,20,80,30);
        b5.setBounds(120,100,80,30);

        c.add(b1);
        c.add(b2);
        c.add(b3);
        c.add(b4);
        c.add(b5);
    }
}
