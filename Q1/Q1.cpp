#include<iostream>
#include"map.h"

int main()
{
  Map map1{6};
  map1.showMap();
  map1.findRoute1();
  map1.findRoute2();
  map1.findRoute3();
  map1.showRoute1();
  map1.showRoute2();
  map1.showRoute3();
  return 0;
}
