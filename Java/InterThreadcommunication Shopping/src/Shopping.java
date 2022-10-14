

public class Shopping {
	int num;
	boolean flag=false; 
public synchronized void  Storedata(int a)
{
	if(flag==true)
	{	
	 try {
		wait();
	} catch (InterruptedException e) {
		// TODO Auto-generated catch block
		e.printStackTrace();
	}
	}
	num=a;
	System.out.println("Storing Data" + num);
	flag=true;
	notify();
	
}
public synchronized int displaydata() {

	if(flag==false)
	{	
	 try {
		wait();
	} catch (InterruptedException e) {
		// TODO Auto-generated catch block
		e.printStackTrace();
	}
	}
	
		System.out.println("Displaying Data" +num);
		
		flag=false;
		notify();
		return num;
}
}
