// A Template function area that calculates are of different shapes.

#include<iostream>
#include<cmath>
using namespace std;
template<class T>
T area(T l, T w, T h)
{
	return 2 * (l * w + w * h + h * l); //for cube
};
template<class T>
T area(T l, T w)
{
	return l * w;
};
template<class T>
T area(T r)
{
	return M_PI * r * r;
};
int main()
{
	int choice = 0;
	while(choice != 4)
	{
		cout << "\nCalculate area for:\n1 -> Cuboid\n2 -> Square/Rectangle\n3 -> Circle\n4 -> Exit\nEnter your choice: ";
		cin >> choice;
		switch(choice)
		{
			case 1:
				float l, w, h;
				cout << "\nEnter length, width and height  for the cuboid: ";
				cin >> l >> w >> h;
				cout << "\nArea: " << area<float>(l, w, h) << endl;
				break;
			case 2:
				float x, y;
				cout << "\nEnter length and width for square/rectangle: ";
				cin >> x >> y;
				cout << "\nArea: " << area<float>(x, y) << endl;
				break;
			case 3:
				float r;
				cout << "\nEnter the radius of the circle:  ";
				cin >> r;
				cout << "\nArea: " << area<float>(r) << endl;
				break;
			case 4:
				break;
			default:
				cout << "\nInvalid Input\n";
				break;
		}
	}
	return 0;
}
