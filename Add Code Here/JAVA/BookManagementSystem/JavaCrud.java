 import java.awt.EventQueue;
 import java.sql.*;

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;

import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JPanel;
import javax.swing.border.TitledBorder;

import net.proteanit.sql.DbUtils;

import javax.swing.JTextField;
import javax.swing.JButton;
import javax.swing.border.EtchedBorder;
import java.awt.Color;
import javax.swing.JTabbedPane;
import javax.swing.JTable;
import javax.swing.JScrollPane;
import javax.swing.JTextPane;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;

public class JavaCrud {
	private JFrame frame;
	private JTextField txtbookname;
	private JTextField txtedition;
	private JTextField txtprice;
	private JTextField txtID;
	Connection con;
	PreparedStatement pst;
	ResultSet res;
	private JTextField txtbookid;
	private JTable table;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					JavaCrud window = new JavaCrud();
					window.frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the application.
	 */
	public JavaCrud() {
		initialize();
		Connect();
		LoadTable();
	}
	
	public void Connect() {
		try {
			Class.forName("com.mysql.cj.jdbc.Driver");
			con = DriverManager.getConnection("jdbc:mysql://localhost:3306/book", "root","imdevesh1403");
		}
		catch(Exception e) {
			e.printStackTrace();
		}
	}

	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize() {
		frame = new JFrame();
		frame.getContentPane().setFont(new Font("Times New Roman", Font.PLAIN, 18));
		frame.setBounds(100, 100, 1008, 641);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.getContentPane().setLayout(null);
		
		JLabel lblNewLabel = new JLabel("Book Shop");
		lblNewLabel.setFont(new Font("Calibri", Font.BOLD, 30));
		lblNewLabel.setBounds(427, 27, 133, 60);
		frame.getContentPane().add(lblNewLabel);
		
		JPanel panel = new JPanel();
		panel.setBorder(new TitledBorder(new EtchedBorder(EtchedBorder.LOWERED, new Color(255, 255, 255), new Color(160, 160, 160)), "Registration", TitledBorder.CENTER, TitledBorder.TOP, null, new Color(0, 0, 0)));
		panel.setBounds(38, 128, 395, 230);
		frame.getContentPane().add(panel);
		panel.setLayout(null);
		
		JLabel lblNewLabel_1 = new JLabel("Book ID");
		lblNewLabel_1.setFont(new Font("Tahoma", Font.BOLD, 16));
		lblNewLabel_1.setBounds(28, 49, 88, 21);
		panel.add(lblNewLabel_1);
		
		JLabel lblNewLabel_1_1 = new JLabel("Name");
		lblNewLabel_1_1.setFont(new Font("Tahoma", Font.BOLD, 16));
		lblNewLabel_1_1.setBounds(28, 80, 47, 25);
		panel.add(lblNewLabel_1_1);
		
		JLabel lblNewLabel_1_1_1 = new JLabel("Price");
		lblNewLabel_1_1_1.setFont(new Font("Tahoma", Font.BOLD, 16));
		lblNewLabel_1_1_1.setBounds(28, 172, 42, 25);
		panel.add(lblNewLabel_1_1_1);
		
		txtbookname = new JTextField();
		txtbookname.setBounds(161, 82, 184, 25);
		panel.add(txtbookname);
		txtbookname.setColumns(10);
		
		txtedition = new JTextField();
		txtedition.setColumns(10);
		txtedition.setBounds(161, 115, 184, 25);
		panel.add(txtedition);
		
		txtprice = new JTextField();
		txtprice.setColumns(10);
		txtprice.setBounds(161, 174, 184, 25);
		panel.add(txtprice);
		
		JLabel lblNewLabel_1_2 = new JLabel("Edition");
		lblNewLabel_1_2.setFont(new Font("Tahoma", Font.BOLD, 16));
		lblNewLabel_1_2.setBounds(28, 115, 57, 21);
		panel.add(lblNewLabel_1_2);
		
		txtbookid = new JTextField();
		txtbookid.setColumns(10);
		txtbookid.setBounds(161, 49, 184, 25);
		panel.add(txtbookid);
		
		JButton btnSave = new JButton("Save");
		btnSave.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				String name,edition,price,id;
				
				name = txtbookname.getText().toString();
				edition = txtedition.getText().toString();
				price = txtprice.getText().toString();
				id = txtbookid.getText().toString();
				
				if(!name.isEmpty() && !edition.isEmpty() && !price.isEmpty() && !id.isEmpty()) {
				
				try {
					pst = con.prepareStatement("insert into books(id,name,edition,price)values(?,?,?,?)");
					pst.setString(1,id);
					pst.setString(2, name);
					pst.setString(3, edition);
					pst.setString(4, price);
					pst.executeUpdate();
					JOptionPane.showMessageDialog(null, "Record Added!");
					LoadTable();
					txtbookid.setText("");
					txtbookname.setText("");
					txtedition.setText("");
					txtprice.setText("");
					
				}catch(Exception e2) {
					e2.printStackTrace();
					}
				
				}else {
					JOptionPane.showMessageDialog(null, "Please fill all the required feilds!");
				}
			}

			
		});
		btnSave.setFont(new Font("Tahoma", Font.BOLD, 12));
		btnSave.setBounds(38, 381, 110, 37);
		frame.getContentPane().add(btnSave);
		
		JButton btnExit = new JButton("Exit");
		btnExit.setFont(new Font("Tahoma", Font.BOLD, 12));
		btnExit.setBounds(180, 381, 110, 37);
		frame.getContentPane().add(btnExit);
		
		JButton btnClear = new JButton("Clear");
		btnClear.setFont(new Font("Tahoma", Font.BOLD, 12));
		btnClear.setBounds(323, 381, 110, 37);
		frame.getContentPane().add(btnClear);
		
		JPanel panel_1 = new JPanel();
		panel_1.setBorder(new TitledBorder(null, "Search", TitledBorder.CENTER, TitledBorder.TOP, null, null));
		panel_1.setBounds(38, 478, 395, 102);
		frame.getContentPane().add(panel_1);
		panel_1.setLayout(null);
		
		JLabel lblNewLabel_1_1_2 = new JLabel("Book ID");
		lblNewLabel_1_1_2.setFont(new Font("Tahoma", Font.BOLD, 16));
		lblNewLabel_1_1_2.setBounds(10, 41, 65, 25);
		panel_1.add(lblNewLabel_1_1_2);
		
		txtID = new JTextField();
		txtID.setColumns(10);
		txtID.setBounds(98, 43, 170, 25);
		panel_1.add(txtID);
		
		JButton search = new JButton("Search");
		search.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String id = txtID.getText().toString();
				try {
					pst = con.prepareStatement("select * from books where id =?");
					pst.setString(1, id);
					ResultSet rs = pst.executeQuery();
					if(rs.next()==true) {
						 String name = rs.getString(2);
			             String edition = rs.getString(3);
			             String price = rs.getString(4);
			             
			             txtbookid.setText(id);
			             txtbookname.setText(name);
			             txtedition.setText(edition);
			             txtprice.setText(price);
					}else {
						 txtbookid.setText("");
			             txtbookname.setText("");
			             txtedition.setText("");
			             txtprice.setText("");
			             JOptionPane.showMessageDialog(null, "Book doesn't exist try again!");
					}
				} catch (SQLException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
			}
		});
		search.setFont(new Font("Tahoma", Font.BOLD, 12));
		search.setBounds(298, 36, 76, 37);
		panel_1.add(search);
		
		JButton btnUpdate = new JButton("Update");
		btnUpdate.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				
                String name,edition,price,id;
				
				name = txtbookname.getText().toString();
				edition = txtedition.getText().toString();
				price = txtprice.getText().toString();
				id = txtID.getText().toString();
				
				if(!name.isEmpty() && !edition.isEmpty() && !price.isEmpty() && !id.isEmpty()) {
				
				try {
					pst = con.prepareStatement("update books set name=?,edition=?,price=? where id =?");
					pst.setString(1,name);
					pst.setString(2, edition);
					pst.setString(3, price);
					pst.setString(4, id);
					pst.executeUpdate();
				
					System.out.println(name);
					System.out.println(edition);
					System.out.println(price);
				
					JOptionPane.showMessageDialog(null, "Record Updated!");
					LoadTable();
					txtbookid.setText("");
					txtbookname.setText("");
					txtedition.setText("");
					txtprice.setText("");
					txtbookid.requestFocus();
					txtID.setText("");
					
				}catch(Exception e2) {
					e2.printStackTrace();
					}
				
				}else {
					JOptionPane.showMessageDialog(null, "Please fill all the required feilds!");
				}
			}
		});
		btnUpdate.setFont(new Font("Tahoma", Font.BOLD, 12));
		btnUpdate.setBounds(581, 444, 110, 51);
		frame.getContentPane().add(btnUpdate);
		
		JButton btnDelete = new JButton("Delete");
		btnDelete.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String id = txtID.getText().toString();
				 try {
						pst = con.prepareStatement("delete from books where id =?");
				
			            pst.setString(1, id);
			            pst.executeUpdate();
			            JOptionPane.showMessageDialog(null, "Record Deleted!");
			            LoadTable();
			           
			            txtbookname.setText("");
			            txtedition.setText("");
			            txtprice.setText("");
			            txtbookid.setText("");
			            txtbookid.requestFocus();
					}

		            catch (SQLException e1) {
						
						e1.printStackTrace();
					}
			}
		});
		btnDelete.setFont(new Font("Tahoma", Font.BOLD, 12));
		btnDelete.setBounds(728, 444, 110, 51);
		frame.getContentPane().add(btnDelete);
		
		JTextPane txtpnDevelopedByDevesh = new JTextPane();
		txtpnDevelopedByDevesh.setFont(new Font("Tahoma", Font.PLAIN, 12));
		txtpnDevelopedByDevesh.setText("Java GUI");
		txtpnDevelopedByDevesh.setBounds(858, 575, 60, 19);
		frame.getContentPane().add(txtpnDevelopedByDevesh);
		
		JScrollPane scrollPane = new JScrollPane();
		scrollPane.setBounds(475, 130, 489, 288);
		frame.getContentPane().add(scrollPane);
		
		table = new JTable();
		scrollPane.setViewportView(table);
	}
	
	private void LoadTable() {
		// TODO Auto-generated method stub
		 try
	     {
	    pst = con.prepareStatement("select * from books");
	    res = pst.executeQuery();
	    table.setModel(DbUtils.resultSetToTableModel(res));
	}
	     catch (SQLException e)
	     {
	     e.printStackTrace();
	  }
		
	}
}
