/*
Max Continuous Series of 1sBookmark
You are given with an array of 1s and 0s. And you are given with an integer M, which signifies number of flips allowed.
Find the position of zeros which when flipped will produce maximum continuous series of 1s.

For this problem, return the indices of maximum continuous series of 1s in order.

Example:

Input : 
Array = {1 1 0 1 1 0 0 1 1 1 } 
M = 1

Output : 
[0, 1, 2, 3, 4] 

If there are multiple possible solutions, return the sequence which has the minimum start index.
*/

vector<int> Solution::maxone(vector<int> &A, int B) 
{
    int i = 0, j = 0, num_zero = 0, s = 0, max = 0;
    
    if(A[0] == 0)
        num_zero++;
    while(i<A.size())
    {
        
        i++;
        
        if(num_zero > B)
        {
            if(A[j]==0)
                num_zero--;
            j++;
        }
        
        if(A[i] == 0)
            num_zero++;

        
        if( (i-j) > max)
        {
            max = (i-j);
            s = j;
        }
    }
    vector<int> sol(max);
    for(int i=0;i<max;i++)
    {
        sol[i] = s;
        s++;
    }
    return sol;
}
