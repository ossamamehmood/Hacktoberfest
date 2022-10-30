import java.awt.*;
import javax.swing.*;

public class textfield {
    public static void main(String[] args) {
        JFrame f = new JFrame();
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        f.setBounds(300,300,700,500);
        Container c = f.getContentPane();
       c.setLayout(null);
      

        // JPasswordField t1 = new JPasswordField();
        // t1.setBounds(100,50,120,30);
        // JTextField t2 = new JTextField("Message");
        // t2.setBounds(200,100,120,30);
        // c.add(t1);
        // c.add(t2);

        // t1.setText("New Message");
        // String s = t2.getText();
        // t2.setEditable(false);

        // JTextArea a = new JTextArea();
        // a.setBounds(100,100,400,200);
        // c.add(a);
      
        // JCheckBox ch = new JCheckBox("Happy");
        // ch.setBounds(100,50,20,20);
        // JCheckBox ch2 = new JCheckBox("SAD");

        // c.add(ch);
        // c.add(ch2);


        // JRadioButton r1 = new JRadioButton("Male");
        // //c.setBounds(100,50,100,20);
        // c.add(r1);
        // JRadioButton r2 = new JRadioButton("Female");
        // //c.setBounds(100,100,100,20);
        // c.add(r2);
        
        // String[] values = {"A","B","C","D","E"};
        // JComboBox combo = new JComboBox<>(values);
        // combo.setBounds(100,100,100,30);
        // combo.setSelectedItem("D");
        // c.add(combo);


        String [] val = {"Sahil","Rathod","Jaymini"};
        JList l = new JList<>(val);
        l.setBounds(100,100,100,20);
        c.add(l);


        
        f.setVisible(true);

    }
}
