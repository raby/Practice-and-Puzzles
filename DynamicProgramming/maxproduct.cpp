/*
Find the contiguous subarray within an array (containing at least one number) which has the largest product.
Return an integer corresponding to the maximum product possible.

Example :

Input : [2, 3, -2, 4]
Return : 6 

Possible with [2, 3]
*/
int min(int a, int b)
{
    return (a<b) ? a : b;
}
int max(int a, int b)
{
    return (a>b) ? a : b;
}

int Solution::maxProduct(const vector<int> &A) 
{
    if(A.size()==0)  
        return 0;  
 
    int maxLocal = A[0];  
    int minLocal = A[0];  
    int global = A[0];  
 
    for(int i=1; i<A.size(); i++)
    {  
        int temp = maxLocal;  
        maxLocal = max(max(A[i]*maxLocal, A[i]), A[i]*minLocal);  
        minLocal = min(min(A[i]*temp, A[i]), A[i]*minLocal);  
        global = max(global, maxLocal);  
    }  
    return global;
}
