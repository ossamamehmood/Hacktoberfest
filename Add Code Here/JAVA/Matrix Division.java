public class ArrayDivideMatrix{
  public static void main(String[] args) {
  int array[][]={{3,4,6},{2,4,3}};
  int array1[][]={{3,2,3},{4,2,3}};
  int l=array.length;
  System.out.println("First matrix is:" + " " );
  for(int i=0; i< l; i++){
  for (int j=0; j<3; j++)
  {
  System.out.print(" " +array[i][j]);
  }
  System.out.println();
  }
  int m=array1.length;
  System.out.println("Second matrix is:"+ " ");
  for (int i=0; i< m; i++){
  for(int j=0; j<3; j++){
  System.out.print(" " + array1[i][j]);
  }
  System.out.println();
  }
  System.out.println("Divide of both matrix : ");
  for(int i = 0; i < m; i++) {
  for(int j = 0; j <= m; j++) {
  System.out.print(" "+(array[i][j]/array1[i][j]));
  }
  System.out.println(" ");
  }
  }
  }
