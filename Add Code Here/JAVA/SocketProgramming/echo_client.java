import java.net.*;


class echo_client{
	public static void main(String [] args){
		
		try{
		System.out.println("Connecting to a server ...");
		Socket s = new Socket("localhost",6666);
		}
		catch(Exception e){
			e.printStackTrace();
		}
	}
}