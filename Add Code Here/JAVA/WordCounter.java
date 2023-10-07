//Hactoberfest 2023  Soumen Pathak
import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
public class Wordcounter{

    JLabel w,c;
    JButton b;
    JTextArea a;
    Wordcounter()
    {
        JFrame j=new JFrame("Word Counter");
        w=new JLabel();
        c=new JLabel();
        a=new JTextArea();
        b=new JButton("Count");
        w.setBounds(50,25,100,30);
        c.setBounds(160,25,300,30);
        a.setBounds(20,50,350,200);
        b.setBounds(50,300,150,50);
        b.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String txt=a.getText();
                String words[]=txt.split("\\s");
                w.setText("Word Count:"+words.length);
                c.setText("Character Count:"+txt.length());
            }
        });
        j.add(w);
        j.add(c);
        j.add(a);
        j.add(b);
        j.setSize(1000, 1000);
        j.setLayout(null);
        j.setVisible(true);
        j.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }



    public static void main(String[] args) {
         new Wordcounter();
    }
}
