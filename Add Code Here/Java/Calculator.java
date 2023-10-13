import javax.swing.*;
import java.awt.*; 
public class Calculator
{
    public static void main(String args[])
    {
        JFrame frame=new JFrame("Calculator");
        frame.setSize(348,400);
        frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE); 
        JPanel panel1 =new JPanel();
        JPanel panel2 =new JPanel();
        JPanel panel3 =new JPanel();
        JPanel panel4 =new JPanel();
        frame.add(panel2);
        panel2.add(panel1);
        panel2.add(panel3);
        panel2.add(panel4);
        panel2.setLayout(null);
        panel4.setBounds(0,0,332,150);
        panel1.setBounds(0,150,249,211);
        panel3.setBounds(249,150,83,211);
        panel1.setBackground(Color.gray); 
        panel3.setBackground(Color.gray);
        panel4.setBackground(Color.gray);
        panel1.setLayout(new GridLayout(3,3));
        panel3.setLayout(new GridLayout(6,1));
        for(int i=1;i<10;i++)
        {
            JButton btn1=new JButton(""+i);
            panel1.add(btn1);
        }  
        JButton btn2=new JButton("+");
        JButton btn3=new JButton("-");
        JButton btn4=new JButton("*");
        JButton btn5=new JButton("/");
        JButton btn6=new JButton("=");
        JButton btn7=new JButton("0");
        panel3.add(btn2);
        panel3.add(btn3);
        panel3.add(btn4);
        panel3.add(btn5);
        panel3.add(btn6);
        panel3.add(btn7);
        frame.setVisible(true);
    }
}
