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

using namespace std;

struct results{
  int terminal[10];
  string day[7];
  int kWh[10][7];
};

results buildResults(int i, int j){
  results res={{1000,1001,1002,1003,1004,1005,1006,1007,1008,1009},
  {"Mon","Tue","Wed","Thu","Fri","Sat","Sun"},0};
  int terminal,kWh;
  string day;
  ifstream infile("windfarm.dat");
  while(infile>>terminal>>day>>kWh){
    for(i=0;i<sizeof(res.terminal)/sizeof(res.terminal[0]);i++){
      for(j=0;j<sizeof(res.day)/sizeof(res.day[0]);j++){
        if(terminal==res.terminal[i]&&!day.compare(res.day[j])){
          res.kWh[i][j]+=kWh;
        }
      }
    }
  }
  infile.close();
  return res;
}

void printChart(results res,int i, int j){
  for(i=0;i<7;i++){
    cout<<"\t"<<res.day[i];
  }
  cout<<endl;
  for(i=0;i<sizeof(res.terminal)/sizeof(res.terminal[0]);i++){
    cout<<res.terminal[i]<<"\t";
    for(j=0;j<sizeof(res.day)/sizeof(res.day[0]);j++){
      cout<<res.kWh[i][j]<<"kWh\t";
    }
    cout<<endl;
  }
}

int main(void){
  int i,j;
  results res = buildResults(i, j);
  printChart(res, i, j);
  return 0;
}
