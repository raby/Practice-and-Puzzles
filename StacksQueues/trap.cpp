/*

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

Example :

Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.



The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
In this case, 6 units of rain water (blue section) are being trapped.

*/

int max(int a, int b)
{
    return a>b ? a : b;
}

int min(int a, int b)
{
    return a<b ? a : b;
}

int Solution::trap(const vector<int> &A) 
{
    int l[A.size()];
    int r[A.size()];
    int water = 0;
    
    l[0] = A[0];
    for(int i=1;i<A.size();i++)
        l[i] = max(l[i-1],A[i]);
        
    r[A.size()-1] = A[A.size()-1];
    for(int i=A.size()-2;i>=0;i--)
        r[i] = max(r[i+1],A[i]);
    
    for(int i = 0 ; i<A.size();i++)
        water += min(l[i],r[i]) - A[i];
        
    return water;
}
