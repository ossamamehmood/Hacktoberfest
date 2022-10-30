import java.awt.Container;
import java.awt.LayoutManager;
import java.awt.*;
import javax.swing.JButton;
import javax.swing.JFrame;

public class flowexample extends JFrame {

    JButton b1 = new JButton("Button 1");
    JButton b2 = new JButton("Button 2");
    JButton b3 = new JButton("Button 3");
    JButton b4 = new JButton("Button 4");
    JButton b5 = new JButton("Button 5");

    public  flowexample() {
        setTitle("Flow Layout Example");
        setBounds(100,200,500,300);
        setVisible(true);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        Container c = getContentPane();

        c.add(b1);
        c.add(b2);
        c.add(b3);
        c.add(b4);
        //c.add(b5);

        FlowLayout f = new FlowLayout();
        c.setLayout((LayoutManager) f);
        
       
    }

    public static void main(String[] args) {
       new flowexample();
    }
}
