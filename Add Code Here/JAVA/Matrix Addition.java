import java.util.Scanner;
 
public class JavaMatrixAddition {
public static void main(String args[]){
int i,j,m,n;
Scanner sc = new Scanner(System.in);
System.out.println("Enter number of rows and columns:");
m = sc.nextInt();
n = sc.nextInt();
int a[][] = new int[m][n];
int b[][] = new int[m][n];
int c[][] = new int[m][n];
//reading first matrix
System.out.println("\nEnter elements of first matrix row wsie:");
for(i = 0; i < m; ++i){
for(j = 0; j < n; ++j){
a[i][j] = sc.nextInt();
}
}
//reading second matrix
System.out.println("\nEnter elements of second matrix row wsie:");
for(i = 0; i < m; ++i){
for(j = 0; j < n; ++j){
b[i][j] = sc.nextInt();
}
}
 
//performing addition of two matrices
for(i = 0; i < m; ++i){
for(j = 0; j < n; ++j){
c[i][j] = a[i][j] + b[i][j];
}
}
//printing the resultant matrix
System.out.println("\nAddtion of two matrices is:");
for(i = 0; i < m; ++i){
for(j = 0; j < n; ++j){
System.out.print(c[i][j] + " ");
}
System.out.print("\n");
}
}
}
