#ifndef map_H
#define map_H
#include<iostream>
#include<stdlib.h>
#include<iomanip>
#include<vector>

class Map {
    private:
  int check(char*);
  void swap(char* , char*);
  void permute(char *a, int l, int r);
  int** arr;
  char** route1;
  char** route2;
  char** route3;
  int distance{} , x{} , y{} ,right{} , down{} , diagonal{};
  std::string less_distance;
  int minimum{};
 public:
  Map(int N);
  ~Map();
   void showMap();
   void findRoute1();
   void findRoute2();
   void findRoute3();
   void showRoute1();
   void showRoute2();
   void showRoute3();
   int N;
};

#endif
