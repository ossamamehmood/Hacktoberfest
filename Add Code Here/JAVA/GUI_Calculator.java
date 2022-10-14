import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;

public class Calculator extends JFrame implements ActionListener{
	
	JPanel p;
	JLabel l1,l2,l3,l4;
	JTextField f1,f2;
	JButton btn1, btn2,btn3,btn4,btn5;
	
	int s1, s2;
	int result = 0;
	
	public Calculator() {
		p = new JPanel(null);
		l1 = new JLabel("1st NO.");
		l2 = new JLabel("2nd NO.");
		l3 = new JLabel("RESULT: ");
		l4 = new JLabel();
		
		f1 = new JTextField();
		f2 = new JTextField();
		
		btn1 = new JButton("ADD");
		btn2 = new JButton("SUBTRACT");
		btn3 = new JButton("MULTIPLY");
		btn4 = new JButton("DIVIDE");
		btn5 = new JButton("CLEAR");
		
		l1.setBounds(20, 20, 100, 30);
		l2.setBounds(20, 50, 100, 30);
		l3.setBounds(20, 100, 100, 30);
		l4.setBounds(150, 100, 100, 30);
		
		f1.setBounds(150, 20, 100, 30);
		f2.setBounds(150, 50, 100, 30);
		
		
		btn1.setBounds(20, 140, 100, 30);
		btn2.setBounds(150, 140, 100, 30);
		btn3.setBounds(20, 180, 100, 30);
		btn4.setBounds(150, 180, 100, 30);
		btn5.setBounds(80, 220, 100, 30);
		
		p.add(l1);
		p.add(l2);
		p.add(l3);
		p.add(l4);
		
		p.add(f1);
		p.add(f2);
		
		p.add(btn1);
		p.add(btn2);
		p.add(btn3);
		p.add(btn4);
		p.add(btn5);
		
		add(p);
		
		setSize(400, 400);
		setTitle("calculator");
		setVisible(true);
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		
		btn1.addActionListener(this);
		btn2.addActionListener(this);
		btn3.addActionListener(this);
		btn4.addActionListener(this);
		btn5.addActionListener(this);
		
		
	}
	
	public static void main(String[] args)
	{
		Calculator f = new Calculator();
	}

	@Override
	public void actionPerformed(ActionEvent ae) {
	
		
		try {
			
		
		if(ae.getSource().equals(btn1)) {
			
			s1 = Integer.parseInt(f1.getText());
			s2 = Integer.parseInt(f2.getText());
			
			
			result = s1 + s2;
			
			l4.setText(Integer.toString(result));
			
		}
		
		else if(ae.getSource().equals(btn2)) {
			
			s1 = Integer.parseInt(f1.getText());
			s2 = Integer.parseInt(f2.getText());
			
			
			result = s1 - s2;
			
			l4.setText(Integer.toString(result));
			
		}
			else if(ae.getSource().equals(btn3)) {
						
						s1 = Integer.parseInt(f1.getText());
						s2 = Integer.parseInt(f2.getText());
						
						
						result = s1 * s2;
						
						l4.setText(Integer.toString(result));
						
		}
			else if(ae.getSource().equals(btn4)) {
				
				s1 = Integer.parseInt(f1.getText());
				s2 = Integer.parseInt(f2.getText());
				
				
				result = s1 / s2;
				
				l4.setText(Integer.toString(result));
				
			}
			else if(ae.getSource().equals(btn5)) {
				
				f1.setText("");
				f2.setText("");
				l4.setText("");
				
				
			}
		
		}
		catch(NumberFormatException ex) {
			
			System.out.println("Please Input Intger Value");
		}
		}
}
