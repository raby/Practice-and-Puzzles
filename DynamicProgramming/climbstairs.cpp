/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Example :

Input : 3
Return : 3

Steps : [1 1 1], [1 2], [2 1]

See Expected Output
NotesAll Notes


Time to Solve: 13 min. / Average Solving Time: 10 min.
*/
int Solution::climbStairs(int A) 
{
    if (A<3)
        return A;
    
    int f1=1;
    int f2=2;
    
    for (int i=3;i<=A;i++)
    {
        f2=f1+f2;
        f1=f2-f1;
    }
    return f2;
}
