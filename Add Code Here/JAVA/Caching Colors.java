// Online Java Compiler
// Use this editor to write, compile and run your Java code online
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

class color{
    Integer r,g,b;
    public static Map<String,String> Cache = new HashMap<>();
    color(){
    }
    
   public String colors(int r,int g, int b){
        if(r==0 && g ==0 && b==0){
                return "White";
        }
        else if(r==255 && g ==0 && b==0){
                return "Red";
        }
        else if(r==0 && g ==255 && b==0){
                return "Green";
        }
        if(r==0 && g ==0 && b==255){
                return "Blue";
        }
        if(r==255 && g ==255 && b==255){
                return "Black";
        }
        
        else{
            if(Cache.get("mix")==null){
                Cache.put("mix","mix") ;
                System.out.println("Saving mix in Cache ");
                return Cache.get("mix");
            }else{
                System.out.println("mix Found in Cache ");
               return Cache.get("mix");
            }
        }
    }
    
    
}









class HelloWorld {
    public static void main(String[] args) {
        Integer R,G,B;
        color c =new color();
        String choice = "n";
        while(choice!="y"){
        Scanner input = new Scanner(System.in);
        System.out.print("Enter the RGB color -  R - ");
        R = input.nextInt();
        System.out.print("Enter the RGB color -  G - ");
        G = input.nextInt();
        System.out.println("Enter the RGB color -  B - ");
        B = input.nextInt();
        System.out.println(R+""+G+""+B);
        System.out.println("Color is "+c.colors(R,G,B));
        System.out.println("\n Press y to End ");
        choice = input.next();
        }
    }
        
 
    }