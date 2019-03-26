#include<iostream>
#include<fstream>
#include<vector>
#include<stdlib.h>

int product_count(std::vector<std::string*>*,int,int);
int costumer_count(std::vector<std::string*>*,int,int);

int main()
{
std::string parsstr[4];
  std::vector <std::string*> input;
  std::vector <std::string*> output;
  std::ifstream readfile {"db.txt"};
  int daybegin{};
  while (readfile >> parsstr[0])
    {    
      readfile >> parsstr [1];
      readfile >> parsstr [2];
      readfile >> parsstr [3];
      input.push_back(new std::string[4]);
     
       for(size_t i{} ; i<4 ; i++)
	{
	  input[input.size() - 1][i] = parsstr[i];
	}
    }
   for (size_t i{} ; i<input.size() ;i++)
     {
       if(input[i][0] != input[daybegin][0])
	 {
	  output.push_back(new std::string[3]); 
	  output[output.size()-1][0] = input[daybegin][0];
	  output[output.size()-1][1] = '0'+ product_count(&input,daybegin,i-1);
	  output[output.size()-1][2] = '0'+ costumer_count(&input,daybegin,i-1);
	  daybegin = i;
	 }
        
       if((i==(input.size()-1)))
	 {
	  output.push_back(new std::string[3]); 
	  output[output.size()-1][0] = input[daybegin][0];
	  output[output.size()-1][1] = '0'+ product_count(&input,daybegin,i);
	  output[output.size()-1][2] = '0'+ costumer_count(&input,daybegin,i);
	 
	 }
     }
 std::ofstream writefile {"dbnew.txt"};
 for(size_t i{} ; i<output.size() ; i++)
   {
     writefile << output[i][0] << "] ";
     writefile << output[i][1] << " ";
     writefile << output[i][2] << std::endl;
   }
  return 0;
}



int product_count(std::vector<std::string*>* input,int start, int end)
{
  int sameid{};
  if(start == end)
    {
      return 1;
    }
  else
    {
  for(int i{start+1}; i <= end  ; i++)
    {
      for(int check{start};check <= i-1;check++)
      {
	if((*input)[check][2]==(*input)[i][2])
	  {
	    sameid++;
	    check = start;
	    i++;
	  }
	if(i>=end)
	  {
	    break;
	  }
      }
    }
  return (end - start - sameid +1);
    }
}

int costumer_count(std::vector<std::string*>* input , int start , int end)
{
   int sameid{};
   if(start == end)
     {
       return 1;
     }
   else
     {
  for(int i{start+1}; i <= end  ; i++)
    {
      for(int check{start};check <= i-1;check++)
      {
	if((*input)[check][3]==(*input)[i][3])
	  {
	    sameid++;
	    check = start;
	    i++;
	  }
	if(i>=end)
	  {
	    break;
	  }
      }
    }
  return (end - start - sameid +1);
   }
}
