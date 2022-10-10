package cam;

import java.awt.EventQueue;

import javax.swing.JFrame;

public class Main extends JFrame {
	
	public Main() {
		
		initUI();
	}

	private void initUI() {
		
		add(new Board());
		
		setTitle("Star Ship");
		setSize(Params.BOARD_WIDTH, Params.BOARD_HEIGHT);
		
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		setResizable(false);
		setLocationRelativeTo(null);
	}
	
	public static void main(String[] args) {
		
		EventQueue.invokeLater(() -> {
			
			var ex = new Main();
			ex.setVisible(true);
		});
	}

}
