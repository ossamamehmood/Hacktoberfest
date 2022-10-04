import java.util.Scanner;
public class OddOrEven {
    public static void main(String[] args) {
        Scanner input=new Scanner(System.in);
        int bil;
        System.out.println("PROGRAM MENENTUKAN BILANGAN HANJIL & GENAP");
        System.out.println("-------------------------------------------------");
        System.out.print("Masukan Bilangan = ");
        bil=input.nextInt();
        
        if (bil%2==0){
            System.out.println("Bilangan "+bil+" adalah bilangan genap");
        }else {
             System.out.println("Bilangan "+bil+" adalah bilangan ganjil");
        }
    
  }
}
