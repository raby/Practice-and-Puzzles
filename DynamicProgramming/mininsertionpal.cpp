#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

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

int solution(string A) {
  vector<vector<int> > table(A.size()+1,vector<int> (A.size()+1,0));
  string B = A;
  reverse(B.begin(),B.end());

  for(int i=1;i<=A.size();i++) {
     for(int j=1;j<=A.size();j++) {
         int c;
         (A[i-1] == B[j-1]) ? c = 1 : c = 0;
         table[i][j] = max(table[i][j-1] + c, table[i-1][j]);
     }
  }

  printTable(table);
  return table[A.size()][A.size()];
}

int main() {

  string A = "abcda";
  int S = solution(A);
  cout<< "Solution: "<<A.size()-S<<endl;
  return 0;
}
