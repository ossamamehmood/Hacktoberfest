
public class reversePyramidWithMinorImage
{
	public static void main(String[] args)
	{
		int rows = 7; 
		
		
		
		
		for (int i = 1; i <= rows; i++)
		{
		for (int j = 1; j < i; j++)
			{
				System.out.print(" ");
			}
		for (int j = i; j <= rows; j++)
			{
				System.out.print(j+" ");
			}
			System.out.println();
		}
		

	
		for (int i = rows-1; i >= 1; i--)
		{
		for (int j = 1; j < i; j++)
			{
				System.out.print(" ");
			}
		for (int j = i; j <= rows; j++)
			{
				System.out.print(j+" ");
			}
			System.out.println();
		}
	
	}
}
