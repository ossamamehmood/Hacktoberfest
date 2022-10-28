import java.net.*;
import java.io.*;


class tcp_client{
	public static void main(String [] args){
	  try{
	    Socket s=new Socket("localhost",6666);
InputStream obj=s.getInputStream();//to read data

BufferedReader br=new BufferedReader(new InputStreamReader(obj));

String str;
while((str=br.readLine())!=null)
{

System.out.println("From Server: "+str);

}
br.close();
s.close();
	  }
	  catch(Exception e){
	    e.printStackTrace();
	  }
	}
}