#include"libVec.h"



int libVec::counter(int n)
{
  int count{};
  for (int i{} ; i < n; i++)
    {
       a.push_back(i);
    }
   for (int i{} ; i < n; i++)
    {
      count += a[i];
    }
   return count;
}
