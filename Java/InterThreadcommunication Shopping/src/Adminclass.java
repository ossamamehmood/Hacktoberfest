
public class Adminclass extends Thread {
	private Shopping s;
	public Adminclass(Shopping shopping) {
		this.s=shopping;
	}
	@Override
		public void run() {
			// TODO Auto-generated method stub
		int numb=0;
		while(true)
		{
			numb++;
			s.Storedata(numb);
			if(numb>90)
			{
				break;
			}
		}
			
		}
}
