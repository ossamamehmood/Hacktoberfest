import java.util.*;


public class list{

    public static void main(String[]args)
    {

        ArrayList<Integer>list=new ArrayList<>();
        int n,j, count;
        
        int intArray[];
        Scanner sc =new Scanner(System.in);
        System.out.println("Enter number of element.");
        n=sc.nextInt();

        System.out.println("Enter elements of arraylist");
        for(int i=0;i<n;i++){;

           j=sc.nextInt();
           list.add(j);             
        }

        System.out.println("my arraylist is:");
        for(int i=0;i<n;i++){
            System.out.println(list.get(i));
        }


        System.out.println("odd numbers form list are:");
        for(int i=0;i<n;i++){
            if(list.get(i)%2!=0){
                System.out.println(list.get(i));
                count=i++;
            }
        }

        System.out.println("even numbers form list are:");
        for(int i=0;i<n;i++){
            if(list.get(i)%2==0){
                System.out.println(list.get(i));
                count=i++;
            }
        }
    }

}
