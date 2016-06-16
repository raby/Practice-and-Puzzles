/*
Given a string, 
find the length of the longest substring without repeating characters.

Example:

The longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3.

For "bbbbb" the longest substring is "b", with the length of 1.
*/
int Solution::lengthOfLongestSubstring(string A) 
{
    map<char, int> m;
    int max = 0;
    int rc = 0;
    int j = 0;
    
    for(int i=0;i<A.size();i)
    {
        j = i;
        rc = 0;
        while(j<A.size() && m[A[j]]==0)
        {
            rc++;
            if(rc>max)
                max = rc;
            m[A[j]]=j+1;
            j++;
        }
		
        i = m[A[j]];
        m.clear();
        if( j == A.size() )
            break;
    }
    return max;
}
