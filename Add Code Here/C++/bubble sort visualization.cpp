#include <iostream>
using namespace std;
#define n 10
int main()
{
	system("color c");
	int arr[n] = {7, 1, 5, 0, 2, 4, 6, 3, 8, 9};
	printf("Array to sort :- ");
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << "\n\n";

	for (int i = 0; i < n; i++)
	{
		system("color e");
		cout << i << " item sorted.\n";

		for (int k = 0; k < n; k++)
		{
			if (k < n - i)
				system("color 7");
			else
				system("color c");
			cout << arr[k] << endl;
		}
		system("color e");
		cout << "\n\n"
			 << "_________________________________________________\n"
			 << i + 1 << " iteration" << endl;
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				system("color d");
				cout << j + 1 << ") Check & swap " << arr[j] << " & " << arr[j + 1];
				arr[j] += arr[j + 1];
				arr[j + 1] = arr[j] - arr[j + 1];
				arr[j] -= arr[j + 1];
				for (int k = 0; k < n; k++)
				{
					system("color ff");
					cout << arr[k] << " ";
				}
				cout << "\n";
			}
			else
			{
				system("color b");
				cout << j + 1 << ") Check " << arr[j] << " & " << arr[j + 1] << '\n';
				for (int k = 0; k < n; k++)
				{
					system("color ff");
					cout << arr[k] << " ";
				}
				cout << "\n";
			}
			cout << endl;
		}
	}

	system("color e");
	cout << "All item sorted" << endl;
	system("color c");
	cout << "\nSorted Array\n";
	for (int i = 0; i < n; i++)
		cout << arr[i] << endl;
	system("color f");
	return 0;
}
