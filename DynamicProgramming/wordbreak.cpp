#include "printtable.h"
#include <string>


struct dictionary {
  private:
    vector<string> dic;
    int i;
  public:
    dictionary() {
      dic.push_back("i");
      dic.push_back("like");
      dic.push_back("sam");
      dic.push_back("sung");
      dic.push_back("samsung");
      dic.push_back("mobile");
      dic.push_back("ice");
      dic.push_back("cream");
      dic.push_back("icecream");
      dic.push_back("man");
      dic.push_back("go");
      dic.push_back("mango");
      i = 0;
    }
    string next() {
      if(i<dic.size())
        return dic[i++];
      else
        reset();
      return "-1";
    }
    string prev() {
      return dic[i--];
    }
    void reset() {
      i = 0;
    }
};

bool check(const string& A, dictionary D) {
  string s = "";
  while(s != "-1") {
    s = D.next();
    if(s.size() == A.size()) {
      for(int i=0; i<A.size();i++) {
        if(A[i] != s[i])
          return 0;
      }
      return 1;
    }
  }
  return 0;
}

bool wordbreak(const string& A) {
  dictionary D;
  vector<bool> table(A.size()+1,0);

  for(int i=1;i<=A.size();i++) {
    if(table[i] == 0) {
       string a = A.substr(0,i);
       table[i] = check(a,D);
    }
    if(table[i] == 1) {
      for(int j = i+1;j<=A.size();j++) {
        if(table[A.size()] == 1)
          return 1;
        string a = A.substr(i,j-i);
        table[j] = check(a,D);
      }
    }
    if(i == A.size() && table[i] == 1) {
       return 1;
    }
  }
  return 0;
}


int main() {

  string A = "likeidsamsung";
  bool ans = wordbreak(A);
  cout<<"The answer is "<<ans<<endl;

  return 0;
}
