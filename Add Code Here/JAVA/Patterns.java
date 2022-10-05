public class Patterns {

    public static void main(String[] args){
        pattern1();
        pattern2();
        pattern3();
        pattern4();
        pattern5();
        pattern6();
        pattern7();
        pattern8();
        pattern9();
        pattern10();
        pattern11();
        pattern12();
        pattern13();
        pattern14();
        pattern15();
        // pattern16();
        pattern17();
        pattern18();
        pattern19();
        pattern20();
        pattern21();
        pattern22();
        // pattern23();
        pattern24();
        pattern25();
        pattern26();
        // pattern27();
        pattern28();
        pattern29();
        pattern30();
        // pattern31();
        pattern32();
        // pattern33();
        pattern34();
        pattern35();
    }

    static void pattern1(){
        System.out.println();
        int rows = 5;
        for(int row = 1; row <= rows; row++){
            for(int col = 1; col <= rows; col++){
                System.out.print("* ");
            }
            System.out.println();
        }
        System.out.println();
        
    }
    
    static void pattern2(){
        System.out.println();
        int rows = 5;
        for(int row = 1; row <= rows; row++){
            for(int col = 1; col <= row; col++){
                System.out.print("* ");
            }
            System.out.println();
        }
        System.out.println();
        
    }

    static void pattern3(){
        System.out.println();
        int rows = 5;
        for(int row = 1; row <= rows; row++){
            for(int col = 1; col <= rows - row + 1; col++){
                System.out.print("* ");
            }
            System.out.println();
        }
        System.out.println();
    }

    static void pattern4(){
        System.out.println();
        int rows = 5;
        for(int row = 1; row <= rows; row++){
            for(int col = 1; col <= row; col++){
                System.out.print(col + " ");
            }
            System.out.println();
        }
        System.out.println();
    }

    static void pattern5(){
        System.out.println();

        int rows = 5;
        for(int row = 1; row <= 2 * rows - 1; row++){
            int totalcols = row < rows? (row):(rows - (row - rows));
            for(int col = 1; col <= totalcols; col++){
                System.out.print("* ");
            }
            System.out.println();
        }
        System.out.println();
    }

    static void pattern6(){
        System.out.println();
        int rows = 5;
        for(int row = 1; row <= rows; row++){
            for(int spaceCount = 1; spaceCount <= rows - row;spaceCount++){
                System.out.print("  ");
            }
            for(int col = 1; col <= row; col++){
                System.out.print("* ");
            }
            System.out.println();
        }
        System.out.println();
    }

    static void pattern7(){
        System.out.println();
        int rows = 5;
        for(int row = 1; row <= rows; row++){
            for(int spaceCount = 1; spaceCount <= row - 1;spaceCount++){
                System.out.print("  ");
            }
            for(int col = 1; col <= rows - row + 1; col++){
                System.out.print("* ");
            }
            System.out.println();
        }
        System.out.println();
    }

    static void pattern8(){
        System.out.println();
        int rows = 5;
        for(int row = 1; row <= rows; row++){

            for(int spaceCount = 1; spaceCount <= rows - row;spaceCount++){
                System.out.print("  ");
            }

            for(int col = 1; col <= row; col++){
                System.out.print("* ");
            }

            for(int col = 1; col <= row - 1; col++){
                System.out.print("* ");
            }
            System.out.println();
        }
        System.out.println();
    }

    static void pattern9(){
        System.out.println();
        int rows = 5;
        for(int row = 1; row <= rows; row++){
            for(int spaceCount = 1; spaceCount <= row - 1;spaceCount++){
                System.out.print("  ");
            }
            for(int col = 1; col <= rows - row + 1; col++){
                System.out.print("* ");
            }

            for(int col = 1; col <= rows - row; col++){
                System.out.print("* ");
            }
            System.out.println();
        }
        System.out.println();
    }
    
    static void pattern10(){
        System.out.println();
        int rows = 5;
        for(int row = 1; row <= rows; row++){
            for(int spaceCount = 1; spaceCount <= rows - row;spaceCount++){
                System.out.print("  ");
            }
            for(int col = 1; col <= row; col++){
                System.out.print("*   ");
            }

            System.out.println();
        }
        System.out.println();
    }

    static void pattern11(){
        System.out.println();
        int rows = 5;
        for(int row = 1; row <= rows; row++){
            for(int spaceCount = 1; spaceCount <= row - 1;spaceCount++){
                System.out.print("  ");
            }
            for(int col = 1; col <= rows - row + 1; col++){
                System.out.print("*   ");
            }

            System.out.println();
        }
        System.out.println();
    }

    static void pattern12(){
        System.out.println();
        int rows = 5;
        for(int row = 1; row <= 2 * rows; row++){
           
            int totalSpaces = row <= rows? row - 1: rows - (row - rows);
            int totalcols = row <= rows? (rows - row + 1):(row - rows);
           
            for(int spaceCount = 1; spaceCount <= totalSpaces;spaceCount++){
                System.out.print("  ");
            }
            for(int col = 1; col <= totalcols; col++){
                System.out.print("*   ");
            }

            System.out.println();
        }
        System.out.println();
    }

    static void pattern13(){
        System.out.println();
        int rows = 5;
        for(int row = 1; row <= rows; row++){
            
            for(int spaceCount = 1; spaceCount <= rows - row;spaceCount++){
                System.out.print(" ");
            }
            for(int col = 1; col <= row; col++){
                if(row == rows)
                    if(col == row)
                        System.out.println("*");
                    else
                        System.out.print("**");
                else if(col == 1 || col == row)
                    System.out.print("* ");
                else
                    System.out.print("  ");
            }

            System.out.println();
        }
        System.out.println();
    }

    static void pattern14(){
        int rows = 5;
    
        for(int row = 1;row <=rows; row++){

            for(int spaceCount = 1; spaceCount <= row - 1; spaceCount++){
                System.out.print(" ");
            }

            for(int col = 1;col <= rows - row + 1; col++){
                if(row == 1){
                    if(col != rows)
                        System.out.print("**");
                
                    else
                        System.out.print("*");
                }

                else{
                    if(col == 1 || col == rows - row + 1)
                        System.out.print("* ");
                    else
                        System.out.print("  ");
                }
            }

            System.out.println();
        }
        System.out.println();
    }

    static void pattern15(){
        int rows = 5;
        System.out.println();

        for(int row  = 1; row <= 2 * rows - 1; row++){
            int totalSpaces = row <= rows?(rows - row):(row-rows);
            int totalCOls = row <= rows?(row):rows - (row - rows);

            for(int spaceCount = 1; spaceCount <= totalSpaces; spaceCount++){
                System.out.print(" ");
            }

            for(int col = 1;col <= totalCOls;col++){
                if(col == 1 || col == totalCOls)
                    System.out.print("* ");
                else 
                    System.out.print("  ");
            }

            System.out.println();
        }
        System.out.println();
    }

    // static void pattern16(){

    // }

    static void pattern17(){
        int rows = 4;
        System.out.println();

        for(int row = 1; row <= 2 * rows- 1; row++){
            int totalSpaces = row <= rows ? (rows - row):(row - rows);
            int colStart = row <= rows? row : rows - (row - rows) ;
            for(int spaceCount = 1; spaceCount <= totalSpaces; spaceCount++){
                System.out.print(" ");
            }

            for(int col = colStart; col >= 1; col--){
                System.out.print(col);
            }

            for(int col = 2; col <= colStart; col++){
                System.out.print(col);
            }
            System.out.println();
        }
        System.out.println();
    }

    static void pattern18(){

        int rows = 5;
        System.out.println();

        for(int row = 1; row <= 2 * rows; row++){
            int colEnd = row<=rows?rows - row + 1:row - rows;
            int spaceCount = row<=rows?row - 1:rows - (row - rows);

            for(int col = 1; col <= colEnd; col++){
                System.out.print("*");
            }

            for(int space = 1; space <= spaceCount * 2; space++){
                System.out.print(" ");
            }

            for(int col = 1;col <= colEnd;col++){
                System.out.print("*");
            }
            System.out.println();
        }
        System.out.println();
    }

    static void pattern19(){

        int rows = 5;
        System.out.println();

        for(int row = 1; row <= 2 * rows - 1; row++){

            int colEnd = row<=rows?row:rows - (row - rows);
            int spaceCount = row<=rows?rows - row:row - rows;

            for(int col = 1; col <= colEnd; col++){
                System.out.print("*");
            }

            for(int space = 1; space <= spaceCount * 2; space++){
                System.out.print(" ");
            }

            for(int col = 1;col <= colEnd;col++){
                System.out.print("*");
            }
            System.out.println();
        }
        System.out.println();
    }

    static void pattern20(){

        int rows = 5;
        System.out.println();

        for(int row = 1; row <= rows; row++){
            for(int col = 1;col <= rows;col++){
                if(col == 1 || col == rows || row == 1 || row == rows){
                    System.out.print("*");
                }

                else{
                    System.out.print(" ");
                }
            }
            System.out.println();
        }
        
        System.out.println();
    }

    static void pattern21(){
        System.out.println();
        int rows = 5;
        int num = 1;
        for(int row = 1; row <= rows; row++){
            for(int col = 1; col <= row; col++){
                System.out.print(num + " ");
                num++;
            }
            
            System.out.println();
        }
        System.out.println();
    }

    static void pattern22(){
        System.out.println();
        int rows = 5;
        for(int row = 1; row <= rows; row++){
            for(int col = 1; col <= row; col++){
                if((row + col) % 2 == 0) 
                    System.out.print("1 ");
                else
                    System.out.print("0 ");
            }
            
            System.out.println();
        }
        System.out.println();
    }

    // static void pattern23(){

    //     /*    *   *
    //          * * * *
    //         *   *   *  3 + 1
               
    //            *     *
    //           * *   * *
    //          *   * *   *
    //         *     *     *  4 + 2


    //             *       * 
    //            * *     * *
    //           *   *   *   *
    //          *     * *     *
    //         *       *       * 5 + 3
    //      */
    //     int rows = 3;

    //     for(int row = 1; row <= rows; row++){
    //         for(int spaceCount = 1; spaceCount <= rows - row; spaceCount++){
    //             System.out.print(" ");
    //         }

    //         for(int col = 1; col <= row; col++){
    //             if(col == 1 || col == row){
    //                 if(col == 1){
    //                     System.out.print("* ");
    //                 }
    //                 else{
    //                     System.out.print("*");
    //                 }
    //             }

    //             else
    //                 System.out.print("  ");
    //         }

    //         for(int spaceCount = 1; spaceCount <= rows - row; spaceCount++){
    //             System.out.print(" ");
    //         }

    //         for(int spaceCount = 1;spaceCount<= (rows - 1) - row; spaceCount++){
    //             if(row == rows || row == rows - 1){

    //             }
    //             else{
    //                 System.out.print(" ");
    //             }
    //         }


    //         if(row != rows){
    //         for(int col = 1; col <= row; col++){
    //                 if(col == 1 || col == row){
    //                     System.out.print("* ");
    //                 }
    //                 else{
    //                     System.out.println("  ");
    //                 }
    //             }
    //         }
    //         System.out.println();

    //     }
    // }

    static void pattern24(){
        int rows = 5;
        System.out.println();
        
        for(int row = 1; row <= 2 * rows; row++){

            int totalSpaces = row <= rows?rows - row:(row - rows - 1);
            int totalcols = row<= rows?row:rows - (row - rows - 1);

            for(int col = 1; col <= totalcols; col++){
                if(col == 1 || col == totalcols){
                    System.out.print("*");
                }
                else{
                    System.out.print(" ");
                }
            }

            for(int spaceCount = 1; spaceCount <= 2 * totalSpaces; spaceCount++){
                System.out.print(" ");
            }

            for(int col = 1; col <= totalcols; col++){
                if(col == 1 || col == totalcols){
                    System.out.print("*");
                }
                else{
                    System.out.print(" ");
                }
            }

            System.out.println();
        }
        System.out.println();
    }

    static void pattern25(){
        int rows = 5;
        System.out.println();

        for(int row = 1;row <= rows; row++){
            for(int spaceCount = 1; spaceCount <= rows - row; spaceCount++){
                System.out.print(" ");
            }

            for(int col = 1; col <= rows; col++){
                if(col == 1 || col == rows || row == 1 || row == rows){
                    System.out.print("*");
                }
                else{
                    System.out.print(" ");
                }
            }
            System.out.println();
        }
        System.out.println();
    }    
    
    static void pattern26(){
        System.out.println();
        int rows = 6;
        for(int row = 1; row <= rows; row++){
            for(int col = 1; col <= rows - row + 1; col++){
                System.out.print(row + " ");
            }
            System.out.println();
        }
        System.out.println();
    }

    // static void pattern27(){

    // }

    static void pattern28(){
        int rows = 4;
        System.out.println();

        for(int row = 1; row <= 2 * rows- 1; row++){
            int totalSpaces = row <= rows ? (rows - row):(row - rows);
            int totalcols = row <= rows? row : rows - (row - rows) ;

            for(int spaceCount = 1; spaceCount <= totalSpaces; spaceCount++){
                System.out.print(" ");
            }

            for(int col = 1; col <= totalcols; col++){
                System.out.print("* ");
            }

            System.out.println();
        }
        System.out.println();
    }

    static void pattern29(){
        int rows = 5;
        System.out.println();
        
        for(int row = 1; row <= 2 * rows - 1; row++){

            int totalSpaces = row <= rows?rows - row:(row - rows);
            int totalcols = row<= rows?row:rows - (row - rows);

            for(int col = 1; col <= totalcols; col++){
                System.out.print("*");    
            }

            for(int spaceCount = 1; spaceCount <= 2 * totalSpaces; spaceCount++){
                System.out.print(" ");
            }

            for(int col = 1; col <= totalcols; col++){
                System.out.print("*");    
            }

            System.out.println();
        }
        System.out.println();
    }

    static void pattern30(){
        int rows = 5;
        System.out.println();

        for(int row = 1; row <= rows; row++){
            for(int spaceCount = 1; spaceCount <= rows - row; spaceCount++){
                System.out.print("  ");
            }

            for(int col = row; col >= 1; col--){
                System.out.print(col+ " ");
            }

            for(int col = 2; col <= row; col++){
                System.out.print(col + " ");
            }
            System.out.println();
        }
        System.out.println();
    }

    // static void pattern31(){
    //     int rows = 5;

    //     for(int row = 1; row < 2 * rows - 1; row++){
    //         for(int col = 1; col < 2 * rows - 1; col++){
    //             int curr = rows - Math.min(Math.min(row,col), Math.min((2 * rows - 1) - row,(2 * rows - 1) - col ));

    //             System.out.print(curr + " ");
    //         }
    //         System.out.println();
    //     }
    // }

    static void pattern32(){
        int rows = 5;
        System.out.println();

        for(int row = 1; row <= rows; row++){
            int colStart = (64 + (rows - row + 1));
            for(int col = colStart; col < 65 + rows; col++){
                char ch = (char)col;
                System.out.print(ch + " ");
            }
            System.out.println();
        }
        System.out.println();
    }

    // static void pattern33(){

    // }

    static void pattern34(){
        int rows = 5;

        for(int row = 1; row <= rows; row++){
            int colStart = 64 + rows - row + 1;

            for(int col = colStart; col > 64; col--){
                System.out.print((char)(col) + " ");
            }
            System.out.println();
        }
    }

    static void pattern35(){
        int rows = 4;
        System.out.println();

        for(int row = 1; row <= rows; row++){
            for(int col = 1;col <= row; col++){
                System.out.print(col + " ");
            }

            for(int spaceCount = 1; spaceCount <= 2 * (rows - row); spaceCount++){
                System.out.print("  ");
            }

            for(int col = row; col >= 1; col--){
                System.out.print(col + " ");
            }
            System.out.println();
        }
        System.out.println();

    }
}


