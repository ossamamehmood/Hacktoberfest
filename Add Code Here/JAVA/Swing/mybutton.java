import java.awt.*;
import javax.swing.*;

public class mybutton {
    public static void main(String[] args) {
        JFrame  obj = new JFrame();
        obj.setBounds(100,100,1000,500);
        Container c = obj.getContentPane();
        c.setLayout(null);


        JButton btn = new JButton("ClickMe");
        btn.setSize(100,30);
        btn.setLocation(100,100);
        btn.setEnabled(false);
    
        c.add(btn);
        btn.setVisible(true);
        obj.setVisible(true);

    }
}
