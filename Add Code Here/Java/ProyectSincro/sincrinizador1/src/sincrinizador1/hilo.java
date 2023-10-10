package sincrinizador1;

public class hilo extends Thread {
	static sincriniza  cuenta=new sincriniza();
	
	public void run() {
		int i;
		
		System.out.println("la cuenta es "+cuenta.cuenta());
	}

}
