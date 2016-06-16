/*
Given two strings aa and bb of equal length, what's the longest string (SS) that can be constructed such that it is a child of both? 

A string xx is said to be a child of a string yy if xx can be formed by deleting 0 or more characters from yy. 

For example, ABCD and ABDC has two children with maximum length 3, ABC and ABD. Note that we will not consider ABCD as a common child because C doesn't occur before D in the second string.

Input format

Two strings, aa and bb, with a newline separating them.

Constraints

All characters are upper cased and lie between ASCII values 65-90. The maximum length of the strings is 5000.

Output format

Length of string SS.

Sample Input #0

HARRY
SALLY
Sample Output #0

2
The longest possible subset of characters that is possible by deleting zero or more characters from HARRY and SALLY is AY, whose length is 2.

Sample Input #1

AA
BB
Sample Output #1

0
AA and BB has no characters in common and hence the output is 0.

Sample Input #2

SHINCHAN
NOHARAAA
Sample Output #2

3
The largest set of characters, in order, between SHINCHAN and NOHARAAA is NHA.

Sample Input #3

ABCDEF
FBDAMN
Sample Output #3

2
BD is the longest child of these strings.
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int max(int a, int b)
{
    return (a>b) ? a:b;
}

int lcs( string x, string y, int m, int n)
{
    vector<vector<int>> L(m+1,vector<int> (n+1));
   int i , j;

   for(i=0;i<=m;i++)
   {
       for(j=0;j<=n;j++)
       {
           if(i==0 || j ==0)
               L[i][j] = 0;
           else if (x[i-1]==y[j-1])
               L[i][j] = L[i-1][j-1] + 1;
           else
               L[i][j] = max(L[i-1][j], L[i][j-1]);
       }      
   }       
    return L[m][n];
}
 


int main() {
    string s1,s2;
    cin>>s1>>s2;
    
    int m = s1.size();
    int n = s2.size();
    
    cout<<lcs(s1,s2,m,n);
    
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
