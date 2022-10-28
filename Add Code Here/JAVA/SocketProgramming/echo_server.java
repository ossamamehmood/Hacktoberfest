import java.net.*;


class echo_server{
	public static void main(String [] args){
		
		try{
		System.out.println("Waiting for client ...");
		ServerSocket ss = new ServerSocket(6666);
		Socket soc = ss.accept();
		System.out.println("Connection established ..");
		ss.close();
		}
		catch(Exception e){
			e.printStackTrace();
		}
	}
}