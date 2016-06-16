/*
John has discovered various rocks. Each rock is composed of various elements, and each element is represented by a lower-case Latin letter from 'a' to 'z'. An element can be present multiple times in a rock. An element is called a gem-element if it occurs at least once in each of the rocks.

Given the list of NN rocks with their compositions, display the number of gem-elements that exist in those rocks.

Input Format

The first line consists of an integer, NN, the number of rocks. 
Each of the next NN lines contains a rock's composition. Each composition consists of lower-case letters of English alphabet.

Constraints 
1≤N≤1001≤N≤100 
Each composition consists of only lower-case Latin letters ('a'-'z'). 
1≤1≤ length of each composition ≤100≤100
Output Format

Print the number of gem-elements that are common in these rocks. If there are none, print 0.

Sample Input

3
abcdde
baccd
eeabg
Sample Output

2
Explanation

Only "a" and "b" are the two kinds of gem-elements, since these are the only characters that occur in every rock's composition.
*/


#include <cmath>
#include <cstdio>
#include <map>
#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bitset>

using namespace std;


int main() {
    string y;
    int gems=0;
    int num_of_rocks=0;
    vector<string> the_rocks;
    map<char,pair<int,int>> count_the_rocks;
    
    
    cin>>num_of_rocks;
	
    for(int i= 0; i <num_of_rocks; i++){
	
        cin>>y;
	
        the_rocks.push_back(y);	
		}
	
   	for(char a = 'a'; a<='z';a++){
    count_the_rocks[a].first=0;   
    count_the_rocks[a].second=0;
    }
	
	
	for(int i=0; i<the_rocks.size(); i++){
        for(int j = 0;j<the_rocks[i].length();j++){
            if(count_the_rocks[the_rocks[i][j]].second==0){
               
                count_the_rocks[the_rocks[i][j]].first++; 
                count_the_rocks[the_rocks[i][j]].second=-1;   
            
            
            
            }
            
        }
       for(char a = 'a'; a<='z';a++){
            count_the_rocks[a].second=0;
        }
    }   
    for(char a = 'a'; a<='z';a++){
		if(count_the_rocks[a].first==num_of_rocks){
			        gems++;
         }
	}
    
    cout<<gems<<endl;
    
    return 0;
}