/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.


*/
int max(int a, int b)
{
    return (a>b) ? a : b;
}

int Solution::longestValidParentheses(string A) 
{
    stack<int> s;
    s.push(-1);
    int result=0;
    for(int i=0;i<A.size();i++)
    {
        if(A[i]=='(')
            s.push(i);
        
        else
        {
         
            s.pop();   
            if(!s.empty())
                result = max(result, i-s.top());
            else
                s.push(i);
        }
    }
    return result;
}
