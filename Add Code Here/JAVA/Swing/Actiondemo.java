import javax.swing.*;
import javax.swing.event.AncestorEvent;
import javax.swing.event.AncestorListener;
import javafx.event.ActionEvent;
import javafx.scene.paint.Color;
import java.awt.*;



class MyFrame extends JFrame implements AncestorListener {

    Container c;
    JButton b;

    MyFrame(){
        c = this.getContentPane();
        c.setLayout(null);

        b = new JButton("ClickMe");
        b.setBounds(100,100,100,50);
        c.add(b);

    }

    public void ActionPerformed(ActionEvent e){

      c.setBackground(Color.YELLOW);

    }
 

}


public class Actiondemo {
    public static void main(String[] args) {
        
        MyFrame f = new MyFrame();

        f.setTitle("ActionDemo");
        f.setSize(700,500);
        f.setLocation(100,100);
        f.setVisible(true);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

    }
}
