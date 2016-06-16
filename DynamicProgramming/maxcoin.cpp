/*
There are N coins (Assume N is even) in a line. Two players take turns to take a coin from one of the ends of the line until there are no more coins left. The player with the larger amount of money wins. Assume that you go first.

Write a program which computes the maximum amount of money you can win.

Example:

suppose that there are 4 coins which have value
1 2 3 4
now you are first so you pick 4
then in next term
next person picks 3 then
you pick 2 and
then next person picks 1
so total of your money is 4 + 2 = 6
next/opposite person will get 1 + 3 = 4
so maximum amount of value you can get is 6
*/
int max(int a, int b)
{
    return (a>b) ? a : b;
}
int min(int a, int b)
{
    return (a<b) ? a : b;
}

int Solution::maxcoin(vector<int> &A) 
{
  vector<vector<int>> P (A.size()+10,(vector<int>(A.size()+10,0)));
 // int P[A.size()+10][A.size()+10];
  int a, b, c;
  int k = 0;
  while(k++<A.size())
  {
    for(int m = 0, n = k; n < A.size(); m++,n++)
    {
      assert(m < A.size());
      assert(n < A.size());
      a = ((m+2 <= A.size()-1)             ? P[m+2][n] : 0);
      b = ((m+1 <= A.size()-1 && n-1 >= 0) ? P[m+1][n-1] : 0);
      c = ((n-2 >= 0)               ? P[m][n-2] : 0);
      P[m][n] = max(A[m] + min(a,b), A[n] + min(b,c));
    }
  }
  
  
  return P[0][A.size()-1];
}
