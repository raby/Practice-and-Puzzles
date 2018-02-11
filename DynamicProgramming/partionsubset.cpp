#include "printtable.h"

using namespace std;

bool partionSubset(const int set[], const int& size) {
  int sum = 0;
  for(int i=0; i<size; i++)
    sum += set[i];

  if(sum%2!=0)
    return false;

  sum = sum/2;
  vector<vector<int> > table(size+1,vector<int>(sum+1,0));
  for(int i=0; i<=size; i++)
    table[i][0] = 1;

  for(int i=1; i<=size; i++) {
    for(int j=1; j<=sum; j++) {
      if(set[i-1]<=j)
        table[i][j] = table[i-1][j-set[i-1]] || table[i-1][j];
      else
         table[i][j] = table[i-1][j];
    }
  }
  printTable(table);
  return table[size][sum];
}

int main () {

  int set[] = {3, 1, 1, 2, 2, 1};
  int size = sizeof(set)/sizeof(set[0]);
  int ans = partionSubset(set,size);
  cout<<"The solution is: "<<ans<<endl;
  return 0;
}
