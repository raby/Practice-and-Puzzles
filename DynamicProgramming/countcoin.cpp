#include <iostream>
#include <vector>

using namespace std;

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

int count(int n) {
  int m = 3;
  vector<int> S (m);
  S[0] = 1;
  S[1] = 2;
  S[2] = 5;

  int i, j, x, y;
  vector<vector<int> > table(n+1,vector<int>(m,0));
  for (i=0; i<m; i++)
    table[0][i] = 1;
  for (i = 1; i < n+1; i++) {
    for (j = 0; j < m; j++) {
      x = (S[j] <= i) ? table[i - S[j]][j] : 0;
      y = (j >= 1) ? table[i][j-1] : 0;
      table[i][j] = x + y;
    }
  }
  printTable(table);
  return table[n][m-1];
}


int main() {
  int n = 10;
  int ans = count(n);
  cout<<"The solution is: "<<ans<<endl;
}
