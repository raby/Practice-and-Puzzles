/*
Alice recently started learning about cryptography and found that anagrams are very useful. Two strings are anagrams of each other if they have same character set (and frequency of characters) and same length. For example strings "bacdc" and "dcbac" are anagrams, while strings "bacdc" and "dcbad" are not.

Alice decides on an encryption scheme involving 2 large strings where encryption is dependent on the minimum number of character deletions required to make the two strings anagrams. She need your help in finding out this number.

Given two strings (they can be of same or different length) help her in finding out the minimum number of character deletions required to make two strings anagrams. Any characters can be deleted from any of the strings.

Input Format 
Two lines each containing a string.

Constraints 
1 <= Length of A,B <= 10000 
A and B will only consist of lowercase latin letter.

Output Format 
A single integer which is the number of character deletions.

Sample Input #00:

cde
abc
Sample Output #00:

4
Explanation #00: 
We need to delete 4 characters to make both strings anagram i.e. 'd' and 'e' from first string and 'b' and 'a' from second string.
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>


using namespace std;

int anaGram(string a, string b){
	map<char,pair<int,int>> m;
	int count=0;

	//set map for all lower case letters
	for(char a='a'; a<'z';a++){
	m[a].first = 0;
	m[a].second = 0;
	}

	for(int i=0;i<a.size();i++){
			m[a[i]].first++; 
	}
	for(int i=0;i<b.size();i++){
			m[b[i]].second++; 
	}
	for(char a = 'a'; a<='z'; a++){
		count += abs(m[a].first - m[a].second);
	}
	return count;
}

int main() {
   string a,b;
    cin>>a;
    cin>>b;
    cout<<anaGram(a,b);
    
    return 0;
}
