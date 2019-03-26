#include"libVec.h"
#include"libArr.h"
#include<iostream>
#include<chrono>
#include<functional>
template <class C>
long int runTime(void (C::* Fun)(int), int n)
{
  
  auto start = std::chrono::high_resolution_clock::now();
  C a;
  (a.*Fun)(n);
  auto end = std::chrono::high_resolution_clock::now();
  auto duration=std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
  return duration.count();
}

int main()
{
  //libVec::counter(5);
  void (libVec::* ptr2fun)(int) = &libVec::counter;
  void (libArr::* ptfptr)(int) = &libArr::counter;
  std::cout << runTime(ptr2fun, 10000000) << std::endl;
  std::cout << runTime(ptfptr, 1000000) << std::endl;
  return 0;
}


