//-------------------------------------------------------------
//Author:     Ryan Wagner
//Date:       August 22, 2014
//Description:Pivot Table (Dailyprogrammer Challenge #176 Easy)
//Input:      Text file windfarm.dat
//Output:     Pivot utilizing the three input fields.
//-------------------------------------------------------------

#include<iostream>
#include<fstream>
#include<string>

struct results{
  int terminal[10];
  std::string day[7];
  int kWh[10][7];
};

results buildResults(int i){
  results res={{1000,1001,1002,1003,1004,1005,1006,1007,1008,1009},
  {"Mon","Tue","Wed","Thu","Fri","Sat","Sun"},0};
  int terminal,kWh;
  std::string day;
  std::ifstream infile("windfarm.dat");
  while(infile>>terminal>>day>>kWh){
    for(i=0;day.compare(res.day[i]);i++);
    res.kWh[terminal-1000][i]+=kWh;
  }
  infile.close();
  return res;
}

void printChart(results res,int i, int j){
  for(i=0;i<7;i++){
    std::cout<<"\t"<<res.day[i];
  }
  std::cout<<'\n';
  for(i=0;i<sizeof(res.terminal)/sizeof(res.terminal[0]);i++){
    std::cout<<res.terminal[i]<<"\t";
    for(j=0;j<sizeof(res.day)/sizeof(res.day[0]);j++){
      std::cout<<res.kWh[i][j]<<"kWh\t";
    }
    std::cout<<'\n';
  }
}

int main(void){
  int i,j;
  results res = buildResults(i);
  printChart(res, i, j);
  return 0;
}
