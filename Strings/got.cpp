/*
Dothraki are planning an attack to usurp King Robert's throne. King Robert learns of this conspiracy from Raven and plans to lock the single door through which the enemy can enter his kingdom.

door

But, to lock the door he needs a key that is an anagram of a certain palindrome string.

The king has a string composed of lowercase English letters. Help him figure out whether any anagram of the string can be a palindrome or not.

Input Format 
A single line which contains the input string.

Constraints 
1≤1≤ length of string ≤105≤105 
Each character of the string is a lowercase English letter.

Output Format 
A single line which contains YES or NO in uppercase.

Sample Input : 01

aaabbbb
Sample Output : 01

YES
Explanation 
A palindrome permutation of the given string is bbaaabb. 

Sample Input : 02

cdefghmnopqrstuvw
Sample Output : 02

NO
Explanation 
You can verify that the given string has no palindrome permutation. 

Sample Input : 03

cdcdcdcdeeeef
Sample Output : 03

YES
Explanation 
A palindrome permutation of the given string is ddcceefeeccdd.
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {
    int c=0;
    
    string s;
    cin>>s;
  //cout<<s.size();
    
    sort(s.begin(),s.end());
   
    bool eo=false;
    bool flip=false;
    if((s.size())%2==0)
        eo=true;
    
    for(int i=97;i<123;i++)
    {
        int count=0;
        while(s[c]==(char)i && c<s.size())
        {
            count++;
            c++;
        }
       // cout<<count<<" ";
        if(eo==true && count%2==1)
            {
            cout<<"NO";
            break;
            }  
        else if(eo == false && count%2==1 && flip==true)
        {
            cout<<"NO";
            break;
        }
        else if(eo == false && count%2==1 && flip!=true)
        {
            flip=true;
        }
        else if(i==122)
        {
            cout<<"YES";
            break;
        }
         
      }
    
  //  int flag = 0;
    // Assign Flag a value of 0 or 1 depending on whether or not you find what you are looking for, in the given string 
  //  if(flag==0)
  //      cout<<"NO";
 //   else
//cout<<"YES";
    return 0;
}
