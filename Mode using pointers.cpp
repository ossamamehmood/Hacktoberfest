//#include <iostream>
//using namespace std;
//
//int findMode(int* arr, int size)
//{
//	int number;
//	int max = 0;
//	int count = 0;
//	int mode=0;
//	for (int i = 0; i < size; i++)
//	{
//		number = arr[i];
//		count = 0;
//		for (int j = 0; j < size; j++)
//		{
//			if (number == arr[j])
//			{
//				count++;
//			}
//		}
//		if (max < count)
//		{
//			max = count;
//			mode = number;
//		}
//	}
//	if (max == 1)
//	{
//		return -1;
//	}
//	else
//	{
//		return mode;
//	}
//}
//int main()
//{
//	int size;
//	int* arr;
//	cout << "Total Number of Elements : ";
//	cin >> size;
//	arr = new int[size];
//	cout << "Enter elements of array\n";
//	for (int i = 0; i < size; i++)
//	{
//		cin >> arr[i];
//	}
//
//	int res=findMode(arr, size);
//	if (res == -1)
//	{
//		cout << "No Mode Exist!\n";
//	}
//	else
//	{
//		cout << "Mode : " << res;
//	}
//	return 0;
//}