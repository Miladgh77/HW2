#include"libArr.h"

int libArr::counter(int n)
{
  int count{};
  int arr[n];
  for (int i{} ; i < n ; i++)
    {
      arr[i] = i;
    }
   for (int i{} ; i < n ; i++)
    {
      count += arr[i]; 
    }
   return count;
}
