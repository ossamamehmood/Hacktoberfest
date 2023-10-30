import java.net.*;
import java.io.*;

public class Client {
	Socket socket;

	BufferedReader br;
	PrintWriter out;

	public Client() {
		try {
			System.out.println("Sending Request ...");
			socket = new Socket("192.168.0.117", 7777);
			System.out.println("Connection Done !!!");
			br = new BufferedReader(new InputStreamReader(socket.getInputStream()));
			out = new PrintWriter(socket.getOutputStream());

			startReading();
			startWriting();
		} catch (Exception e) {

		}
	}

	public void startReading() {
		// thread - read karke deta rahega
		try {
			// Lamda function for Runnable to creating threads
			Runnable r1 = () -> {
				System.out.println("Reader Started....");
				while (true && (!socket.isClosed())) {
					try {

						String msg = br.readLine();
						System.out.println("Server: " + msg);
						if (msg.equals("exit")) {
							System.out.println("Server Terminated the Chat.....");
							System.out.println("Connection Close From Server......");
							socket.close();
							break;
						}

					} catch (Exception e) {

					}
				}
			};
			new Thread(r1).start();
		} catch (Exception e) {
		}
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
					System.out.println("Client: " + content);
					if (content.equals("exit")) {
						System.out.println("Connection Closed From Client......");
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
		System.out.println("This is Client..............");
		new Client();
	}
}