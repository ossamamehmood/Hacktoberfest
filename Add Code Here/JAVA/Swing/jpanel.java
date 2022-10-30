import java.awt.Color;
import java.lang.ProcessBuilder.Redirect;

import javax.swing.JFrame;
import javax.swing.JPanel;

public class jpanel {
    public static void main(String[] args) {
        JFrame obj = new JFrame();
        obj.setVisible(true);

        obj.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        obj.setBounds(300,300,500,500);

        JPanel obj2 = new JPanel();
        obj.add(obj2);
        obj.setLayout(null);
        obj2.setSize(200,200);
        obj2.setLocation(140,140);
        obj2.setBackground(Color.CYAN);
        obj2.setVisible(true);
    }
}
