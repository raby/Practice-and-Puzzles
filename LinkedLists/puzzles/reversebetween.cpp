/*
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

 Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list. Note 2:
Usually the version often seen in the interviews is reversing the whole linked list which is obviously an easier version of this question. 
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseBetween(ListNode* A, int m, int n) {
	if(A->next==nullptr && m == 1 && n == 1)
		return A;

	ListNode* tr = A;
	ListNode* c = A;
	ListNode* p = A;

	for(int i = 1; i<m ; i++)
	{
		p = c;
		c = c->next;
	}

	ListNode* hs = nullptr;
	ListNode* t = nullptr; 
	ListNode* tp;

	for(int i = 0; i<=(n-m); i++)
	{
		t = new ListNode(c->val);
		if(i==0)
			tp = t;	
		ListNode* td = c;
		c = c->next;
		delete td;
		t->next = hs;
		hs = t;
	}
	if(m==1)
	{
		tp->next = c;
		return hs;
	}
	else
		p->next = hs;
	tp->next = c;
	return tr;
    
}
