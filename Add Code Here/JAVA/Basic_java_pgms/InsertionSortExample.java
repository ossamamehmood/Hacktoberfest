public class InsertionSortExample {
    //program for insertion sort
    public static void main(String args[]){
        int[] intArray = {20, 35, -17, 7, 55, 1, -22};
        for(int firstUnsortedIndex = 1; firstUnsortedIndex < intArray.length; firstUnsortedIndex++){

            int operand = intArray[firstUnsortedIndex];
            int i;
        
            for( i = firstUnsortedIndex; i>0 && operand< intArray[i-1]; i--){
                intArray[i] = intArray[i-1];
                
            }
            intArray[i]= operand;
        }
        for(int i =0; i<intArray.length; i++){
            System.out.println(intArray[i]);
        }

    }

}
