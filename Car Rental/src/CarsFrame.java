import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class CarsFrame extends JFrame implements ActionListener {
    private JButton back;
    public CarsFrame() throws HeadlessException {
        super("Cars");
        setSize(700,500);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new BorderLayout());
        JPanel pan = new JPanel();
        pan.setBackground(new Color(103,128,159));
        pan.setLayout(new GridLayout(2,2));
        ImageIcon img = new ImageIcon("corolla.jpg");
        Image image = img.getImage();
        Image nImg = image.getScaledInstance(340,200, java.awt.Image.SCALE_SMOOTH);
        img = new ImageIcon(nImg);
        pan.add(new JLabel(img));
        ImageIcon img1 = new ImageIcon("city.jpg");
        Image image1 = img1.getImage();
        Image nImg1 = image1.getScaledInstance(340,200, java.awt.Image.SCALE_SMOOTH);
        img1 = new ImageIcon(nImg1);
        pan.add(new JLabel(img1));
        ImageIcon img2 = new ImageIcon("civic.jpg");
        Image image2 = img2.getImage();
        Image nImg2 = image2.getScaledInstance(340,200, java.awt.Image.SCALE_SMOOTH);
        img2 = new ImageIcon(nImg2);
        pan.add(new JLabel(img2));
        ImageIcon img3 = new ImageIcon("accord.jpg");
        Image image3 = img3.getImage();
        Image nImg3 = image3.getScaledInstance(340,200, java.awt.Image.SCALE_SMOOTH);
        img3 = new ImageIcon(nImg3);
        pan.add(new JLabel(img3));
        add(pan,BorderLayout.CENTER);
        JPanel pan2 = new JPanel();
        pan2.setLayout(new FlowLayout());
        back = new JButton("Back");
        back.setBackground(Color.MAGENTA);
        back.addActionListener(this);
        pan2.add(back);
        pan2.setBackground(new Color(103,128,159));
        add(pan2,BorderLayout.SOUTH);
    }
    public void actionPerformed(ActionEvent e){
        String a = e.getActionCommand();
        if(a.equals("Back")){
            this.dispose();
            Home home = new Home();
            home.setResizable(false);
            home.setVisible(true);
        }
    }
}