
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.*;





public class Calculator extends JFrame implements ActionListener 
{
	JLabel lbl1;
	JTextField txt1,txt2,txt3,txt4;
	JButton btn1,btn2,btn3,btn4,btn5,btn6,btn7,btn8,btn9,btn10,btn11,btn12,btn13;


	
	int retrieve(String s)
	{
		byte[] b = s.getBytes();
		int num = 0;
		for(byte i:b)
		{
			num = num*10+(i-48);
		}
		return num;
		
	}
	String dtx(int num,int ind)
	{
		int[] list = {2,8,16};
		char[] c = {'A','B','C','D','E'};
		int r=0;
		StringBuilder s = new StringBuilder();
		while(num != 0)
		{
			r = num%list[ind];
			if(r>9)
			{
				System.out.println(s);
				s.append(c[r%10]);
				System.out.println(s);
			}
			else
			{
				s.append(r);
			}
			num = num/list[ind];
		}
		
		return s.reverse().toString();
	}
	String xtd(String num,int ind)
	{
		int[] a = {2,8,16};
		byte[] b = num.getBytes();
		int j=b.length-1,sum = 0;
		for(byte i :b)
		{
			if(i==65 || i==66 || i==67 || i==68 || i==69 || i==70)
			{
				i = (byte) (i-7) ;
			}
			else if(i==97 || i==98 || i==99 || i==100 || i==101 || i==102)
			{
				i = (byte) (i-39) ;
			}
			sum = (int)(sum + (i-48)*Math.pow(a[ind], j));
			System.out.println(sum);
			j--;
		}
		return String.valueOf(sum);
	}
	void label(JLabel p,String s,int a,int b,int c,int d)
	{
		p = new JLabel(s);
		p.setBounds(a,b,c,d);
		super.add(p);
	}
	JTextField txtfield(JTextField txtf,int a,int b,int c,int d)
	{
		txtf = new JTextField();
		txtf.setBounds(a,b,c,d);
		super.add(txtf);
		return txtf;
	}
	JButton btn(JButton jbtn,String s,int a,int b,int c,int d)
	{
		jbtn = new JButton(s);
		jbtn.setBounds(a,b,c,d);
		super.add(jbtn);
		jbtn.addActionListener(this);
		return jbtn;
	}
	void setui()
	{
		super.setBounds(300,200,600,500);
		super.setTitle("Calculator");
		super.setResizable(false);
		//----------------------------------------------------------------------
		//@adding labels and textfields
		
		label(lbl1,"Enter First Value : ",40,20,200,25);
		txt1 = txtfield(txt1,260,20,300,25);
		
		label(lbl1,"Enter Second Value : ",40,50,200,25);
		txt2 = txtfield(txt2,260,50,300,25);
		
		label(lbl1,"Result : ",40,80,200,25);
		txt3 = txtfield(txt3,260,80,300,25);
		
		label(lbl1,"Operation : ",40,110,200,25);
		txt4 = txtfield(txt4,260,110,300,25);

		
		//----------------------------------------------------------------------
		btn1 = btn(btn1,"+",70,200,60,30);
		
		btn2 = btn(btn2,"-",170,200,60,30);
		btn3 = btn(btn3,"*",270,200,60,30);
		btn4 = btn(btn4,"/",370,200,60,30);
		btn5 = btn(btn5,"%",470,200,60,30);
		//-------------------------------------------------------------------------
		btn6 = btn(btn6,"D to B",130,260,80,30);
		btn7 = btn(btn7,"D to H",250,260,80,30);
		btn8 = btn(btn8,"D to O",370,260,80,30);
		//-------------------------------------------------------------------------
		btn9 = btn(btn9,"B to D",130,320,80,30);
		btn10 = btn(btn10,"H to D",250,320,80,30);
		btn11 = btn(btn11,"O to D",370,320,80,30);
		//-------------------------------------------------------------------------
		btn12 = btn(btn12,"Reset",200,380,80,30);
		btn13 = btn(btn13,"Exit",320,380,80,30);
		//-------------------------------------------------------------------------
		super.setLayout(null);
		super.setVisible(true);
		super.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
	}
	public static void main(String[] args) {
		Calculator a = new Calculator();
		a.setui();
	}

	

	@Override
	public void actionPerformed(ActionEvent e) {


		int getf1 = retrieve(txt1.getText());
		int getf2 = retrieve(txt2.getText());
		
	
		
		System.out.println(e.getSource());
		if(e.getSource()==btn1)
		{
			txt3.setText(String.valueOf(getf1+getf2));
			txt4.setText("+");
		}
		else if(e.getSource()==btn2)
		{
			txt3.setText(String.valueOf(getf1-getf2));
			txt4.setText("-");
		}
		else if(e.getSource()==btn3)
		{
			txt3.setText(String.valueOf(getf1*getf2));
			txt4.setText("*");
		}
		else if((e.getSource() == btn4 || e.getSource() == btn5) && getf2 == 0)
		{
			txt3.setText("Undefined");
			JOptionPane.showMessageDialog(txt4,"Zero Devision Error");
		}
		else if(e.getSource()==btn4 && getf2 !=0)
		{
			txt3.setText(String.valueOf(getf1/getf2));
			txt4.setText("/");
		}
		else if(e.getSource()==btn5 && getf2!=0)
		{
			txt3.setText(String.valueOf(getf1%getf2));
			txt4.setText("Remainder");
		}
		else if(e.getSource() == btn6)
		{
			txt3.setText(dtx(getf1,0));
			txt4.setText("Decimal To Decimal Converter");
		}
		else if(e.getSource() == btn7)
		{
			txt3.setText(dtx(getf1,2));
			txt4.setText("Decimal To HexaDecimal Converter");
		}
		else if(e.getSource() == btn8)
		{
			txt3.setText(dtx(getf1,1));
			txt4.setText("Decimal To Octal Converter");
		}
		else if(e.getSource() == btn9)
		{
			txt3.setText(xtd(txt1.getText(),0));
			txt4.setText("Binary To Decimal Converter");
		}
		else if(e.getSource() == btn10)
		{
			txt3.setText(xtd(txt1.getText(),2));
			txt4.setText("HexaDecimal To Decimal Converter");
		}
		else if(e.getSource() == btn11)
		{
			txt3.setText(xtd(txt1.getText(),1));
			txt4.setText("Octal To Decimal Converter");
		}
		else if(e.getSource() == btn12)
		{
			txt1.setText("");
			txt2.setText("");
			txt3.setText("");
			txt4.setText("");
		}
		else  
		{
			System.exit(0);
		}
	}
}
