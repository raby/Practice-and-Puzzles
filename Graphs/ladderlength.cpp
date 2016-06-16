/*
Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that:

You must change exactly one character in every transformation
Each intermediate word must exist in the dictionary
Example :

Given:

start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note that we account for the length of the transformation path instead of the number of transformation itself.

 Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
*/

/*Code could be optimized and more coincise, but it's late on a Friday night and I am tired*/

bool checkString(string &a, string &b)
{
    bool grace = 0;
    int i = 0;
    if(a == b)
        return false;
    while(i<a.size())
    {
        if(a[i]!=b[i])
        {
            if(grace == 1)
                return false;
            grace = 1;
        }
        i++;
    }
    return true;
}

int Solution::ladderLength(string start, string end, vector<string> &dictV) {
    if(start == end)
        return 1;
    
    map<string,int> distance;
    map<string,bool> visited;
    queue<string> q;
    q.push(start);
    distance[start] = 1;
    while(!q.empty())
    {
        string t = q.front();
        q.pop();
        visited[t] = true;
        for(int i=0;i<dictV.size();i++)
        {
            if(!visited[dictV[i]] && checkString(t,dictV[i]) )
            {
                distance[dictV[i]] = distance[t] + 1;
                if(dictV[i] == end)
                    return distance[t]+1;
                q.push(dictV[i]);
            }
        }
    }
    return distance[end];
}
