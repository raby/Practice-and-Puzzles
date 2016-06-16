/*
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

 Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
Example :

Given candidate set 10,1,2,7,6,1,5 and target 8,

A solution set is:

[1, 7]
[1, 2, 5]
[2, 6]
[1, 1, 6]
 Warning : DO NOT USE LIBRARY FUNCTION FOR GENERATING COMBINATIONS.
Example : itertools.combinations in python.
If you do, we will disqualify your submission retroactively and give you penalty points. 
*/

set<vector<int>> ans;
vector<int> sol;

void allComb(vector<int> A, vector<int> sol, int B, int v, int i)
{
	while (i<A.size())
	{
		sol.push_back(A[i++]);
		v += sol[sol.size() - 1];
		if (v == B)
			ans.insert(sol);
		if (sol.size() <= A.size() && v < B )
			allComb(A,sol,B,v,i);
		v -= sol[sol.size() - 1];
		sol.pop_back();
	}
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) 
{
    ans.clear();
    sol.clear();
    sort(A.begin(),A.end());
    allComb(A, sol, B, 0, 0);
    set<vector<int>>::iterator it = ans.begin();
    vector<vector<int>>ta;
    for(it;it!=ans.end();it++)
        ta.push_back(*it);
    return ta;
}
