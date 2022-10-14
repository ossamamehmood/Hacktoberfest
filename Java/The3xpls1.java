import java.math.BigInteger;

public class The3xpls1{
	public static void main(String[] args){
		System.out.println("This is the 3x + 1 problem =============");

		BigInteger choise = new BigInteger(args[0]);
		BigInteger highest = choise;
		BigInteger result = choise;

		// int tester = 200000;
		// int pointer = 0;
		while(!result.equals(BigInteger.ONE)){
			// if(pointer == tester){
			// 	break;
			// }
			if(result.mod(new BigInteger("2")).equals(BigInteger.ZERO)){
				result = result.divide(BigInteger.valueOf(2));
			} else {
				result = result.multiply(BigInteger.valueOf(3)).add(BigInteger.valueOf(1));
			}
			if(result.compareTo(highest) == 1){
				highest = result;
			}
			// pointer++;
		}
		System.out.println("The highest for this is: "+highest);
	}
}