/*
Given two integers n and k, return all possible combinations of k numbers out of 1 2 3 ... n.

Make sure the combinations are sorted.

To elaborate,
1. Within every entry, elements should be sorted. [1, 4] is a valid entry while [4, 1] is not.
2. Entries should be sorted within themselves.

Example :
If n = 4 and k = 2, a solution is:

[
  [1,2],
  [1,3],
  [1,4],
  [2,3],
  [2,4],
  [3,4],
]
 Warning : DO NOT USE LIBRARY FUNCTION FOR GENERATING COMBINATIONS.
Example : itertools.combinations in python.
If you do, we will disqualify your submission retroactively and give you penalty points. 
*/
vector<int> combo;
vector<vector<int>> ans;

void comb(int N, int K)
{
    std::string bitmask(K, 1); // K leading 1's
    bitmask.resize(N, 0); // N-K trailing 0's

    // print integers and permute bitmask
    do {
        for (int i = 0; i < N; ++i) // [0..N-1] integers
        {
            if (bitmask[i]) 
                combo.push_back(i+1);
        }
        ans.push_back(combo);
        combo.clear();       
    } while (std::prev_permutation(bitmask.begin(), bitmask.end()));
}


vector<vector<int> > Solution::combine(int n, int k) {
    ans.clear();
    if(k<=n)
        comb(n,k);
    else if(k==n)
    {
        for(int i=0;i<n;i++)
            combo.push_back(i+1);
        ans.push_back(combo);
    }
        
    return ans;
}
