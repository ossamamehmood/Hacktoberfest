package Calculator;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class Calculator extends JFrame implements ActionListener {
    String str = "";
    float re = 0;
    char d, f;
    static JButton b1 = new JButton("1");
    JButton b2 = new JButton("2");
    JButton b3 = new JButton("3");
    JButton b4 = new JButton("4");
    JButton b5 = new JButton("5");
    JButton b6 = new JButton("6");
    JButton b7 = new JButton("7");
    JButton b8 = new JButton("8");
    JButton b9 = new JButton("9");
    JButton b0 = new JButton("0");
    JButton ba = new JButton("+");
    JButton bm = new JButton("-");
    JButton bd = new JButton("/");
    JButton bmu = new JButton("*");
    JButton be = new JButton("=");
    JButton bdo = new JButton(".");
    JButton bdel = new JButton("Delete");
    JTextField t = new JTextField();

    public Calculator() {
        setTitle("Calculator");
        setVisible(true);
        setSize(300, 426);
        b1.addActionListener(this);
        b1.setBounds(10, 88, 57, 48);
        getContentPane().add(b1);
        b2.addActionListener(this);
        b2.setLocation(77, 88);
        b2.setSize(57, 48);
        getContentPane().add(b2);
        b3.addActionListener(this);
        b3.setSize(57, 48);
        b3.setLocation(144, 88);
        getContentPane().add(b3);
        b4.addActionListener(this);
        b4.setLocation(10, 145);
        b4.setSize(57, 48);
        getContentPane().add(b4);
        b5.addActionListener(this);
        b5.setLocation(77, 145);
        b5.setSize(57, 48);
        getContentPane().add(b5);
        b6.addActionListener(this);
        b6.setLocation(144, 145);
        b6.setSize(57, 48);
        getContentPane().add(b6);
        b7.addActionListener(this);
        b7.setLocation(10, 204);
        b7.setSize(57, 48);
        getContentPane().add(b7);
        b8.addActionListener(this);
        b8.setLocation(77, 204);
        b8.setSize(57, 48);
        getContentPane().add(b8);
        b9.addActionListener(this);
        b9.setLocation(144, 204);
        b9.setSize(57, 48);
        getContentPane().add(b9);
        b0.addActionListener(this);
        b0.setLocation(77, 263);
        b0.setSize(57, 48);
        getContentPane().add(b0);
        ba.addActionListener(this);
        ba.setLocation(211, 88);
        ba.setSize(57, 48);
        getContentPane().add(ba);
        bm.addActionListener(this);
        bm.setLocation(211, 145);
        bm.setSize(57, 48);
        getContentPane().add(bm);
        bd.addActionListener(this);
        bd.setLocation(211, 204);
        bd.setSize(57, 48);
        getContentPane().add(bd);
        bmu.addActionListener(this);
        bmu.setLocation(211, 263);
        bmu.setSize(57, 48);
        getContentPane().add(bmu);
        be.addActionListener(this);
        be.setLocation(144, 263);
        be.setSize(57, 48);
        getContentPane().add(be);
        bdo.addActionListener(this);
        bdo.setLocation(10, 263);
        bdo.setSize(57, 48);
        getContentPane().add(bdo);
        bdel.addActionListener(this);
        bdel.setLocation(10, 322);
        bdel.setSize(258, 48);
        getContentPane().add(bdel);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        getContentPane().setLayout(null);
        t.setToolTipText("");
        t.setBackground(new Color(255, 255, 255));
        t.setFont(new Font("Arial", t.getFont().getStyle(), t.getFont().getSize() + 7));
        t.setHorizontalAlignment(SwingConstants.RIGHT);
        t.setBounds(10, 11, 258, 66);
        getContentPane().add(t);
        t.setColumns(10);
    }
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == b1) {
            str = str + "1";
            t.setText(str);
        }
        if (e.getSource() == b2) {
            str = str + "2";
            t.setText(str);
        }
        if (e.getSource() == b3) {
            str = str + "3";
            t.setText(str);
        }
        if (e.getSource() == b4) {
            str = str + "4";
            t.setText(str);
        }
        if (e.getSource() == b5) {
            str = str + "5";
            t.setText(str);
        }
        if (e.getSource() == b6) {
            str = str + "6";
            t.setText(str);
        }
        if (e.getSource() == b7) {
            str = str + "7";
            t.setText(str);
        }
        if (e.getSource() == b8) {
            str = str + "8";
            t.setText(str);
        }
        if (e.getSource() == b9) {
            str = str + "9";
            t.setText(str);
        }
        if (e.getSource() == b0) {
            str = str + "0";
            t.setText(str);
        }
        if (e.getSource() == bdo) {
            str = str + ".";
        }
        if (e.getSource() == ba) {
            if (re == 0) {
                re = Float.parseFloat(str);
                str = "";
                d = '+';
                f = '0';
            } else {
                if (f == '0') {
                    cal();
                    str = "";
                    f = '1';
                } else {
                    re = re + (Float.parseFloat(str));
                    str = "";
                    f = '1';
                }
                d = '+';
            }
        }
        if (e.getSource() == bm) {
            if (re == 0) {
                re = Float.parseFloat(str);
                str = "";
                d = '-';
                f = '0';
            } else {
                if (f == '0') {
                    cal();
                    str = "";
                    f = '1';
                } else {
                    re = re - (Float.parseFloat(str));
                    str = "";
                    f = '1';
                }
                d = '-';
            }

        }
        if (e.getSource() == bd) {
            if (re == 0.0000000) {
                re = Float.parseFloat(str);
                str = "";
                d = '/';
                f = '0';
            } else {
                if (f == '0') {
                    cal();
                    str = "";
                    f = '1';
                } else {
                    re = re / (Float.parseFloat(str));
                    str = "";
                    f = '1';
                }
                d = '/';
            }

        }
        if (e.getSource() == bmu) {
            if (re == 0) {
                re = Float.parseFloat(str);
                str = "";
                d = '*';
                f = '0';
            } else {
                if (f == '0') {
                    cal();
                    str = "";
                    f = '1';
                } else {
                    re = re * (Float.parseFloat(str));
                    str = "";
                    f = '1';
                }
                d = '*';
            }

        }

        if (e.getSource() == be) {
            switch (d) {
                case '+':
                    {
                        re = re + (Float.parseFloat(str));
                        break;
                    }
                case '-':
                    {
                        re = re - (Float.parseFloat(str));
                        break;
                    }
                case '/':
                    {
                        re = re / (Float.parseFloat(str));
                        break;
                    }
                case '*':
                    {
                        re = re * (Float.parseFloat(str));
                        break;
                    }
                default:break;
            }

            str = Float.toString(re);
            t.setText(str);
        }
        if (e.getSource() == bdel) {
            int l = str.length();
            if (l == 0) {
                str = "";
                re = 0;
            } else {
                str = str.substring(0, (l - 1));

            }
            t.setText(str);
        }
    }
    public void cal() {
        switch (d) {
            case '+':
                {
                    re = re + (Float.parseFloat(str));
                    break;
                }
            case '-':
                {
                    re = re - (Float.parseFloat(str));
                    break;
                }
            case '/':
                {
                    re = re / (Float.parseFloat(str));
                    break;
                }
            case '*':
                {
                    re = re * (Float.parseFloat(str));
                    break;
                }
            default:break;
        }

    }
    public static void main(String args[]) {
        Calculator n = new Calculator();

    }
}
