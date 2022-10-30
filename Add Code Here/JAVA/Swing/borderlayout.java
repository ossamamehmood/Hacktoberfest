import java.awt.BorderLayout;
import java.awt.Container;
import javax.swing.JButton;
import javax.swing.JFrame;

public class borderlayout {
    public static void main(String[] args) {
        JFrame f = new JFrame();
        f.setVisible(true);

        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        f.setBounds(300,300,500,500);

        Container c = f.getContentPane();

        BorderLayout bl = new BorderLayout(10,8);
        c.setLayout(bl);
    
        JButton b1 = new JButton("PAGE_START");
        JButton b2 = new JButton("PAGE_END");
        JButton b3 = new JButton("LINE_START");
        JButton b4 = new JButton("LINE_END");
        JButton b5 = new JButton("CENTER");

        c.add(b1,BorderLayout.PAGE_START);
        c.add(b2,BorderLayout.PAGE_END);
        c.add(b3,BorderLayout.LINE_START);
        c.add(b4,BorderLayout.LINE_END);
        c.add(b5,BorderLayout.CENTER);




        
    }
}
