import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Checked_Exceptions {
    public static void main(String[] args)  throws Exception{
        InputStreamReader i = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(i);
        int n = Integer.parseInt(br.readLine());
        System.out.println(n);
    }
}
        