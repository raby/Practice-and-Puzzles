/*
Given a collection of integers that might contain duplicates, S, return all possible subsets.

 Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
The subsets must be sorted lexicographically.
Example :
If S = [1,2,2], the solution is:

[
[],
[1],
[1,2],
[1,2,2],
[2],
[2, 2]
]
*/
set<vector<int> > ans;
vector<int> sol;

void help(const vector<int> &A, vector<int> sol,int i)
{
    while(i<A.size())
    {
        sol.push_back(A[i]);
        ans.insert(sol);
        help(A,sol,(i+1));
        sol.pop_back();
        i++;
    }
}

vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) 
{
    sort(A.begin(),A.end());
    ans.clear();
    sol.clear();
    ans.insert(sol);
    help(A,sol,0);
    set<vector<int>>::iterator it = ans.begin();
    vector<vector<int>> rans;
    for(it;it!=ans.end();it++)
        rans.push_back(*it);
    
    return rans;
}
