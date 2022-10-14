
public class Shopmain {
public static void main(String[] args) {
	Shopping s=new Shopping();
	Adminclass a=new Adminclass(s);
	Customerclass c=new Customerclass(s);
 a.start();
		c.start();
	
	
}
}
