
//package LeetCode;
import java.io.*;
import java.util.*;

/**
 *
 * @author prabhat
 */
 class SuffixArray {

	   static final int MAX1 = 1000000+10;
	   static final int MAX2 = 1000001;
	   static final long MOD = 1000000007;
	   static int phiSum[] = new int[MAX1];
	   static int phi[] = new int[MAX1];
	   static long[] res=new long[MAX1];
	   static int arr[];
	   static long BIT[];
	   static int n;
	   static boolean[] b;
	   static int[][] pascal;
	   static int[][]P;
	   static Edge[] edge;
	   static int step;
	    public static void main(String[] args) throws IOException{
	       
	        InputReader in = new InputReader(System.in);
	        PrintWriter pw = new PrintWriter(System.out,true);
	     String a=in.next();
             //pw.println(destinct(s1));
             String b=in.next();
           long ans=(destinct(a)+destinct(b));
		long tmp=destinct(a+"$"+b)-((long)(a.length()+1)*(b.length()+1));
		//System.out.println(tmp);
	       pw.println(-ans+2*tmp);
             
	       // pw.println(Arrays.toString(lcp));
	        //pw.println(Arrays.toString(sa));
	         
	       pw.close();
	    }
            static long destinct(String s)
            {
                int[] sa=suffixArray(s);
                int[] lcp=lcp(sa,s);
                int l=s.length();
                long ans=0;
                ans=l-sa[0];
                for(int i=1;i<sa.length;i++)
                    ans+=l-sa[i]-lcp[i-1];
                return ans;
            }
            
            
	    public static int[] lcp(int[] sa, String s) {        /* O(n) time complexity*/
	        int n = sa.length;
	        int[] rank = new int[n];        //   This is used to get next suffix string from suffix array.
	       
	        for (int i = 0; i < n; i++)
	          rank[sa[i]] = i;
	        int[] lcp = new int[n ];
	        int h=0;
	        for (int i = 0; i < n; i++)
	        {
	         if (rank[i] < n - 1) 
	            {
	            for (int j = sa[rank[i] + 1]; Math.max(i, j) + h < s.length() && s.charAt(i + h) == s.charAt(j + h); ++h)
	              ;   /*for  there is no statement */
	            /* j contains index of the next substring to
	            be considered  to compare with the present
	            substring, i.e., next string in suffix array */
	            
	            lcp[rank[i]] = h;        // lcp for the present suffix.
	            if (h > 0)
	              --h;             // Deleting the starting character from the string
	          }
	        }
	        return lcp;
	      }
 
	  
	 // sort suffixes of S in O(n*log(n))
	  public static int[] suffixArray(CharSequence S) {
	    int n = S.length();
	    Integer[] order = new Integer[n];
	    for (int i = 0; i < n; i++)
	      order[i] = n - 1 - i;
 
	    // stable sort of characters
	    Arrays.sort(order, new MyComparator(S));
 
	    int[] sa = new int[n];
	    int[] classes = new int[n];
	    for (int i = 0; i < n; i++) {
	      sa[i] = order[i];
	      classes[i] = S.charAt(i);
	    }
	    // sa[i] - suffix on i'th position after sorting by first len characters
	    // classes[i] - equivalence class of the i'th suffix after sorting by first len characters
 
	    for (int len = 1; len < n; len *= 2) {
	      int[] c = classes.clone();
	      for (int i = 0; i < n; i++) {
	        // condition sa[i - 1] + len < n simulates 0-symbol at the end of the string
	        // a separate class is created for each suffix followed by simulated 0-symbol
	        classes[sa[i]] = i > 0 && c[sa[i - 1]] == c[sa[i]] && sa[i - 1] + len < n && c[sa[i - 1] + len / 2] == c[sa[i] + len / 2] ? classes[sa[i - 1]] : i;
	      }
	      // Suffixes are already sorted by first len characters
	      // Now sort suffixes by first len * 2 characters
	      int[] cnt = new int[n];
	      for (int i = 0; i < n; i++)
	        cnt[i] = i;
	      int[] s = sa.clone();
	      for (int i = 0; i < n; i++) {
	        // s[i] - order of suffixes sorted by first len characters
	        // (s[i] - len) - order of suffixes sorted only by second len characters
	        int s1 = s[i] - len;
	        // sort only suffixes of length > len, others are already sorted
	        if (s1 >= 0)
	          sa[cnt[classes[s1]]++] = s1;
	      }
	    }
	    return sa;
	  }
      static class MyComparator implements Comparator<Integer> {
		private final CharSequence S;
		public MyComparator(CharSequence S)
		{
			this.S=S;
		}
		@Override
		public int compare(Integer index1, Integer index2)
		{
			return Character.compare(S.charAt(index1), S.charAt(index2));
		}
	}
          
	  static int[] RadixSort(int[] a)
            {
              int mul=1;
              int n=a.length;
             int max=Integer.MIN_VALUE;
             for(int i=0;i<n;i++)max=Math.max(max, a[i]);
              for (int exp = 1; max/exp > 0; exp *= 10)
                          a=  CountSort(a, n, exp);
               
               return a; 
            }
            static int[] CountSort(int[] a,int n,int exp)
            {
               
              int[] cs=new int[n];
              int[] freq=new int[10005];
              
               for(int i=0;i<n;i++)
               {
                 freq[(a[i]/exp)%10]++;
               }
               
              for(int i=1;i<10000;i++)
                  freq[i]+=freq[i-1];
              
              for(int i=n-1;i>=0;i--)
              {
                 cs[freq[(a[i]/exp)%10]-1]=a[i];         /// because it is zero based so we do minus 1
                freq[(a[i]/exp)%10]--;
              
              }
              
            
            return cs;
            }
            
	    public static long nCr(long total, long choose)
		{
			if(total < choose)
				return 0;
			if(choose == 0 || choose == total)
				return 1;
			return nCr(total-1,choose-1)+nCr(total-1,choose);
		}
	    static void compute() {
	    		for (int i = 0; i < MAX1; i++) {
	    			phi[i] = 0;
	    		}
	          phi[1]=1;
	    		for (int i = 2; i < MAX1; i++) {
	    			if (phi[i] == 0) {
	    				phi[i] = i - 1;
	     
	    				for (int j = 2 * i; j < MAX1; j += i) {
	    					 if(phi[j]==0) phi[j] = j ;
	    					phi[j] -= (phi[j]/i);
	    				}
	    			}
	    		}
	     
	    		for (int i = 1; i < MAX1; i++) {
	    			for (int j = i, k = 1; j < MAX1; j += i,k++) {
	    				phiSum[j] += i * phi[k];
	    			}
	    		}
	    		//System.out.println(Arrays.toString(phiSum));
                /*botharrays  res and phisum gives the same arrays so please don't worry*/
	    		
	    		for(int i=1;i<MAX1;i++)
	    		{
	    			for(int j=i+i;j<MAX1;j+=i)
	    			{
	    			   res[j]=res[j]+1L*i*phi[j/i];
	    			}
	    		}
	    		for(int i=1;i<=1000000;i++)
	    			res[i]=res[i]+res[i-1];
	    	//System.out.println(Arrays.toString(res));
	    						
	    		
	    		
	    }
	    public static void Seive()
		{
			
			 b=new boolean[10000001];
			Arrays.fill(b, true);
			b[0]=false;
			b[1]=false;
			
			for(int i=2;i<=(10000000);i++)
			{
				if(b[i])
				{
					
				 for(int j=i*2;j<=10000000;j+=i)
					{
						     b[j]=false;
						
					}
				}
				
			}
			
		}
	    static int pascal(int i1,int j1)
	    {
	  	  pascal=new int[101][101];
	  	  for(int i=0;i<=100;i++)
	  	  {
	  		  pascal[i][0]=1;
	  		  for(int j=1;j<=i;j++)
	  		  {
	  			  pascal[i][j]=(int) ((pascal[i-1][j]+pascal[i-1][j-1])%MOD);
	  		  }
	  	  }
	  	  return pascal[i1][j1];
	    }
	    private static class DSU{
			int[] parent;
			int[] rank;
			int cnt;
			public DSU(int n){
				parent=new int[n];
				rank=new int[n];
				for(int i=0;i<n;i++){
					parent[i]=i;
					rank[i]=1;
				}
				cnt=n;
			}
			int find(int i){
		        while(parent[i] !=i){
		        	parent[i]=parent[parent[i]];
		        	i=parent[i];
		        }
		        return i;
		    }
			int Union(int x, int y){
		        int xset = find(x);
		        int yset = find(y);
		        if(xset!=yset)
		        	cnt--;
		        if(rank[xset]<rank[yset]){
		        	parent[xset] = yset;
			        rank[yset]+=rank[xset];
			        rank[xset]=0;
			        return yset;
		        }else{
		        	parent[yset]=xset;
		        	rank[xset]+=rank[yset];
		        	rank[yset]=0;
		        	return xset;
		        }
		    }
		}
	  public static int[][] packU(int n, int[] from, int[] to, int max) {
		    
		    int[][] g = new int[n][];
		    int[] p = new int[n];
		    for (int i = 0; i < max; i++) p[from[i]]++;
		    for (int i = 0; i < max; i++) p[to[i]]++;
		    for (int i = 0; i < n; i++) g[i] = new int[p[i]];
		    for (int i = 0; i < max; i++) {
		        g[from[i]][--p[from[i]]] = to[i];
		        g[to[i]][--p[to[i]]] = from[i];
		    }
		    return g;
		}
		public static int[][] parents3(int[][] g, int root) {
		    int n = g.length;
		    int[] par = new int[n];
		    Arrays.fill(par, -1);
	 
		    int[] depth = new int[n];
		    depth[0] = 0;
	 
		    int[] q = new int[n];
		    q[0] = root;
		    for (int p = 0, r = 1; p < r; p++) {
		        int cur = q[p];
		        for (int nex : g[cur]) {
		            if (par[cur] != nex) {
		                q[r++] = nex;
		                par[nex] = cur;
		                depth[nex] = depth[cur] + 1;
		            }
		        }
		    }
		    return new int[][]{par, q, depth};
		}
		public static int lower_bound(int[] nums, int target) {
	        int low = 0, high = nums.length - 1;
	        while (low < high) {
	            int mid = low + (high - low) / 2;
	            if (nums[mid] < target)
	                low = mid + 1;
	            else
	                high = mid;
	        }
	        return nums[low] == target ? low : -1;
	    }
	 
	    public static int upper_bound(int[] nums, int target) {
	        int low = 0, high = nums.length - 1;
	        while (low < high) {
	            int mid = low + (high + 1 - low) / 2;
	            if (nums[mid] > target)
	                high = mid - 1;
	            else
	                low = mid;
	        }
	        return nums[low] == target ? low : -1;
	    }
	  public static boolean palin(String s)
		{
		   int i=0;
		   int j=s.length()-1;
		   while(i<j)
		   {
			   if(s.charAt(i)==s.charAt(j))
			   {
				   i++;
				   j--;
			   }
			   else return false;     
		   }
		   return true;
		}
		
	    static boolean CountPs(String s,int n)
	       {
	    	boolean b=false;
	    	     char[] S=s.toCharArray();
		       int[][] dp=new int[n][n];
		       boolean[][] p=new boolean[n][n];
		       for(int i=0;i<n;i++)p[i][i]=true;
		     
		       for(int i=0;i<n-1;i++)
		       {
		    	   if(S[i]==S[i+1])
		    	   {
		    		p[i][i+1]=true;
		    		dp[i][i+1]=1;
		    		b=true;
		    	   }
		       }
		    
		       for(int gap=2;gap<n;gap++)
		       {
		    	   for(int i=0;i<n-gap;i++)
		    	   {
		    		   int j=gap+i;
		    		   if(S[i]==S[j]&&p[i+1][j-1]){p[i][j]=true;}
		    		  
		    		  if(p[i][j])
		    			   dp[i][j]=dp[i][j-1]+dp[i+1][j]+1-dp[i+1][j-1];
		    		   
		    		   else  dp[i][j]=dp[i][j-1]+dp[i+1][j]-dp[i+1][j-1];
		    		  
		    		   if(dp[i][j]>=1){b=true;}
		    	   }
		       }
		      
		    return b; 
	   // return dp[0][n-1];
		       
	    }
	  
	  
	  
	 
	 
	public static int gcd(int a,int b)
	{
		int res=1;
		while(a>0)
		{
			res=a;
			a=b%a;
			b=res;
		}
		return res;
	}
	 
	 
	public static long pow(long n,long p,long m)
	{
		 long  result = 1;
		  if(p==0)
		    return 1;
		if (p==1)
		    return n;
		while(p!=0)
		{
		    if(p%2==1)
		        result *= n;
		    if(result>=m)
		    result%=m;
		    p >>=1;
		    n*=n;
		    if(n>=m)
		    n%=m;
		}
		return result;
	}
	public static long pow(long n,long p)
	{
		long  result = 1;
		  if(p==0)
		    return 1;
		if (p==1)
		    return n;
		while(p!=0)
		{
		    if(p%2==1)
		        result *= n;
		    p >>=1;
		    n*=n;
		}
		return result;
	 
	}
	 
	 
	 
	 
	static class Edge implements Comparator<Edge> {
		private int u;
		private int v;
		private int w;
		public Edge() {
		}
		public Edge(int u, int v, int w) {
			this.u=u;
			this.v=v;
			this.w=w;
		}
		public int getU() {
			return u;
		}
		public void setU(int u) {
			this.u = u;
		}
		public int getV() {
			return v;
		}
		public void setV(int v) {
			this.v = v;
		}
		public int getW() {
			return w;
		}
		public void setW(int w) {
			this.w = w;
		      }
		public int compareTo(Edge e)
		  {
			return this.getW() - e.getW();
		}
		@Override
		public String toString() {
			return "Edge [u=" + u + ", v=" + v + ", w=" + w + "]";
		}
		@Override
		public int compare(Edge e1, Edge e2) {
			if(e1.u==e2.u)return e1.v-e2.v;
			return e1.u-e2.u;
			
		}
	}
	 
	 
	 
	static class Pair implements Comparable<Pair>
	{
		int a,b;
		Pair (int a,int b)
		{
			this.a=a;
			this.b=b;
		}
	 
		public int compareTo(Pair o) {
			// TODO Auto-generated method stub
			if(this.a!=o.a)
			return -Integer.compare(this.a,o.a);
			else
				return -Integer.compare(this.b, o.b);
			//return 0;
		}
		public boolean equals(Object o) {
	       if (o instanceof Pair) {
	           Pair p = (Pair)o;
	           return p.a == a && p.b == b;
	       }
	       return false;
	   }
	   public int hashCode() {
	       return new Integer(a).hashCode() * 31 + new Integer(b).hashCode();
	   }
	}
	 
		static class InputReader
		{
			private InputStream stream;
			private byte[] buf = new byte[1024];
			private int curChar;
			private int numChars;
			private SpaceCharFilter filter;
			
			public InputReader(InputStream stream)
			{
				this.stream = stream;
			}
			
			public int read()
			{
				if (numChars==-1) 
					throw new InputMismatchException();
				
				if (curChar >= numChars)
				{
					curChar = 0;
					try 
					{
						numChars = stream.read(buf);
					}
					catch (IOException e)
					{
						throw new InputMismatchException();
					}
					
					if(numChars <= 0)				
						return -1;
				}
				return buf[curChar++];
			}
		 
			public String nextLine()
			{
				BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
				String str = "";
	            try
	            {
	                str = br.readLine();
	            }
	            catch (IOException e)
	            {
	                e.printStackTrace();
	            }
	            return str;
			}
			public int ii()
			{
				int c = read();
				
				while(isSpaceChar(c)) 
					c = read();
				
				int sgn = 1;
				
				if (c == '-') 
				{
					sgn = -1;
					c = read();
				}
				
				int res = 0;
				do 
				{
					if(c<'0'||c>'9') 
						throw new InputMismatchException();
					res *= 10;
					res += c - '0';
					c = read();
				}
				while (!isSpaceChar(c)); 
				
				return res * sgn;
			}
			
			public long il() 
			{
				int c = read();
				while (isSpaceChar(c))
					c = read();
				int sgn = 1;
				if (c == '-') 
				{
					sgn = -1;
					c = read();
				}
				long res = 0;
				
				do 
				{
					if (c < '0' || c > '9')
						throw new InputMismatchException();
					res *= 10;
					res += c - '0';
					c = read();
				}
				while (!isSpaceChar(c));
					return res * sgn;
			}
			
			public double nextDouble() 
			{
				int c = read();
				while (isSpaceChar(c))
					c = read();
				int sgn = 1;
				if (c == '-') 
				{
					sgn = -1;
					c = read();
				}
				double res = 0;
				while (!isSpaceChar(c) && c != '.') 
				{
					if (c == 'e' || c == 'E')
						return res * Math.pow(10, ii());
					if (c < '0' || c > '9')
						throw new InputMismatchException();
					res *= 10;
					res += c - '0';
					c = read();
				}
				if (c == '.') 
				{
					c = read();
					double m = 1;
					while (!isSpaceChar(c)) 
					{
						if (c == 'e' || c == 'E')
							return res * Math.pow(10, ii());
						if (c < '0' || c > '9')
							throw new InputMismatchException();
						m /= 10;
						res += (c - '0') * m;
						c = read();
					}
				}
				return res * sgn;
			}
			
			public String readString() 
			{
				int c = read();
				while (isSpaceChar(c))
					c = read();
				StringBuilder res = new StringBuilder();
				do 
				{
					res.appendCodePoint(c);
					c = read();
				} 
				while (!isSpaceChar(c));
				
				return res.toString();
			}
		 
			public boolean isSpaceChar(int c) 
			{
				if (filter != null)
					return filter.isSpaceChar(c);
				return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
			}
		 
			public String next() 
			{
				return readString();
			}
			
			public interface SpaceCharFilter 
			{
				public boolean isSpaceChar(int ch);
			}
		}
	}
