public class FirstClass{
    public static void main(String[] args) {
        String s="Lorem Ipsum is ";
        String s1="    simply dummy text   ";
        char s2[]={'H','e','l','l','o'};
        String s3="";
        s3=s3.copyValueOf(s2,0,5);
        System.out.println(s.toUpperCase());//Convert in UPPERCASE
        System.out.println(s.toLowerCase());//Conver in lowercase
        System.out.println(s.indexOf("text"));//Find the index of word
        System.out.println(s.length());//Length of String
        System.out.println(s.concat(s1));//Appends a string to the end of another string
        System.out.println(s3);
        System.out.println(s3.replace('l','p'));//Replace the words of string
        System.out.println(s1.trim());//remove white space from both the ends of a string
        
        //math lib...
        System.out.println(Math.max(3,8));
        System.out.println(Math.min(3,8));
        System.out.println(Math.sqrt(225));
        System.out.println(Math.abs(-7.321));//Returns absolute value
        System.out.println(Math.random()); //Random number 0 - 1
        int randomnum=(int)(Math.random()*101);//It prints random number 0 - 100           
        System.out.println(randomnum);

    }
}
