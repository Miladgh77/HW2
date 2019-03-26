#include"map.h"

Map::Map(int n){  
  N = n;
  arr = new int*[N];
  for(int i{} ; i < N ; i++)
    {
    arr[i] = new int[N];
    }
   srand(time(NULL));
  for(int i{} ; i < N ; i++)
    {
    for(int j{} ; j < N ; j++)
      arr[i][j] = rand() % 100 +1;
    }

   route1 = new char*[N];
  for(int i{} ; i < N ; i++)
    route1[i] = new char[N];
   for(int i{} ; i < N ; i++)
     {
    for(int j{} ; j < N ; j++)
      route1[i][j] = '-';
     }

      route2 = new char*[N];
  for(int i{} ; i < N ; i++)
    route2[i] = new char[N];
   for(int i{} ; i < N ; i++)
     {
    for(int j{} ; j < N ; j++)
      route2[i][j] = '-';
     }
   
     route3 = new char*[N];
  for(int i{} ; i < N ; i++)
    route3[i] = new char[N];
   for(int i{} ; i < N ; i++)
     {
    for(int j{} ; j < N ; j++)
      route3[i][j] = '-';
     }
}

Map::~Map() {
  
   for(int i{} ; i < N ; i++)
     delete[] arr[i];
   delete[] arr;

   for(int i{} ; i < N ; i++)
     delete[] route1[i];
   delete[] route1;

    for(int i{} ; i < N ; i++)
     delete[] route2[i];
   delete[] route2;

    for(int i{} ; i < N ; i++)
     delete[] route3[i];
   delete[] route3;
 
}
void Map::showMap(){
 for(int i{} ; i < N ; i++)
   {
   for(int j{} ; j < N ; j++)
     {
       std::cout <<std:: setw(3) << arr[i][j] << " ";
     }
   std::cout << std::endl;
   }
 
  }

void Map::findRoute1()
{
  route1[0][0] = '*';
  while(x != N-1 || y != N-1)
    {
      if ( x == N-1)
	{
	  y++;
	  distance += abs( arr[y][x] - arr[y-1][x] );
	  route1[y][x] = '*'; 
	}
      else if ( y == N-1)
	{
	  x++;
	  distance += abs( arr[y][x] - arr[y][x-1] );
	  route1[y][x] = '*'; 
	}
      else
	{
	  down = abs( arr[y+1][x] - arr[y][x] );
	  right = abs (arr[y][x+1] - arr[y][x] );
	 

	  if ( down <= right)
	    {
	      y++;
	      distance +=down ;
	    }
	  else if (right <= down )
	    {
	    x++;
	    distance += right ;
	    }
	  route1[y][x] = '*';
	}
      
    }
  std::cout << "Distance1: "<< distance << std::endl;
}
void Map::findRoute2()
{
  route2[0][0] = '*';
  x=0;
  y=0;
  while(x != N-1 || y != N-1)
    {
      if ( x == N-1)
	{
	  y++;
	  distance += abs( arr[y][x] - arr[y-1][x] );
	  route2[y][x] = '*'; 
	}
      else if ( y == N-1)
	{
	  x++;
	  distance += abs( arr[y][x] - arr[y][x-1] );
	  route2[y][x] = '*'; 
	}
      else
	{
	  down = abs( arr[y+1][x] - arr[y][x] );
	  right = abs (arr[y][x+1] - arr[y][x] );
	  diagonal = abs (arr[y+1][x+1] - arr[y][x] );

	  if ( down <= right && down <= diagonal)
	    {
	      y++;
	      distance +=down ;
	    }
	  else if (right <= down && right <= diagonal)
	    {
	    x++;
	    distance += right ;
	    }
	  else
	    {
	    x++;
	    y++;
	    distance += diagonal ;
	    }
	  route2[y][x] = '*';
	}
      
    }
  std::cout << "Distance2: "<< distance << std::endl;
}

void Map::findRoute3()
{
  char str[2*N-2];
  for(int i{}; i < (N-1); i++)
    {
      str[i]='R';
    }
  for(int i{N-1}; i <(2*N-2); i++)
    {
      str[i]='D';
    }
  distance = check (str);
  less_distance = str;
  permute(str , 0 , 2*N-3);
  x = 0;
  y = 0;
  route3[y][x]='*';
  
  for(int i{} ; i < 2*N-2 ; i++)
    {
      if (less_distance[i] == 'D')
	{
	  y++;
	  route3[y][x]='*';
	}
      else if (less_distance[i] == 'R')
	{
	  x++;
	  route3[y][x]='*'; 
	}
    }
  std::cout << "Distance3: "<< distance << std::endl;
}

void Map::showRoute1(){
  std::cout<<"Route1:"<<std::endl;
for(int i{} ; i < N ; i++)
   {
   for(int j{} ; j < N ; j++)
     {
     std::cout << route1[i][j] << " ";
     }
   std::cout << std::endl;
   }
}

 void Map::showRoute2(){
   std::cout<<"Route2:"<<std::endl;
 for(int i{} ; i < N ; i++)
   {
   for(int j{} ; j < N ; j++)
     {
     std::cout << route2[i][j] << " ";
     }
   std::cout << std::endl;
   }
 }

 void Map::showRoute3(){
   std::cout<<"Route3:"<<std::endl;
 for(int i{} ; i < N ; i++)
   {
   for(int j{} ; j < N ; j++)
     {
     std::cout << route3[i][j] << " ";
     }
   std::cout << std::endl;
   }
}



void Map::permute(char *a, int l, int r) 
{ 
  
  if (l == r )
    {
    int min = check(a);
    if(min < distance)
      {
	distance = min;
	less_distance = a;
      }
    }
      
   
   else
   { 
       for (int i = l; i <= r; i++) 
       { 
          swap((a+l), (a+i)); 
          permute(a, l+1, r); 
          swap((a+l), (a+i)); //backtrack 
       } 
   } 
}

void Map::swap(char *x, char *y) 
{ 
    char temp; 
    temp = *x; 
    *x = *y; 
    *y = temp; 
}

int Map::check(char*b)
  {
    x = 0;
    y = 0;
    int count{};
    for(int i{} ; i < 2*N-2 ; i++)
      {
	if (b[i] == 'D')
	  {
	  y++;
	  count += abs(arr[y][x]-arr[y-1][x]);
	  }
	else if (b[i] == 'R')
	  {
	    x++;
	    count += abs(arr[y][x]-arr[y][x-1]);
	  }
       }
	  return count;
  }

