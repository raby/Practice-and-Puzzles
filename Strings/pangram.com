/*
Roy wanted to increase his typing speed for programming contests. So, his friend advised him to type the sentence "The quick brown fox jumps over the lazy dog" repeatedly, because it is a pangram. (Pangrams are sentences constructed by using every letter of the alphabet at least once.)

After typing the sentence several times, Roy became bored with it. So he started to look for other pangrams.

Given a sentence ss, tell Roy if it is a pangram or not.

Input Format

Input consists of a string ss.

Constraints 
Length of ss can be at most 103103 (1≤|s|≤103)(1≤|s|≤103) and it may contain spaces, lower case and upper case letters. Lower-case and upper-case instances of a letter are considered the same.

Output Format

Output a line containing pangram if ss is a pangram, otherwise output not pangram.

Sample Input

Input #1

We promptly judged antique ivory buckles for the next prize    
Input #2

We promptly judged antique ivory buckles for the prize    
Sample Output

Output #1

pangram
Output #2

not pangram
Explanation

In the first test case, the answer is pangram because the sentence contains all the letters of the English alphabet.
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    map<char,int> a;

    char s[10000]; 
    int length=0;
    int count =0;
    
    fgets(s, 9999, stdin);
    for(int i=0;i<9999;i++)
    {
        if(s[i]!='\0')
        {
            s[i] = tolower(s[i]);
            length++;
        }
        else break;
    }
    
    if(length<26)
        cout<<"not pangram";
    else
    {
        for(int i=0;i<length;i++)
        {
            a[s[i]]++;
            if(a[s[i]]==1)
                count++;
        }   
        if(count>26)
            cout<<"pangram";
        else
            cout<<"not pangram";
    }

    return 0;
}
