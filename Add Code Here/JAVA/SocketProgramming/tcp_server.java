
import java.io.*;
import java.net.*;


class tcp_server{
	public static void main(String [] args){

	try{
ServerSocket ss=new ServerSocket(6666);
Socket s=ss.accept();
System.out.println("Connection Established");
OutputStream obj=s.getOutputStream();//to write or send data
PrintStream ps=new PrintStream(obj);
String str="Hello Client";
ps.println(str);
ps.println("Bye");
ps.close();
ss.close();
s.close();
	}
	catch(Exception e){
	  e.printStackTrace();
	}
	}
}