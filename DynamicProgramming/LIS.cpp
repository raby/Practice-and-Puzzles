#include <iostream>
#include <vector>

using namespace std;

int max(int a, int b) {
  return (a > b) ? a : b;
}

void printTable(vector< vector<int> > table) {
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

int LIS( vector<int> input) {

  for(int i=0;i<input.size();i++) {
    cout<<input[i]<<" ";
  }

  vector< vector<int> > table(input.size()+1, vector<int>(input.size()+1,0));

  for(int i=1;i<=input.size();i++) {
    int min = input[i-1];
    for(int j=i;j<=input.size();j++) {
      int c;
      if(min <= input[j-1]) {
        c = 1;
        min = input[j-1];
      }
      else {
        c = 0;
      }
      table[i][j] = max(table[i][j-1] + c, table[i-1][j]);
    }
  }
  printTable(table);

  return table[input.size()][input.size()];
}

int main() {
  vector<int> input;
  /*input.push_back(3);
  input.push_back(10);
  input.push_back(2);
  input.push_back(1);
  input.push_back(20);
  */
  /*
  //{50, 3, 10, 7, 40, 80}
  input.push_back(50);
  input.push_back(3);
  input.push_back(10);
  input.push_back(7);
  input.push_back(40);
  input.push_back(80);
  */
  // {10, 22, 9, 33, 21, 50, 41, 60, 80}
  input.push_back(10);
  input.push_back(22);
  input.push_back(9);
  input.push_back(33);
  input.push_back(21);
  input.push_back(50);
  input.push_back(41);
  input.push_back(60);
  input.push_back(80);
  int ans = LIS(input);
  cout<<"The solution is: "<<ans<<endl;
  return 0;
}
