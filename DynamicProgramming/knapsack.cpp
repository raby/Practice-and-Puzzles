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
//allow inclusion once
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

  cout<<endl;
  printTable(table);
  return table[s][W];

}

int knapsack_multi(const int& W, const int* value, const int* weight, const int& s) {

  vector<vector<int> >table(s+1,vector<int>(W+1,0));
  for(int i = 1; i<=W;i++) {
     for(int j = 1; j<=s;j++) {
       if(weight[j-1] <= i)
          table[j][i] = max( (value[j-1] + table[j-1][i-weight[j-1]]), table[j-1][i] );
       else
          table[j][i] = table[j-1][i];
     }
  }

  cout<<endl;
  printTable(table);
  return table[s][W];

}

int main() {

  int W = 9;
  int value[] = {5,8,7,15};
  int weight[] = {1,2,3,5};
  int s = (sizeof(value)/sizeof(value[0]));

  int sol = knapsack(W,value,weight,s);
  int sol_multi = knapsack_multi(W,value,weight,s);

  cout<<"The solution is: "<<sol<<endl;
  cout<<"The inclusive solution is: "<<sol_multi<<endl;
  return 0;
}
