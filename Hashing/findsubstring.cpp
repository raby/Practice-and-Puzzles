/*
You are given a string, S, and a list of words, L, that are all of the same length.

Find all starting indices of substring(s) in S that is a concatenation of each word in L exactly once and without any intervening characters.

Example :

S: "barfoothefoobarman"
L: ["foo", "bar"]
You should return the indices: [0,9].
(order does not matter).
*/

map<string,vector<int>> m;

void genMap(vector<string> B)
{
	sort(B.begin(),B.end());
do {
	string l = "";
	for(int i=0;i<B.size();i++)
		l += B[i];
	m[l].push_back(-1);

	} while ( next_permutation(B.begin(),B.end()) );
}

vector<int> Solution::findSubstring(string A, const vector<string> &B) 
{
	vector<int> ans;
	
	m.clear();
	ans.clear();
	
	if(A.size()<( B[0].size()*B.size()) )
	    return ans;
	
	genMap(B);
	for(int i=0;i<=A.size()-( B[0].size()*B.size() );i++)
	{
		string a=A.substr(i,B[0].size()*B.size());
		if(!m[a].empty())
			ans.push_back(i);
		else
			m.erase(a);
	}
	return ans;
}
