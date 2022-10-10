import java.util.Scanner;   
   

public class Main   
{   
 
    public static final String ALPHABET = "abcdefghijklmnopqrstuvwxyz";   
      
    
    public static void main(String[] args)   
    {   
        
        Scanner sc = new Scanner(System.in);
        while(true){
        System.out.println("Enter your choice");
        System.out.println("1 for Encryption");
        System.out.println("2 for decryption");
        System.out.println("3 for brute force");
        System.out.println("4 to EXIT");
        
        int ch=sc.nextInt();
        
        if(ch==1){
            Scanner sc2 = new Scanner(System.in);
        System.out.println(" Input the plaintext message : ");
        String plaintext = sc2.nextLine();
        System.out.println(" Enter the value by which each character in the plaintext message gets shifted : ");
        int shift = sc2.nextInt();
        String ciphertext = "";
        char alphabet;
        for(int i=0; i < plaintext.length();i++) 
        {
            
            alphabet = plaintext.charAt(i);
            
             
            if(alphabet >= 'a' && alphabet <= 'z') 
            {
            
             alphabet = (char) (alphabet + shift);
            
             if(alphabet > 'z') {
                
                alphabet = (char) (alphabet+'a'-'z'-1);
             }
             ciphertext = ciphertext + alphabet;
            }
            
            
            else if(alphabet >= 'A' && alphabet <= 'Z') {
            
             alphabet = (char) (alphabet + shift);    
                
            
             if(alphabet > 'Z') {
                
                 alphabet = (char) (alphabet+'A'-'Z'-1);
             }
             ciphertext = ciphertext + alphabet;
            }
            else {
             ciphertext = ciphertext + alphabet;   
            }
        
    }
System.out.println(" ciphertext : " + ciphertext);
                  
            }   
        if(ch==2){
                Scanner sc1 = new Scanner(System.in);
                System.out.println(" Input the ciphertext message : ");
                String ciphertext = sc1.nextLine();
                System.out.println(" Enter the shift value : ");
                int shift = sc1.nextInt();
                String decryptMessage = "";
                for(int i=0; i < ciphertext.length();i++) 
            {
                
                char alphabet = ciphertext.charAt(i);
                
                if(alphabet >= 'a' && alphabet <= 'z')
                {
                    
                    alphabet = (char) (alphabet - shift);
                
                    
                    if(alphabet < 'a') {
                        
                        alphabet = (char) (alphabet-'a'+'z'+1);
                    }
                    decryptMessage = decryptMessage + alphabet;
                }    
                    
                else if(alphabet >= 'A' && alphabet <= 'Z')
                {
                 
                    alphabet = (char) (alphabet - shift);
                    
                    
                    if (alphabet < 'A') {
                        
                        alphabet = (char) (alphabet-'A'+'Z'+1);
                    }
                    decryptMessage = decryptMessage + alphabet;            
                }
                else 
                {
                 decryptMessage = decryptMessage + alphabet;            
                } 
   
            }
                 System.out.println(" decrypt message : " + decryptMessage);
          
        sc.close();   
    }
    if(ch==3){
        // System.out.println("COMING SOON");
    }
    if(ch==4){
        System.exit(0);
    }
    }
    }
    
}  
