/*
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

    342 + 465 = 807
Make sure there are no trailing zeros in the output list
So, 7 -> 0 -> 8 -> 0 is not a valid response even though the value is still 807.
*/

 void carry(int &c,int &val)
 {
    if( (val + c) > 9)
    {
		int t = (val+c);
        val = t%10;
        c = t/10;
    }
    else if(c>=0 && val <= 9)
	{
	    int tc = 10 - val;
		if(c-tc >= 0)
		{
			val = 0;
			c=c-tc;
		}
		else
		{
			val = val + c;
			c = 0;
		}
	}
 }
 
 ListNode* sumList(ListNode* A, ListNode* B, int c)
 {
    ListNode* m = nullptr;
	ListNode* t = nullptr;
	ListNode* e = nullptr;
     
    while( (A!=nullptr || B!=nullptr || c!=0) )
    {   
		if(A==nullptr && B==nullptr)
		{
			t = new ListNode(0 + 0);
			carry(c, t->val);
		}
		else if(A==nullptr)
		{
			t = new ListNode(0 + B->val);
			carry(c,t->val);
			B = B->next;
		}
		else if(B==nullptr)
		{
			t = new ListNode(A->val + 0);
			carry(c,t->val);
			A = A->next;
		}
		else 
        {
           t = new ListNode( A->val + B->val) ;
           carry(c,t->val);
		   A = A->next;
		   B = B->next;
        }
		if(m==nullptr)
		{
			m = t;
			e = t;
		}
		else
		{
			e->next = t;
			e = e->next;
		}
        
	}
	return m;
}
 
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    return sumList(A,B,0);
}
