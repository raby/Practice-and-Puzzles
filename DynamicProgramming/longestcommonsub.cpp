#include <string>
#include <vector>
#include <iostream>

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

int LCS(string A, string B) {
  int x = A.length();
  int y = B.length();
  vector< vector<int > > table(x+1,vector<int>(y+1,0));

  for(int i=1;i<=x;i++) {
    for(int j=1;j<=y;j++) {
      int c;
      (A[i-1] == B[j-1]) ? c = 1 : c = 0;
      table[i][j] = max(table[i][j-1] + c,table[i-1][j]);
    }
  }
  printTable(table);
  return table[x][y];
}

int main() {

  //string A = "AGGTAB";
  //string B = "GXTXAYB";

  string A = "ABCDGH";
  string B = "AEDFHR";

  int ans = LCS(A,B);
  cout<<"The longest common subsequence: "<<ans<<endl;

  return 0;

}
