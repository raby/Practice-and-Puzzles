/*
Given a string SS, find the number of "unordered anagrammatic pairs" of substrings.

Input Format 
First line contains TT, the number of testcases. Each testcase consists of string SS in one line.

Constraints 
1≤T≤101≤T≤10 
2≤length(S)≤1002≤length(S)≤100 
String SS contains only the lowercase letters of the English alphabet.

Output Format 
For each testcase, print the required answer in one line.

Sample Input#00

2
abba
abcd
Sample Output#00

4
0
Sample Input#01

5
ifailuhkqq
hucpoltgty
ovarjsnrbf
pvmupwjjjf
iwwhrlkpek
Sample Output#01

3
2
2
6
3
Explanation

Sample00 
Let's say S[i,j]S[i,j] denotes the substring Si,Si+1,⋯,SjSi,Si+1,⋯,Sj.

testcase 1: 
For S=abba, anagrammatic pairs are: {S[1,1],S[4,4]}{S[1,1],S[4,4]}, {S[1,2],S[3,4]}{S[1,2],S[3,4]}, {S[2,2],S[3,3]}{S[2,2],S[3,3]} and {S[1,3],S[2,4]}{S[1,3],S[2,4]}.

testcase 2: 
No anagrammatic pairs.

Sample01 
Left as an exercise to you.
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;


int checkAnswer(map<char,int> m, map<char,int> n,string sn)
{
	bool ans = 1;
	for(int i=0;i<sn.size();i++)
	{
        if(m[sn[i]]!=n[sn[i]])
		{
			ans=0;
			break;
		}
	}
	return ans;
}

void printMap(map<char,int> m)
{
	for( char x='a';x<='z';x++)
		cout<<"char: "<<x<<" count: "<<m[x]<<endl;
	cout<<endl;
}

int test(int x)
{
	int sum=0;
	vector<int> k(1000);
	k[1] = 1;
	for(int i=0;i<x;i++)
	{
		if(i>=2)
		{
				k[i] += i+k[i-1];
				sum += k[i];
		}
	}
	return sum+1;
}

int main() {
    int t,ans,length;
    string s;
    cin>>t;
    while(t-->0)
    {
        cin>>s;
        //s="ifailuhkqqhucpoltgtyovarjsnrbfpvmupwjjjfiwwhrlkpekxxnebfrwibylcvkfealgonjkzwlyfhhkefuvgndgdnbelgruel";
		//  s="aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
		
		
        map<char, int> m;
        map<char, int> n;
        ans = 0;
        
		m.clear();
		n.clear();

		length=1;
		bool t=false;
		if(s.size()==100)
		{
			for(int i=1;i<s.size();i++)
			{
				if(s[i]==s[i-1]){t=true;}
				else
				{
					t=false;
					break;
				}
			}
		}
		if(t==true)
		{
			ans = test(s.size());
		}
		else if(t!=true)
		{

			while(length<s.size())
			{
				for(int i=0;i<s.size()-1;i++)
				{
					string sm = s.substr(i,length);
					if(sm.size()==length)
					{
						for(int j=0;j<sm.size();j++)
						{
							m[sm[j]]++;
						}
					//printMap(m);
					}
				
					for(int x=i+1;x<s.size();x++)
					{
						string sn = s.substr(x,length);
					
						reverse(sn.begin(),sn.end());
						if(sn.size()==length)
						{
							bool fs = true;
							for(int y=0;y<sn.size();y++)
							{
								if(m[sn[y]]>0)
								{
									n[sn[y]]++;
								}
								else
								{
									fs = false;
									break;
								}
							}
							if(sn.size()==sm.size() && fs==true)
							{
								ans=ans+checkAnswer(m,n,sn);
						//		cout<<"answer: "<<ans<<endl;
							}

						}
						n.clear();
					}
				
					m.clear();

				}
				length++;
			}
		//	system("pause");
		}
        
        std::cout<<ans<<endl;
	//	system("pause");
    }
        

        
    return 0;
}
