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
