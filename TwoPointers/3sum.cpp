/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. 
Return the sum of the three integers. 
You may assume that each input would have exactly one solution.

Example: 
given array S = {-1 2 1 -4}, 
and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2)
*/

int Solution::threeSumClosest(vector<int> &A, int B) {
    
    sort(A.begin(),A.end());
    int lb = 0;
    int i = 1;
    int j = A.size()-1;
    int ub = j;
    int target = B - (A[lb]+A[i]);
    int best = A[j] - target;
    
    while(ub-lb >= 2)
    {
        int val = A[j];
        
        if(val == target)
            return B;
            
        if(abs(best)>abs(val-target))
            best = val - target;
            
        if(i+1 == j)
        {
            lb++;
            i=lb+1;
            j=ub;
            target = B-(A[lb]+A[i]);
        }
        else if(val < target )
        {
            i++;
            target = B-(A[lb]+A[i]);
        }
        else if(lb+1 == i)
        {
            j--;
            ub = j;
        }
        else
            j--;
    }
    return B+best;
}
