/* package codechef; // don't place package name! */



import java.io.ByteArrayInputStream;

import java.io.IOException;

import java.io.InputStream;

import java.io.PrintWriter;

import java.util.Arrays;

import java.util.InputMismatchException;



class PAPER {

	InputStream is;

	PrintWriter out;

	String INPUT = "";

	

	void solve()

	{

		for(int T = ni();T > 0;T--){

			int n = ni(), m = ni();

			int W = ni(), H = ni();

			char[] s = ns(n);

			int[][] co = new int[m][];

			for(int i = 0;i < m;i++){

				co[i] = na(2);

			}

			long min = Long.MAX_VALUE;

			for(int i = 0;i < m;i++){

				for(int j = i+1;j < m;j++){

					min = Math.min(min,

							(long)(co[i][0]-co[j][0])*(co[i][0]-co[j][0])

							+

							(long)(co[i][1]-co[j][1])*(co[i][1]-co[j][1])

							);

				}

			}

			long lw = W, rw = W;

			long uh = H, dh = H;

			for(int i = 0;i < m;i++){

				lw = Math.min(lw, co[i][0]);

				rw = Math.min(rw, W-co[i][0]);

				dh = Math.min(dh, co[i][1]);

					uh = Math.min(uh, H-co[i][1]);

			}

			for(int i = n-1;i >= 0;i--){

				if(s[i] == 'D'){

					min = Math.min(min, (2*dh)*(2*dh));

					dh = uh;

				}else if(s[i] == 'U'){

					min = Math.min(min, (2*uh)*(2*uh));

					uh = dh;

				}else if(s[i] == 'R'){

					min = Math.min(min, (2*rw)*(2*rw));

					rw = lw;

				}else if(s[i] == 'L'){

					min = Math.min(min, (2*lw)*(2*lw));

					lw = rw;

				}

			}

			out.printf("%.14f\n", Math.sqrt(min));

		}

	}

	

	void run() throws Exception

	{

		is = INPUT.isEmpty() ? System.in : new ByteArrayInputStream(INPUT.getBytes());

		out = new PrintWriter(System.out);

		

		long s = System.currentTimeMillis();

		solve();

		out.flush();

		if(!INPUT.isEmpty())tr(System.currentTimeMillis()-s+"ms");

	}

	

	public static void main(String[] args) throws Exception { new PAPER().run(); }

	

	private byte[] inbuf = new byte[1024];

	public int lenbuf = 0, ptrbuf = 0;

	private int readByte()

	{

		if(lenbuf == -1)throw new InputMismatchException();

		if(ptrbuf >= lenbuf){

			ptrbuf = 0;

			try { lenbuf = is.read(inbuf); } catch (IOException e) { throw new InputMismatchException(); }

			if(lenbuf <= 0)return -1;

		}

		return inbuf[ptrbuf++];

	}

	

	private boolean isSpaceChar(int c) { return !(c >= 33 && c <= 126); }

	private int skip() { int b; while((b = readByte()) != -1 && isSpaceChar(b)); return b; }

	

	private double nd() { return Double.parseDouble(ns()); }

	private char nc() { return (char)skip(); }

	

	private String ns()

	{

		int b = skip();

		StringBuilder sb = new StringBuilder();

		while(!(isSpaceChar(b))){ // when nextLine, (isSpaceChar(b) && b != ' ')

			sb.appendCodePoint(b);

			b = readByte();

		}

		return sb.toString();

	}

	

	private char[] ns(int n)

	{

		char[] buf = new char[n];

		int b = skip(), p = 0;

		while(p < n && !(isSpaceChar(b))){

			buf[p++] = (char)b;

			b = readByte();

		}

		return n == p ? buf : Arrays.copyOf(buf, p);

	}

	

	private char[][] nm(int n, int m)

	{

		char[][] map = new char[n][];

		for(int i = 0;i < n;i++)map[i] = ns(m);

		return map;

	}

	

	private int[] na(int n)

	{

		int[] a = new int[n];

		for(int i = 0;i < n;i++)a[i] = ni();

		return a;

	}

	

	private int ni()

	{

		int num = 0, b;

		boolean minus = false;

		while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));

		if(b == '-'){

			minus = true;

			b = readByte();

		}

		

		while(true){

			if(b >= '0' && b <= '9'){

				num = num * 10 + (b - '0');

			}else{

				return minus ? -num : num;

			}

			b = readByte();

		}

	}

	

	private long nl()

	{

		long num = 0;

		int b;

		boolean minus = false;

		while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));

		if(b == '-'){

			minus = true;

			b = readByte();

		}

		

		while(true){

			if(b >= '0' && b <= '9'){

				num = num * 10 + (b - '0');

			}else{

				return minus ? -num : num;

			}

			b = readByte();

		}

	}

	

	private void tr(Object... o) { if(INPUT.length() > 0)System.out.println(Arrays.deepToString(o)); }

}



