import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.EOFException;
import java.io.FileInputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.ObjectInputStream;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTable;
import javax.swing.border.Border;

public class LoginPage extends JFrame {
	Container c = getContentPane();
	JPanel PFlightTypes = new JPanel(null);
	JPanel PLogin = new JPanel(null);
	JPanel PFlightDetails = new JPanel(null);

	public boolean bCheck = true;

	JLabel LDomesticFlight = new JLabel("<html><B>Domestic Flights &nbsp;</B></html>");
	JLabel LInternationalFlight = new JLabel("<html><B>| &nbsp;  International Flights</B></html>");
	JLabel LDomesticFlight0 = new JLabel("<html><B  style='color:red;'>Domestic Flights &nbsp;</B></html>");
	JLabel LInternationalFlight0 = new JLabel(
			"<html><B  style='color:red;'>| &nbsp;  International Flights</B></html>");

	JLabel LUserName, LPassword;

	JLabel LDomesticFlight1 = new JLabel("<html><B>Domestic Flight Booking</B></html>");
	JLabel LInternationalFlight1 = new JLabel("<html><B>International Flight Booking</B></html>");

	JLabel Historybtn = new JLabel("<html><B>History</B></html>");
	JLabel Historybtn1 = new JLabel("<html><B  style='color:red;' >History</B></html>");

	JTextField TFUserName;
	JPasswordField TPPassword;

	JButton BLogin;

	JFrame frame = new JFrame();
	JPanel panel = new JPanel();

	final Object[] col1 = { "From", "To", "Price", "Time" };
	final Object[] col2 = { "From", "To", "Price", "Time" };
	final Object[] col3 = { "From", "To", "Price", "Time" };
	final Object[] col4 = { "From", "To", "Price", "Time" };
	final Object[] col5 = { "Arrival", "Destination", "Class", "Time","Adult","Childrens","Infants","Fare" };

	final Object[][] row1 = { { "Nagpur", "Bangalore", "3125", "16:30" }, { "Nagpur", "Chennai ", "3225", "19:00" },
			{ "Nagpur", "Delhi", "1425 ", "08:30" }, { "Nagpur", "Goa", "1025 ", "09:50" },
			{ "Nagpur", "Hyderabad", "1525", "11:00" }, { "Nagpur", "Kolkata", "3825 ", "05:30" },
			{ "Nagpur", "Lucknow", "3025 ", "05:30" }, { "Nagpur", "Mumbai", "1725", "12:00" },
			{ "Nagpur", "Vishakapatnam", "3725", "19:00" } };
	final Object[][] row2 = { { "Nagpur", "Bali", "21485", "06:20" }, { "Nagpur", "Bangkok", "9000", "20:45" },
			{ "Nagpur", "Cairo", "22975", "10:25" }, { "Nagpur", "CapeTown", "42500", "16:45" },
			{ "Nagpur", "Chicago", "35000", "06:30" }, { "Nagpur", "Dubai", "12000", "08:15" },
			{ "Nagpur", "Frankfurt", "18500", "06:50" }, { "Nagpur", "HongKong", "20845", "12:00" },
			{ "Nagpur", "Istanbul", "22000", "10:45" }, { "Nagpur", "London", "22600", "14:35" },
			{ "Nagpur", "LosAngeles", "35000", "22:00" }, { "Nagpur", "Melbourne", "27800", "21:15" },
			{ "Nagpur", "New York", "32000", "08:50" }, { "Nagpur", "Paris", "18500", "18:45" },
			{ "Nagpur", "Rome", "19900", "20:00" }, { "Nagpur", "SanFrancisco", "35000", "12:00" },
			{ "Nagpur", "Shanghai", "24430", "10:15" }, { "Nagpur", "Singapore", "9000", "21:10" },
			{ "Nagpur", "Sydney", "27800", "12:00" }, { "Nagpur", "Toronto", "35000", "17:00 " } };
	final Object[][] row3 = { { "Nagpur", "Bangalore", "9375", "16:30" }, { "Nagpur", "Chennai ", "9675", "19:00" },
			{ "Nagpur", "Delhi", "4275", "08:30" }, { "Nagpur", "Goa", "3075", "09:50" },
			{ "Nagpur", "Hyderabad", "4575", "11:00" }, { "Nagpur", "Kolkata", "11475", "05:30" },
			{ "Nagpur", "Lucknow", "9075", "05:30" }, { "Nagpur", "Mumbai", "5175", "12:00" },
			{ "Nagpur", "Vishakapatnam", "11175", "19:00" } };
	final Object[][] row4 = { { "Nagpur", "Bali", "64455", "06:20" }, { "Nagpur", "Bangkok", "27000", "20:45" },
			{ "Nagpur", "Cairo", "68925", "10:25" }, { "Nagpur", "CapeTown", "37500", "16:45" },
			{ "Nagpur", "Chicago", "105000", "06:30" }, { "Nagpur", "Dubai", "36000", "08:15" },
			{ "Nagpur", "Frankfurt", "55500", "06:50" }, { "Nagpur", "HongKong", "62535", "12:00" },
			{ "Nagpur", "Istanbul", "66000", "10:45" }, { "Nagpur", "London", "67800", "14:35" },
			{ "Nagpur", "LosAngeles", "105000", "22:00" }, { "Nagpur", "Melbourne", "83400", "21:15" },
			{ "Nagpur", "New York", "96000", "08:50" }, { "Nagpur", "Paris", "55500", "18:45" },
			{ "Nagpur", "Rome", "59700", "20:00" }, { "Nagpur", "SanFrancisco", "105000", "12:00" },
			{ "Nagpur", "Sanghai", "73290", "10:15" }, { "Nagpur", "Singapore", "27000", "21:10" },
			{ "Nagpur", "Sydney", "83400", "12:00" }, { "Nagpur", "Toronto", "105000", "17:00" } };

	// try {
	// 	Save1 save1;
	// 	ObjectInputStream OIS1 = new ObjectInputStream(new FileInputStream("save1"));
	// 	do {
	// 		save1 = (Save1) OIS1.readObject();

	// 		System.out.println(save1);

	// 	} while (save1 != null);
	// 	OIS1.close();

	// }
	// catch (Exception e) {
	// 	System.out.println(e);
	// }

	final Object[][] row5 = { { "Nagpur", "Bali", "Economic", "06:20", "2", "1", "0", "", "6455"}, { "Nagpur", "Bangkok", "Economic", "08:30", "5", "0", "0", "12455"}, { "Nagpur", "London", "Business", "09:22", "3", "3", "0", "20455"}, { "Nagpur", "Dubai", "Economic", "06:50", "5", "1", "0", "", "116455"}, { "Nagpur", "Bali", "Economic", "09:20", "2", "1", "0", "", "6455"}, { "Nagpur", "Delhi", "Business", "12:20", "2", "1", "0", "", "15455"}, { "Nagpur", "Mumbi", "Economic", "06:10", "2", "1", "0", "", "8655"} };

	JTable TDomesticFlight = new JTable(row1, col1);
	JTable TInternationalFlight = new JTable(row2, col2);
	JTable TDomesticFlight1 = new JTable(row3, col3);
	JTable TInternationalFlight1 = new JTable(row4, col2);
	JTable history = new JTable(row5, col5);

	JScrollPane JSP1 = new JScrollPane(TDomesticFlight, ScrollPaneConstants.VERTICAL_SCROLLBAR_AS_NEEDED,
			ScrollPaneConstants.HORIZONTAL_SCROLLBAR_AS_NEEDED);
	JScrollPane JSP2 = new JScrollPane(TInternationalFlight, ScrollPaneConstants.VERTICAL_SCROLLBAR_AS_NEEDED,
			ScrollPaneConstants.HORIZONTAL_SCROLLBAR_AS_NEEDED);
	JScrollPane JSP3 = new JScrollPane(TDomesticFlight1, ScrollPaneConstants.VERTICAL_SCROLLBAR_AS_NEEDED,
			ScrollPaneConstants.HORIZONTAL_SCROLLBAR_AS_NEEDED);
	JScrollPane JSP4 = new JScrollPane(TInternationalFlight1, ScrollPaneConstants.VERTICAL_SCROLLBAR_AS_NEEDED,
			ScrollPaneConstants.HORIZONTAL_SCROLLBAR_AS_NEEDED);
	JScrollPane JSP5 = new JScrollPane(history, ScrollPaneConstants.VERTICAL_SCROLLBAR_AS_NEEDED,
			ScrollPaneConstants.HORIZONTAL_SCROLLBAR_AS_NEEDED);

	Icon img1 = new ImageIcon("ig/economic.jpg");
	Icon img2 = new ImageIcon("ig/business.jpg");
	Icon img3 = new ImageIcon("ig/economic1.jpg");
	Icon img4 = new ImageIcon("ig/business1.jpg");

	JLabel appname = new JLabel("<html><B style='color:gray; font-size:25px;'>Airline Ticket Booking</B></html>", img1,
			SwingConstants.LEFT);

	JLabel LEconomic = new JLabel("<html><B  style='color:red;'>| &nbsp; Economic</B></html>", img1,
			SwingConstants.LEFT);
	JLabel LBusiness = new JLabel("<html><B  style='color:red;'>Business &nbsp;</B></html>", img2, SwingConstants.LEFT);
	JLabel LEconomic1 = new JLabel("<html><B>| &nbsp; Economic</B></html>", img3, SwingConstants.LEFT);
	JLabel LBusiness1 = new JLabel("<html><B>Business&nbsp;</B></html>", img4, SwingConstants.LEFT);

	public void setData() {

		// try (ObjectInputStream OIS1 = new ObjectInputStream(new FileInputStream("save2"))) {
		// 	while(true) {
		// 		char ch;
		// 		try {
		// 			ch = OIS1.readChar();
		// 			System.out.print(ch);
		// 		} catch (EOFException e) {
		// 			System.out.println("");
		// 			System.out.println("End of file reached");
		// 			break;
		// 		} 
		// 	}
		// } catch (IOException e) {
		// 	// TODO Auto-generated catch block
		// 	e.printStackTrace();
		// }

		try {
            FileReader reader = new FileReader("save2.txt");
            int character;
 
            while ((character = reader.read()) != -1) {
                System.out.print((char) character);
            }
            reader.close();
 
        } catch (IOException e) {
            e.printStackTrace();
        }

	}

	public LoginPage() {
		WindowUtilities.setNativeLookAndFeel();
		setPreferredSize(new Dimension(796, 572));

		setData();

		PFlightTypes.setBackground(Color.white);
		PLogin.setBackground(Color.white);
		PFlightDetails.setBackground(Color.white);

		JSP1.setBounds(0, 340, 790, 200);
		JSP2.setBounds(0, 340, 790, 200);
		JSP3.setBounds(0, 340, 790, 200);
		JSP4.setBounds(0, 340, 790, 200);
		JSP5.setBounds(0, 340, 790, 200);

		Border blackline1 = BorderFactory.createTitledBorder("Domestic  - Economic");
		JSP1.setBorder(blackline1);
		Border blackline2 = BorderFactory.createTitledBorder("International - Economic");
		JSP2.setBorder(blackline2);
		Border blackline3 = BorderFactory.createTitledBorder("Domestic  - Business");
		JSP3.setBorder(blackline3);
		Border blackline4 = BorderFactory.createTitledBorder("Inernational - Business");
		JSP4.setBorder(blackline4);
		Border hist = BorderFactory.createTitledBorder("History");
		JSP5.setBorder(hist);

		PFlightTypes.setBounds(0, 0, 400, 300);
		PLogin.setBounds(400, 0, 350, 340);
		PFlightDetails.setBounds(0, 200, 400, 200);

		LUserName = new JLabel("<html><B>&nbsp; &nbsp; &nbsp; User Name </B></html>");
		LPassword = new JLabel("<html><B>&nbsp; &nbsp; &nbsp; Password </B></html>");
		TFUserName = new JTextField(10);
		TPPassword = new JPasswordField(10);
		BLogin = new JButton("Sign In");

		LUserName.setBounds(40, 140, 100, 21);
		LPassword.setBounds(40, 170, 100, 21);
		TFUserName.setBounds(150, 140, 100, 21);
		TPPassword.setBounds(150, 170, 100, 21);
		BLogin.setBounds(150, 240, 100, 25);

		LDomesticFlight1.setBounds(60, 140, 138, 20);
		LInternationalFlight1.setBounds(60, 170, 153, 20);

		PLogin.add(LUserName);
		PLogin.add(TFUserName);
		PLogin.add(LPassword);
		PLogin.add(TPPassword);
		PLogin.add(BLogin);

		// Border LoginBorder = BorderFactory.createTitledBorder("Domestic - Economic");
		// PLogin.setBorder(LoginBorder);

		PFlightDetails.add(JSP1);
		PFlightDetails.add(JSP2);
		PFlightDetails.add(JSP3);
		PFlightDetails.add(JSP4);
		PFlightDetails.add(JSP5);

		JSP1.setVisible(true);
		JSP2.setVisible(false);
		JSP3.setVisible(false);
		JSP4.setVisible(false);
		JSP5.setVisible(false);

		appname.setBounds(57, 0, 300, 150);

		LBusiness.setBounds(57, 170, 300, 25);
		LEconomic.setBounds(157, 170, 300, 25);
		LBusiness1.setBounds(57, 170, 300, 25);
		LEconomic1.setBounds(157, 170, 300, 25);

		// LBusiness.setBounds(265, 170, 300, 125);
		// LEconomic.setBounds(0, 170, 250, 125);
		// LBusiness1.setBounds(280, 200, 135, 60);
		// LEconomic1.setBounds(50, 200, 147, 60);

		PFlightTypes.add(appname);

		PFlightTypes.add(LEconomic);
		PFlightTypes.add(LBusiness);
		PFlightTypes.add(LEconomic1);
		PFlightTypes.add(LBusiness1);

		LBusiness.setVisible(false);
		LEconomic1.setVisible(false);
		LBusiness1.setVisible(true);
		LEconomic.setVisible(true);

		LDomesticFlight.setVisible(false);
		LInternationalFlight.setVisible(true);
		LDomesticFlight0.setVisible(true);
		LInternationalFlight0.setVisible(false);
		Historybtn.setVisible(true);
		Historybtn1.setVisible(false);

		LDomesticFlight.setBounds(60, 140, 100, 25);
		LInternationalFlight.setBounds(160, 140, 150, 25);
		LDomesticFlight0.setBounds(60, 140, 100, 25);
		LInternationalFlight0.setBounds(160, 140, 150, 25);

		Historybtn.setBounds(60, 200, 300, 25);
		Historybtn1.setBounds(60, 200, 300, 25);

		c.add(PFlightTypes);
		c.add(PLogin);
		c.add(PFlightDetails);

		PFlightTypes.add(LDomesticFlight);
		PFlightTypes.add(LInternationalFlight);
		PFlightTypes.add(LDomesticFlight0);
		PFlightTypes.add(LInternationalFlight0);
		PFlightTypes.add(Historybtn);
		PFlightTypes.add(Historybtn1);

		pack();
		setVisible(true);

		addWindowListener(new ExitListener());

		LDomesticFlight.addMouseListener(new mouse1(this, true));
		LInternationalFlight.addMouseListener(new mouse1(this, false));

		LDomesticFlight1.addMouseListener(new mouse3(this, true));
		LInternationalFlight1.addMouseListener(new mouse3(this, false));

		LBusiness1.addMouseListener(new mouse2(this, true));
		LEconomic1.addMouseListener(new mouse2(this, false));

		Historybtn.addMouseListener(new mouse0(this, false));
		Historybtn1.addMouseListener(new mouse0(this, false));

		BLogin.addActionListener(new button1(this));
	}

	public static void main(String args[]) {
		new LoginPage();
	}
}

class button1 implements ActionListener {
	LoginPage type;
	char[] cCheck, cPassword = { 'a', 'd', 'm', 'i', 'n', '\0' };
	JFrame f;
	String sCheck, sCheck1 = "admin";

	public button1(LoginPage type) {
		this.type = type;
	}

	public void actionPerformed(ActionEvent e) {
		cCheck = type.TPPassword.getPassword();
		sCheck = type.TFUserName.getText();
		if ((sCheck1.equals(sCheck)) && check()) {
			type.PLogin.add(type.LDomesticFlight1);
			type.PLogin.add(type.LInternationalFlight1);

			type.PLogin.remove(type.LUserName);
			type.PLogin.remove(type.TFUserName);
			type.PLogin.remove(type.LPassword);
			type.PLogin.remove(type.TPPassword);
			type.PLogin.remove(type.BLogin);

			type.c.repaint();
		} else {
			JOptionPane.showMessageDialog(null, "Invalid username or password. Try again");
		}
	}

	public boolean check() {
		if (cCheck.length >= 6 || cCheck.length < 4)
			return false;
		for (int i = 0; i <= 4; i++) {
			if (cCheck[i] != cPassword[i])
				return false;
		}
		return true;
	}
}

class mouse0 extends MouseAdapter {
	LoginPage type;
	boolean bCheck;

	public mouse0(LoginPage type, boolean bCheck) {
		this.type = type;
		this.bCheck = bCheck;
	}

	public void mouseEntered(MouseEvent e) {
		type.Historybtn.setCursor(Cursor.getPredefinedCursor(Cursor.HAND_CURSOR));
	}

	public void mouseClicked(MouseEvent e) {

		type.JSP1.setVisible(false);
		type.JSP2.setVisible(false);
		type.JSP3.setVisible(false);
		type.JSP4.setVisible(false);
		type.JSP5.setVisible(true);

		if (bCheck) {
			type.Historybtn.setVisible(true);
			type.bCheck = true;
		} else {
			type.Historybtn1.setVisible(false);
			type.bCheck = false;
		}

		System.out.println(1);
		type.LDomesticFlight.setVisible(true);
		type.LInternationalFlight.setVisible(true);
		type.LDomesticFlight0.setVisible(false);
		type.LInternationalFlight0.setVisible(false);

		type.LEconomic.setVisible(false);
		type.LBusiness1.setVisible(true);
		type.LEconomic1.setVisible(true);
		type.LBusiness.setVisible(false);

		type.JSP1.setVisible(false);
		type.JSP2.setVisible(false);
		type.JSP3.setVisible(false);
		type.JSP4.setVisible(false);
		type.JSP5.setVisible(true);

		type.Historybtn.setVisible(false);
		type.Historybtn1.setVisible(true);

	}
}

class mouse1 extends MouseAdapter {
	LoginPage type;
	boolean bCheck;

	public mouse1(LoginPage type, boolean bCheck) {
		this.type = type;
		this.bCheck = bCheck;
	}

	public void mouseEntered(MouseEvent e) {
		type.LDomesticFlight.setCursor(Cursor.getPredefinedCursor(Cursor.HAND_CURSOR));
		type.LInternationalFlight.setCursor(Cursor.getPredefinedCursor(Cursor.HAND_CURSOR));
	}

	public void mouseClicked(MouseEvent e) {
		if (bCheck)
			type.bCheck = true;
		else
			type.bCheck = false;

		type.JSP1.setVisible(false);
		type.JSP2.setVisible(false);
		type.JSP3.setVisible(false);
		type.JSP4.setVisible(false);
		type.JSP5.setVisible(false);

		type.Historybtn1.setVisible(false);
		type.Historybtn.setVisible(true);

		if (bCheck) {
			System.out.println('1');

			type.LDomesticFlight.setVisible(false);
			type.LInternationalFlight.setVisible(true);
			type.LDomesticFlight0.setVisible(true);
			type.LInternationalFlight0.setVisible(false);
			type.JSP1.setVisible(true);
		} else {
			System.out.println('2');

			type.LDomesticFlight.setVisible(true);
			type.LInternationalFlight.setVisible(false);
			type.LDomesticFlight0.setVisible(false);
			type.LInternationalFlight0.setVisible(true);
			type.JSP2.setVisible(true);
		}
	}
}

class mouse3 extends MouseAdapter {
	LoginPage type;
	boolean bCheck;

	public mouse3(LoginPage type, boolean bCheck) {
		this.type = type;
		this.bCheck = bCheck;
	}

	public void mouseEntered(MouseEvent e) {
		type.LDomesticFlight1.setCursor(Cursor.getPredefinedCursor(Cursor.HAND_CURSOR));
		type.LInternationalFlight1.setCursor(Cursor.getPredefinedCursor(Cursor.HAND_CURSOR));
	}

	public void mouseClicked(MouseEvent e) {
		if (bCheck)
			new DomesticFlight(type);
		else
			new InternationalFlight(type);
	}
}

class mouse2 extends MouseAdapter {
	LoginPage type;
	boolean bCheck;

	public mouse2(LoginPage type, boolean bCheck) {
		this.type = type;
		this.bCheck = bCheck;
	}

	public void mouseEntered(MouseEvent e) {
		type.LEconomic1.setCursor(Cursor.getPredefinedCursor(Cursor.HAND_CURSOR));
		type.LBusiness1.setCursor(Cursor.getPredefinedCursor(Cursor.HAND_CURSOR));
	}

	public void mouseClicked(MouseEvent e) {
		type.Historybtn1.setVisible(false);
		type.Historybtn.setVisible(true);
		if (type.bCheck) {
			if (bCheck) {
				type.LDomesticFlight.setVisible(false);
				type.LInternationalFlight.setVisible(true);
				type.LDomesticFlight0.setVisible(true);
				type.LInternationalFlight0.setVisible(false);
				type.LBusiness1.setVisible(false);
				type.LBusiness.setVisible(true);
				type.LEconomic.setVisible(false);
				type.LEconomic1.setVisible(true);
				type.JSP1.setVisible(false);
				type.JSP2.setVisible(false);
				type.JSP3.setVisible(true);
				type.JSP4.setVisible(false);
				type.JSP5.setVisible(false);

			} else {
				type.LDomesticFlight.setVisible(false);
				type.LInternationalFlight.setVisible(true);
				type.LDomesticFlight0.setVisible(true);
				type.LInternationalFlight0.setVisible(false);
				type.LEconomic1.setVisible(false);
				type.LBusiness.setVisible(false);
				type.LBusiness1.setVisible(true);
				type.LEconomic.setVisible(true);
				type.JSP1.setVisible(true);
				type.JSP2.setVisible(false);
				type.JSP3.setVisible(false);
				type.JSP4.setVisible(false);
				type.JSP5.setVisible(false);
			}
		} else {
			if (bCheck) {
				type.LDomesticFlight.setVisible(true);
				type.LInternationalFlight.setVisible(false);
				type.LDomesticFlight0.setVisible(false);
				type.LInternationalFlight0.setVisible(true);
				type.LBusiness1.setVisible(false);
				type.LBusiness.setVisible(true);
				type.LEconomic.setVisible(false);
				type.LEconomic1.setVisible(true);
				type.JSP1.setVisible(false);
				type.JSP2.setVisible(false);
				type.JSP3.setVisible(false);
				type.JSP4.setVisible(true);
				type.JSP5.setVisible(false);
			} else {
				type.LDomesticFlight.setVisible(true);
				type.LInternationalFlight.setVisible(false);
				type.LDomesticFlight0.setVisible(false);
				type.LInternationalFlight0.setVisible(true);
				type.LEconomic1.setVisible(false);
				type.LBusiness.setVisible(false);
				type.LBusiness1.setVisible(true);
				type.LEconomic.setVisible(true);
				type.JSP1.setVisible(false);
				type.JSP2.setVisible(true);
				type.JSP3.setVisible(false);
				type.JSP4.setVisible(false);
				type.JSP5.setVisible(false);
			}
		}
	}
}
