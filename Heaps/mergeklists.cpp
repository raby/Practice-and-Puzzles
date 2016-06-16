/*

Merge k sorted linked lists and return it as one sorted list.

Example :

1 -> 10 -> 20
4 -> 11 -> 13
3 -> 8 -> 9
will result in

1 -> 3 -> 4 -> 8 -> 9 -> 10 -> 11 -> 13 -> 20
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeKLists(vector<ListNode*> &A) 
{   
    if(A.size()==1)
        return A[0];
    
    map<int,vector<ListNode*>> m;
    for(int i=0;i<A.size();i++)
    {
        ListNode *t =A[i];
        while(t)
        {
            m[t->val].push_back(t);
            t = t->next;
        }
    }
	map<int,vector<ListNode*>>::iterator it=m.begin();
	vector<ListNode*>::iterator jt=it->second.begin();
	ListNode *t=NULL;
	ListNode *t2=NULL;
	ListNode *root=jt++[0];
	if(jt!=it->second.end())
		t = jt++[0];
	else
	{
		it++;
		jt = it->second.begin();
		t = jt++[0];
	}
	root->next = t;
	t2 = t;
	while(it!=m.end())
	{
		while(jt!=it->second.end())
		{
			t2 = jt++[0];
			t->next = t2;
			t = t->next;
		}
		it++;
		if(it!=m.end())
			jt = it->second.begin();
	}

	m.erase(m.begin(),m.end());
	return root;
}
