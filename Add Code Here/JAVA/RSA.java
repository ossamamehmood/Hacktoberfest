import java.math.*;

class RSA {
	public static void main(String args[])
	{
		int p, q, n, phiN, d = 0, e, i;

		int msg = 12;
		double c;
		BigInteger msgback;

		p = 7;

		q = 11;
		System.out.println("Value of P is "+p+" and Value of q is "+q);
		n = p * q;
		phiN = (p - 1) * (q - 1);
		System.out.println("phiN value of phiN = " + phiN);

		for (e = 2; e < phiN; e++) {

			if (gcd(e, phiN) == 1) {
				break;
			}
		}
		System.out.println("The value of e = " + e);
		for (i = 0; i <= 9; i++) {
			int x = 1 + (i * phiN);

			if (x % e == 0) {
				d = x / e;
				break;
			}
		}
		System.out.println("The value of d = " + d);
		c = (Math.pow(msg, e)) % n;
		System.out.println("Encrypted message is : " + c);
		BigInteger N = BigInteger.valueOf(n);
		BigInteger C = BigDecimal.valueOf(c).toBigInteger();
		msgback = (C.pow(d)).mod(N);
		System.out.println("Decrypted message is : "
						+ msgback);
	}

	static int gcd(int e, int phiN)
	{
		if (e == 0)
			return phiN;
		else
			return gcd(phiN % e, e);
	}
}
