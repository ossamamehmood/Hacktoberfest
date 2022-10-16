//Program that checks if a given number is palindrome or not

void main() {
  int n=1331;
  int copy = n;
  int rev=0;
  
  while(n!=0){
    rev=rev*10 + n%10;
    n=(n/10).round();
  }
  
  if(rev==copy)
  {
    print('Palindrome');
  }
  else
  {
    print('Not Palindrome');
  }
}
