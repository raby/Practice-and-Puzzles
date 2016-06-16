/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

Example :

Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.
*/
int Solution::numDecodings(string A)
{
    if ((A.empty())||(A[0]=='0'))
	return 0;
         
    int t1=1; //num from 0 to current-1
    int t2=1; //num from 0 to current-2
    for (int i=1; i<A.size();i++)
	{
        int tc=0; //num from 0 to current
        if ((A[i]=='0'))
		{
            int d1 = (A[i-1]-'0');
            if( (d1<3)&&(d1>0) )
				tc=t2;
        }
        if (A[i]!='0')
		{
            if(A[i-1]=='0')
				tc = t1;
             else
		    {
            int d2 = (A[i-1]-'0')*10+(A[i]-'0');
                if (d2<=26) 
					tc = t1+t2;
                else
					tc = t1;
            }
        }
        t2=t1;
        t1=tc;   
    }
    return t1;    
}

