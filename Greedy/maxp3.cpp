/*
Given an array of integers, return the highest product possible by multiplying 3 numbers from the array

Input:

array of integers e.g {1, 2, 3}
 NOTE: Solution will fit in a 32-bit signed integer 
Example:

[0, -1, 3, 100, 70, 50]

=> 70*50*100 = 350000
*/
int Solution::maxp3(vector<int> &A) 
{
    sort(A.begin(),A.end());
    int t = A[A.size()-1]*A[A.size()-2]*A[A.size()-3];
    int b = A[1]*A[0]*A[A.size()-1];
    int c = INT_MIN;
    for(int i=0;i<A.size();i++)
    {
        if(A[i]==0)
        {
            c = 0;
            break;
        }
    }
    int ans;
    if(t>b)
    {
        if(t>c)
            ans = t;
        else
            ans = c;
    }
    else
    {
        if(b>c)
            ans = b;
        else
            ans = c;
    }
    return ans;
}
