package loveBubberQuestionSeries;

public class EditDistance {

	public static void main(String[] args) {
		
		String s = "abc";
		String t = "abd";
	    
		
		
		
		
		int arr[][] = new int[s.length()+1][t.length()+1];
		
		for(int i = 0; i<=s.length(); i++) {
			for(int j = 0; j<=t.length(); j++) {
				
				if(i == 0) arr[i][j] = j;
				else if
				(j == 0) arr[i][j] = i;
				else if
				(s.charAt(i-1) == t.charAt(j-1)) {
					arr[i][j] = arr[i-1][j-1];
					
				}else{
					int a = Math.min(arr[i-1][j], arr[i][j-1]);
					int b = Math.min(a, arr[i-1][j-1]);
					arr[i][j] = b+1;
				}
				
				
			}
		}
		
		System.out.println(arr[s.length()][t.length()]);

	}
	
	

}
