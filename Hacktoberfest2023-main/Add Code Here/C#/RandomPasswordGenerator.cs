using System;

string s = "abcdefghijklmnpqrstuvwxyz1234567890!@#$%&*(){}[]";
string pass = String.Empty;

Console.WriteLine("Enter the length of your password");
int length = Convert.ToInt32(Console.ReadLine());

Random random = new Random();

for (int i = 0; i < length; i++)
{
    int n = random.Next(s.Length);
    pass += s[n];
}
Console.WriteLine(pass);