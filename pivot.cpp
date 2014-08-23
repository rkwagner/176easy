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

struct table{
  int terminal;
  string day;
  int kWh;
};

struct results{
  int terminal[10];
  string day[7];
  int kWh[10][7];
};

int main(void){
  ifstream infile;
  infile.open("windfarm.dat");
  table farm[1000];
  int i=0,j,k;
  results res={
    {1000,1001,1002,1003,1004,1005,1006,1007,1008,1009},
  {"Mon","Tue","Wed","Thu","Fri","Sat","Sun"},
  0
  };
  while(infile>>farm[i].terminal>>farm[i].day>>farm[i].kWh){
    for(j=0;j<10;j++){
      for(k=0;k<7;k++){
        if(farm[i].terminal==res.terminal[j]&&
            !(farm[i].day).compare(res.day[k])){
          res.kWh[j][k]+=farm[i].kWh;
        }
      }
    }
    i++;
  }
  for(i=0;i<7;i++){
    cout<<"\t"<<res.day[i];
  }
  cout<<endl;
  for(i=0;i<10;i++){
    cout<<res.terminal[i]<<"\t";
    for(j=0;j<7;j++){
      cout<<res.kWh[i][j]<<"kWh\t";
    }
    cout<<endl;
  }
  infile.close();
  return 0;
}
