/*
Given two words (start and end), and a dictionary, find the shortest transformation sequence from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
If there are multiple such sequence of shortest length, return all of them. Refer to the example for more details.

Example :

Given:

start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
Return

  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]
 Note:
All words have the same length.
All words contain only lowercase alphabetic characters.
*/

//Note, solution could be optimized.

bool checkString(const string &a, const string &b)
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
 
vector<vector<string> > Solution::findLadders(string start, string end, vector<string> &dict) {
    vector<vector<string>> ans;
	ans.clear();
 
	map<string, bool> visited;
	for (int i = 0; i < dict.size();i++)
		visited[dict[i]] = 0;
	
	map<string, bool>::iterator it = visited.begin();
	vector<string> t;
	t.push_back(start);
	ans.push_back(t);
	queue<vector<string>> q;
	q.push(t);
	
	while (!q.empty())
	{
		vector<string> t = q.front();
		q.pop();
		visited[ t[t.size() - 1] ] = true;
 
		for (it; it != visited.end(); it++)
		{
			if (visited[it->first]==0 && checkString(t[t.size() - 1], it->first) ) 
			{
				vector<string> v = t;
				v.push_back(it->first);
				ans.push_back(v);
				q.push(v);
			}
		}
		it = visited.begin();
	}
	
	vector<vector<string>>::iterator jt = ans.begin();
	
	vector<vector<string> > tor;
	tor.clear();
 
	for (jt; jt!=ans.end(); jt++) 
		if ((*jt)[jt->size() - 1] == end)
			tor.push_back(*jt);
	return tor;
}