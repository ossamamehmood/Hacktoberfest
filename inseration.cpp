//#include<iostream>
//using namespace std;
//int main()
//{
//	int n;
//	cout << "How many numbers enter ? "; cin >> n;
//	int* arr = new int[n];
//	cout << "Enter a numbers\n";
//	for (size_t i = 0; i < n; i++)
//	{
//		cin >> arr[i];
//	}
//
//	for (size_t i = 0; i < n; i++)
//	{
//		int curr = arr[i];
//		int j = i - 1;
//		while (arr[j]>curr && j>=0)
//		{
//			arr[j + 1] = arr[j];
//		   j--;
//		}arr[j + 1] = curr;
//	}
//	cout << "Display\n";
//	for (size_t i = 0; i < n; i++)
//	{
//		cout << arr[i] << " ";
//	}
//
//	delete[]arr;
//	arr = 0;
//}