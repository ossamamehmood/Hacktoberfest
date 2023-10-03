class Freq{
	public static void main(String args[]){
		String s="arijit das";
		int freq[]=new int[s.length()];
		char st[]=s.toCharArray();
		for(int i=0;i<s.length();i++){
			freq[i]=1;
			for(int j=i+1;j<s.length();j++){
				if(st[i]==st[j]){
					freq[i]++;
					st[j]='0';
				}
			}
		}
		for(int i=0;i<freq.length;i++){
			if(st[i]!=' ' && st[i]!='0')
				System.out.println(st[i]+"  "+freq[i]);
		}
	}
}