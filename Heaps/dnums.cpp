/*
You are given an array of N integers, A1, A2 ,…, AN and an integer K. Return the of count of distinct numbers in all windows of size K.

Formally, return an array of size N-K+1 where i’th element in this array contains number of distinct elements in sequence Ai, Ai+1 ,…, Ai+k-1.

Note:
- If K > N, return empty array.

For example,

A=[1, 2, 1, 3, 4, 3] and K = 3

All windows of size K are

[1, 2, 1]
[2, 1, 3]
[1, 3, 4]
[3, 4, 3]

So, we return an array [2, 3, 3, 2].
See Expected Output
*/

vector<int> Solution::dNums(vector<int> &A, int B) {
    vector<int> ans;
    map<int,int> m;
    m.clear();
    ans.clear();
    if(B>A.size())
        return ans;
	for(int i=0;i<B;i++)
		m[A[i]]++;
	ans.push_back(m.size());
	int j=0;
    for(int i=B;i<A.size();i++)
    {
            m[A[j]]--;
			if(m[A[j]]==0)
				m.erase(A[j]);
			j++;
			m[A[i]]++;
			ans.push_back(m.size());
	}
    m.clear();
    return ans;
}