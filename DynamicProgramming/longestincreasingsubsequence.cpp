#include "printtable.h"

int solution(const vector<int> val) {
  vector<vector<int> > table(val.size()+1,vector<int>(val.size()+1,0));
  for(int i=1; i<=val.size(); i++) {
    for(int j=1; j<=val.size(); j++) {
      if(val[i-1] < val[j-1] && j>i) {
        table[i][j] = max(table[i][j-1],table[i-1][j] + 1);
      }
      else
        table[i][j] = table[i][j-1];
    }
  }
  printTable(table);

  return table[val.size()][val.size()];
}

int main() {

  vector<int> val;
  val.push_back(0);
  val.push_back(8);
  val.push_back(4);
  val.push_back(12);
  val.push_back(2);
  val.push_back(10);
  val.push_back(6);
  val.push_back(14);
  val.push_back(1);
  val.push_back(9);
  val.push_back(5);
  val.push_back(13);
  val.push_back(3);
  val.push_back(11);
  val.push_back(7);
  val.push_back(15);

  int ans = solution(val);
  return 0;
}
