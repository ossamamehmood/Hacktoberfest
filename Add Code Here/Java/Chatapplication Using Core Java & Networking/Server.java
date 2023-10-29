import java.net.*;
import java.io.*;

class Server {
	ServerSocket server;
	Socket socket;

	BufferedReader br;
	PrintWriter out;

	// Constructor..
	public Server() {

		try {
			server = new ServerSocket(7777);
			System.out.println("Server is ready to accept Connection");
			System.out.println("Server waiting.....");
			socket = server.accept();
			br = new BufferedReader(new InputStreamReader(socket.getInputStream()));
			out = new PrintWriter(socket.getOutputStream());

			startReading();
			startWriting();
		} catch (Exception e) {

		}
	}

	public void startReading() {
		// thread - read karke deta rahega

		// Lamda function for Runnable to creating threads
		Runnable r1 = () -> {

			System.out.println("Reader Started....");
			try {
				while (true && (!socket.isClosed())) {

					String msg = br.readLine();
					System.out.println("Client: " + msg);
					if (msg.equals("exit")) {
						System.out.println("Client Terminated the Chat.....");
						System.out.println("Connection Closed From Client......");
						socket.close();
						break;

					}

				}
			} catch (Exception e) {
			}
		};
		new Thread(r1).start();

	}

	public void startWriting() {
		// data ko user se lega and send karega client ko
		Runnable r2 = () -> {
			System.out.println("Writer Started.......");
			try {
				while (true && (!socket.isClosed())) {

					BufferedReader br1 = new BufferedReader(new InputStreamReader(System.in));
					String content = br1.readLine();
					out.println(content);
					out.flush();
					System.out.println("Server: " + content);
					if (content.equals("exit")) {
						System.out.println("Connection Closed From Server......");
						socket.close();
						break;
					}

				}
			} catch (Exception e) {
			}
		};
		new Thread(r2).start();
	}

	public static void main(String args[]) {
		System.out.println("This is Server.................");
		new Server();
	}
}