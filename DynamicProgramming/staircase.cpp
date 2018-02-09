#include <iostream>
#include <vector>

using namespace std;

int stairs(int n) {

  vector<int> table(n,0);
  table[0] = 1;
  table[1] = 1;
  for(int i=2;i<=n;i++) {
    table[i] = table[i-1] + table[i-2];
  }

  return table[n];

}

int main() {

  int n = 4;
  int ans = stairs(n);
  cout<<"The solution is: "<<ans<<endl;
  return 0;
}
