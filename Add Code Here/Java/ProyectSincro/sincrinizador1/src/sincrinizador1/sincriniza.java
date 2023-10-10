package sincrinizador1;

public class sincriniza {
    private int contador=0;
    
    public synchronized int cuenta()
    {
    	 int i;
    	 for(i=0;i<15000;i++)
    	    contador++;
    	 return contador;
    }

}
