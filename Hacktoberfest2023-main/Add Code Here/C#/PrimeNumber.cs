Console.WriteLine("Enter a number");
int num = Convert.ToInt32(Console.ReadLine());

int div = Convert.ToInt32(Math.Sqrt(num));
int c = 0;

for (int i = 2; i <= div; i++)
{
    if(num % i == 0)
    {
        c++;
    }
}

if (c == 0) Console.WriteLine($"{num} is a prime number");
else Console.WriteLine($"{num} is not a prime number");