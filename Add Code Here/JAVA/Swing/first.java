import java.awt.Color;
import java.lang.ProcessBuilder.Redirect;

import javax.crypto.Cipher;
import javax.swing.*;

public class first {
    public static void main(String[] args) {
        JFrame obj = new JFrame();
        obj.setVisible(true);
        //ctrl+c+(+)
        obj.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);  //to terminate program 
        // obj.setSize(500,400); //to set width and height
        // obj.setLocation(100,100);  // to its position 
        obj.setBounds(100,100 ,500,400); //it will do both size and location

        obj.setTitle("HOGWARTS"); //set the title
        ImageIcon icon = new ImageIcon("download.png"); // use of imageicon
        obj.setIconImage(icon.getImage()); // to access imageicons object 

        obj.getContentPane().setBackground(Color.pink);




    }
}
