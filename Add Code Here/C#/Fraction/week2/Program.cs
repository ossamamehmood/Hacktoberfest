using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Practice2022_4_4
{
    class Program
    {
        static void Main(string[] args)
        {
            Fraction a = new Fraction();
            a.num = 6;
            a.den = 7;
            Fraction b = new Fraction(-5, -9);
            Fraction c = new Fraction();
            c = a/b;
            c.Simplify();
            Console.WriteLine(a/b);
            Console.ReadKey();
            
        }
        class Fraction {
            public int num;
            public int den;
            
            public Fraction()
            {
                den = 1;
                Console.WriteLine("A new object");
            }
            public Fraction(int num, int den = 1)
            {
                this.num = num;
                this.den = den;
            }
            public override string ToString()
            {
                return num + "/" + den;
            }
            //F(x), Sum(a, b) 
            // a+b = 
            // a>b = 
            public static Fraction operator +(Fraction a, Fraction b)
            {
                Fraction c = new Fraction();
                c.num = a.num * b.den + b.num * a.den;
                c.den = a.den * b.den;
                return c.Simplify() ;
            }
            public static Fraction operator -(Fraction a, Fraction b)
            {
                Fraction c = new Fraction();
                c.num = a.num * b.den - b.num * a.den;
                c.den = a.den * b.den;
                return c.Simplify();
            }
            public static bool operator >(Fraction a, Fraction b)
            {
                return a.num * b.den > b.num * a.den;
            }
            public static bool operator <(Fraction a, Fraction b)
            {
                return a.num * b.den < b.num * a.den;
            }
            public static bool operator <=(Fraction a, Fraction b)
            {
                return a.num * b.den <= b.num * a.den;
            }
            public static bool operator >=(Fraction a, Fraction b)
            {
                return a.num * b.den >= b.num * a.den;
            }
            public static bool operator ==(Fraction a, Fraction b)
            {
                return a.num * b.den == b.num * a.den;
            }
            public static bool operator !=(Fraction a, Fraction b)
            {
                return a.num * b.den != b.num * a.den;
            }
            public static Fraction operator *(Fraction a, Fraction b)
            {
                Fraction c = new Fraction();
                c.num = a.num * b.num;
                c.den = a.den * b.den;
                return c.Simplify();
            }
            public static Fraction operator /(Fraction a, Fraction b)
            {
                Fraction c = new Fraction();
                c.num = a.num * b.den;
                c.den = a.den * b.num;
                return c.Simplify();
            }
            public Fraction Simplify()
	{
		for (int divideBy = den; divideBy > 0; divideBy--)
		{
			bool divisible = true;

			if ((int)(num / divideBy) * divideBy != num)
			{
				divisible = false;
			}
			else if ((int)(den / divideBy) * divideBy != den)
			{
				divisible = false;
			}
			else if (divisible)
			{
				num /= divideBy;
				den /= divideBy;
			}
		}
		return this;
	}
        }
    }
        class Vector3{
            float x;
            float y;
            float z;
            public Vector3(){
            
            }
            public Vector3(float x, float y, float z){
                this.x=x;
                this.y=y;
                this.z=z;
            }
            public override string ToString(){
                return "This is Vector3 class";
            }
            public static Vector3 operator +(Vector3 v1, Vector3 v2)
            {
                Vector3 v3 = new Vector3();
                v3.x = v1.x + v2.x;
                v3.y = v1.y + v2.y;
                v3.z = v1.z + v2.z;
                return v3;
            }
            public static Vector3 operator -(Vector3 v1, Vector3 v2)
            {
                Vector3 v3 = new Vector3();
                v3.x = v1.x - v2.x;
                v3.y = v1.y - v2.y;
                v3.z = v1.z - v2.z;
                return v3;
            }
            public static Vector3 operator *(Vector3 v1, float a)
            {
                Vector3 v2 = new Vector3();
                v2.x = v1.x * a;
                v2.y = v1.y * a;
                v2.z = v1.z * a;
                return v2;
            }
            public static Vector3 operator /(Vector3 v1, float a)
            {
                Vector3 v2 = new Vector3();
                v2.x = v1.x / a;
                v2.y = v1.y / a;
                v2.z = v1.z / a;
                return v2;
            }
            public static double distance(Vector3 v1, Vector3 v2)
            {
                double len = Math.Sqrt(Math.Pow((v1.x-v2.x),2)+Math.Pow((v1.y-v2.y),2)+Math.Pow((v1.z-v2.z),2));
                return len;
            }
            public static bool operator ==(Vector3 v1, Vector3 v2)
            {
                return (v1.x==v2.x)||(v1.y==v2.y)||(v1.z==v2.z);
            }
            public static bool operator !=(Vector3 v1, Vector3 v2)
            {
                return (v1.x!=v2.x)||(v1.y!=v2.y)||(v1.z!=v2.z); 
            }
        }
}
