/*6. Program that creates a user interface to perform basic integer operations.
the user enters two numbers in the TextFields- num1 and num2. The result of
operations must be displayed in the Result TextField when the "=" button is
clicked. appropriate exception handling message to be displayed in the Result
TextField when num1 or num2 is not an integer or num2 is zero when division
operation is applied.*/

//Source Code:
/* Develop an applet to perform division */
import java.awt.*;
import java.applet.*;
import java.awt.event.*;
import javax.swing.*;
/*<applet code="DivisionApplet" width=600 height=200>
</applet>*/
public class DivisionApplet extends Applet implements ActionListener {
Label L1,L2,L3;
TextField T1,T2,Result;
Button B1;
public void init() {
L1=new Label("Enter First Num :");
add(L1);
T1=new TextField(10);
add(T1);
L2=new Label("Enter Second Num :");
add(L2);
T2=new TextField(10);

add(T2);
L3=new Label("result");
add(L3);
Result=new TextField(10);
add(Result);
B1=new Button("Divide / =");
add(B1);
B1.addActionListener(this);
}
public void actionPerformed(ActionEvent e) {
if(e.getSource()==B1) {
try {
int value1=Integer.parseInt(T1.getText());
int value2=Integer.parseInt(T2.getText());
int result=value1/value2;
Result.setText(String.valueOf(result));
}
catch(NumberFormatException nfe) {
JOptionPane.showMessageDialog(this,"Not a number");
}
catch(ArithmeticException ae) {
JOptionPane.showMessageDialog(this,"Divided by Zero");
}
}
}
}