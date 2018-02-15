#include "printtable.h"
#include <string>

using namespace std;

int max(const int& a, const int& b) {
  return (a > b) ? a : b;
}

int editdistance(const string& A, const string& B) {

  vector<vector<int> > table(A.size()+1,vector<int> (B.size()+1,0));

  for(int i=1;i<=A.size();i++) {
    for(int j=1;j<=B.size();j++) {
      int c;
      (A[i-1] == B[j-1]) ? c = 1 : c = 0;
      table[i][j] = max(table[i-1][j] + c, table[i][j-1]);
    }
  }

  printTable(table);
  return table[A.size()][B.size()];
}

int main() {

  //string A = "saturday";
  //string B = "sunday";

  //string A = "catg";
  //string B = "doggg";

  //string A = "geek";
  //string B = "gesek";

  //string A = "Andrew";
  //string B = "Amdrewz";

  string A = "jewels";
  string B = "mogwai";

  int ans = editdistance(A,B);
  int l = max(A.size(),B.size());
  cout<<"The solution is: "<<l-ans<<endl;

  return 0;
}
