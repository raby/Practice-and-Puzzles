#include <iostream>
#include <vector>

using namespace std;

int max(int a, int b) {
 return (a > b) ? a : b;
}

void printTable(vector< vector< int> > table) {
  cout<<"["<<endl;
  for(int i=0;i<table.size();i++) {
    cout<<"[ ";
    for(int j=0;j<(table[i].size()-1);j++) {
        cout<<table[i][j]<<", ";
     }
     cout<< table[i][(table[i].size()-1)]<<" ]"<<endl;
  }
  cout<<"]"<<endl;
}

int knapsack(int W,int* value,int* weight,int s) {

  vector<vector<int> >table(s+1,vector<int>(W+1,0));

  for(int i=0;i<=s;i++) {
    for(int j=0;j<=W;j++) {
      if(i == 0 || j == 0) {
        table[i][j] = 0;
      }
      else if(weight[i-1] <= j) {
         table[i][j] = max( (value[i-1] + table[i-1][j - weight[i-1]]) , table[i-1][j] );
      }
      else {
         table[i][j] = table[i-1][j];
      }
    }
  }

  printTable(table);
  return table[s][W];

}

int main() {

  int W = 13;
  int value[] = {5,15,21,30};
  int weight[] = {3,4,8,10};
  int s = (sizeof(value)/sizeof(value[0]));

  int sol = knapsack(W,value,weight,s);

  cout<<"The solution is: "<<sol<<endl;

  return 0;
}
