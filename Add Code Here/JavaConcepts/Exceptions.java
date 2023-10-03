import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Exceptions{
    public static void main(String[] args) throws Exception {
        try(BufferedReader br = new BufferedReader(new InputStreamReader(System.in))){
             int n = Integer.parseInt(br.readLine());
             System.out.println(n);
        }
    }
}

