
public class Customerclass extends Thread{
	
private Shopping s;
	public Customerclass(Shopping shopping) {
		this.s=shopping;
	}
	@Override
		public void run() {
		while(true)
		{
			
			s.displaydata();
		}
			
		}
}
