/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return 1 ( true ).

A = [3,2,1,0,4], return 0 ( false ).

Return 0/1 for this problem
*/
int max(int a, int b)
{
    return (a>b) ? a : b;
}

int Solution::canJump(vector<int> &A) 
{
    if(A.size()<=1)
        return 1;
    int d=A[0];
    for(int i=1;i<A.size();i++)
    {
        if(d>=i)
            d = max(A[i]+i,d);
        else 
            return 0;
    } 
    return 1;
}
