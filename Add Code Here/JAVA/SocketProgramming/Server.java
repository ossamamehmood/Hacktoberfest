import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;

public class Server {
    ServerSocket serverSocket;
    Socket socket;
    BufferedReader reader;
    PrintWriter writer;

    public Server() {
        try {
            serverSocket = new ServerSocket(6666);
            System.out.println("Server is ready for connection");
            socket = serverSocket.accept();

            reader = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            writer = new PrintWriter(socket.getOutputStream());

            read();
            write();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private void write() {
        Runnable runnable = () -> {
            System.out.println("Writer started");
            try {
                while (!socket.isClosed()) {
                    BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
                    String message = read.readLine();
                    writer.println(message);
                    writer.flush();
                    if(message.equals("exit")){
                        socket.close();
                        break;
                    }
                }
            } catch (Exception e) {
                System.out.println("Socket Connection terminated");
            }
            System.out.println("Socket Connection closed");
        };
        new Thread(runnable).start();
    }

    private void read() {
        Runnable runnable = () -> {
            try {
                while (true) {
                    String message = reader.readLine();
                    if (message.equals("exit")) {
                        System.out.println("Client terminated the chat");
                        socket.close();
                        break;
                    }
                    System.out.println("Client - " + message);
                }
            } catch (Exception e) {
                System.out.println("Socket Connection closed");
            }
        };
        new Thread(runnable).start();
    }

    public static void main(String[] args) {
        System.out.println("Starting Server...");
        new Server();
    }
}
