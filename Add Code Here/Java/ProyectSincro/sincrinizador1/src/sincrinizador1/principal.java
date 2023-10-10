package sincrinizador1;

public class principal {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
        hilo[] hilos=new hilo[10];
        int i;
        for(i=0;i<hilos.length;i++)
        {
        	hilos[i]= new hilo();
        	hilos[i].start();
        }
        for(i=0;i<hilos.length;i++)
        {
        	try {
				hilos[i].join();
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
        }

	}

}
