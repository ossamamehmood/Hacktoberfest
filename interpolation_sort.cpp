if (ar[mid] < value)
    {
      low = mid + 1;
    }
    else if (ar[mid] > value)
    {
      low = mid - 1;
    }
    else
    {
      return mid;
    }
  }
 
  if (ar[low] == value)
  {
    return low;
  }
  else
  {
    return -1;
  }
}
int main()
{
  int ar [] = {1, 2, 78, 18, 16, 30, 29, 2, 0, 199};
  int value, pos;
 
  cout << "Your Array : ";
  print_ar (ar, 10);
 
  cout << "Enter the value to search : ";
  cin >> value;
  pos = interpolation_search (ar, value, 10);
  if (pos != -1)
  {
    cout << "Value Found! at position : " << pos + 1 << endl;
  }
  else
  {
    cout << "Sorry, the value you searched for is not present." << endl;
  }
 
  return 0;
}
