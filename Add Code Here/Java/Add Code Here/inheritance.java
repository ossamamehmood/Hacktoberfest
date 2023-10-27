// --- Example of Simple Inheritance ---

// Creating a parent class
class A 
{
	int i,j; // instance variable
	
	void showij()
	{
		System.out.println("i and j : " + i + " " + j);  
	}
}

// Creating a child class
class B extends A  // B inherits A by default
{
	int k;
	
	void showk()
	{
		System.out.println("k : " + k);
	}
	void sum()
	{
		System.out. println("i + j + k : " + (i+j+k));
	}
}

// Main/Driver class
class SimpleInheritance
{
	public static void main(String args[])
	{
		A superOb = new A(); // Creating object of class A
		B subOb = new B(); // Creating object of class B
		
		// The Parent class may be used by itself
		superOb.i = 10;
	    superOb.j = 20;
		System.out.println("Contents of SuperOb : ");
		superOb.showij();
		System.out.println(); // For new line
		
		// The child class has access to all public members of its parent class
		subOb.i = 7;
		subOb.j = 8;
		subOb.k = 9;
		System.out.println("Contents of subOb : ");
		subOb.showij();
		subOb.showk();
		System.out.println(); // For new line
		
		System.out. println("Sum of i,j and k in subOb = ");
		subOb.sum();
	}
}


