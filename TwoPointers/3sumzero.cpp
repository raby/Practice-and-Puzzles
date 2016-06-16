/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
Find all unique triplets in the array which gives the sum of zero.

Note:

 Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets. For example, given array S = {-1 0 1 2 -1 -4}, A solution set is:
(-1, 0, 1)
(-1, -1, 2) 
*/

#include<set>

vector<vector<int> > Solution::threeSum(vector<int> &A) {
    vector<vector<int>> sol;
    set<vector<int>> dup;
    vector<int> tri(3);
    sort(A.begin(),A.end());
    int i,j,k;
    
    for(i = 0 ; i<A.size() ;i++)
    {
        k = A.size()-1;
        j = i+1;
        while(j<k)
        {
            if( (A[i]+A[j]+A[k] ) == 0 )
            {
                tri[0] = A[i];
                tri[1] = A[j];
                tri[2] = A[k];
                dup.insert(tri);
            }
            ( (A[i]+A[j]+A[k]) < 0 ) ? j++ : k--;
        }
    }
    for(set<vector<int>>::iterator it = dup.begin();it!=dup.end();++it)
        sol.push_back(*it);   
    
    return sol;
    
}
