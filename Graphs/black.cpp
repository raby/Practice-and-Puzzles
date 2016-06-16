/*
Given N * M field of O's and X's, where O=white, X=black
Return the number of black shapes. A black shape consists of one or more adjacent X's (diagonals not included)

Example:

OOOXOOO
OOXXOXO
OXOOOXO

answer is 3 shapes are  :
(i)    X
     X X
(ii)
      X
 (iii)
      X
      X
Note that we are looking for connected shapes here.

For example,

XXX
XXX
XXX
is just one single connected black shape.
*/
void traverse(vector<string> &A,int i,int j)
{
    queue<pair<int,int>> q;
    q.push(make_pair(i,j));
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        if(x+1<A.size() && A[x+1][y]=='X')
        {
            q.push(make_pair(x+1,y));
            A[x+1][y] = 'O';
        }
        if(x-1>=0 && A[x-1][y]=='X')
        {
            q.push(make_pair(x-1,y));
            A[x-1][y] = 'O';
        }
        if(y+1<A[0].size() && A[x][y+1]=='X')
        {
            q.push(make_pair(x,y+1));
            A[x][y+1] = '0';
        }
        if(y-1>=0 && A[x][y-1]=='X')
        {
            q.push(make_pair(x,y-1));
            A[x][y-1] = '0';
        }
    }
}

int Solution::black(vector<string> &A) {
    int ans = 0;
    
    for(int i=0;i<A.size();i++)
    {
        for(int j = 0;j<A[i].size();j++)
        {
            if(A[i][j]=='X')
            {   
                ans++;
                traverse(A,i,j);
            }
            
        }
    }
    
    
    return ans;
}
