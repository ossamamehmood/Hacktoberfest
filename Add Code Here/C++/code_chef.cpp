// HourGlass Problem-
#include <iostream>
using namespace std;

int maxValue(int arr[16])
{
   int max = arr[0];
   for (int i = 0; i < 16; i++)
   {
      if (max < arr[i])
         max = arr[i];
   }
   return max;
}

int hourGlass(int arr[6][6])
{
   int hourGlassSum[16];
   int k = 0;

   while (k < 16)
   {
      for (int i = 0; i < 4; i++)
      {
         for (int j = 0; j < 4; j++)
         {
            hourGlassSum[k] = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j + 1] + arr[i + 2][j] + arr[i + 2][j + 1] + arr[i + 2][j + 2];
            cout << "Sum of Hourglass[" << k << "]: " << hourGlassSum[k] << endl;
            k++;
         }
      }
   }
   cout << maxValue(hourGlassSum);
   return 0;
}

int main()
{
   int arr[6][6];
   cout << "Enter the array elements:\n";
   for (int i = 0; i < 6; i++)
   {
      for (int j = 0; j < 6; j++)
      {
         cin >> arr[i][j];
      }
   }
   hourGlass(arr);
   return 0;
}