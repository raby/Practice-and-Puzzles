/*
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

 Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The combinations themselves must be sorted in ascending order.
CombinationA > CombinationB iff (a1 > b1) OR (a1 = b1 AND a2 > b2) OR … (a1 = b1 AND a2 = b2 AND … ai = bi AND ai+1 > bi+1)
The solution set must not contain duplicate combinations.
Example, 
Given candidate set 2,3,6,7 and target 7,
A solution set is:

[2, 2, 3]
[7]
 Warning : DO NOT USE LIBRARY FUNCTION FOR GENERATING COMBINATIONS.
Example : itertools.combinations in python.
If you do, we will disqualify your submission retroactively and give you penalty points. 
*/
set<vector<int>>ans;

void help(vector<int> A, int B, int j,vector<int> sol)
{
    if(B == 0)
    {
        ans.insert(sol);
        return;
    }
    for(int i = j; i<A.size();i++)
    {
        if(B < A[i])
            return;
        
        sol.push_back(A[i]);
        help(A,B-A[i],i,sol);
        sol.pop_back();
    }
}



vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) 
{
    sort(A.begin(),A.end());
    for (int i = 0; i < A.size()-1; i++) 
	{
		if (A[i] == A[i + 1])
			A.erase(A.begin() + i, A.begin() + i + 1);
	}
    vector<int> sol;
    sol.clear();
    ans.clear();
    help(A,B,0,sol);
    vector<vector<int>> rans;
	set<vector<int>>::iterator it = ans.begin();
	for (it; it != ans.end(); it++)
		rans.push_back(*it);

    return rans;
}
