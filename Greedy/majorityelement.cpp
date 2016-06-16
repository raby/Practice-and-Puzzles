/*
Given an array of size n, find the majority element. The majority element is the element that appears more than floor(n/2) times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example :

Input : [2, 1, 2]
Return  : 2 which occurs 2 times which is greater than 3/2. 
See Expected Output
NotesAll Notes

*/
int Solution::majorityElement(const vector<int> &A) 
{
    map<int,int> m;
    m.clear();
    
    for(int i=0;i<A.size();i++)
        m[A[i]]++;
    
    map<int,int>::iterator it = m.begin();
    for(it;it!=m.end();++it)
    {
        if( it->second > (A.size()/2) )
            return it->first;
    }
}
