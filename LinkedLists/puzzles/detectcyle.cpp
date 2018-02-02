/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Try solving it using constant additional space.

Example :

Input : 

                  ______
                 |     |
                 \/    |
        1 -> 2 -> 3 -> 4

Return the node corresponding to node 3. 
*/

ListNode* Solution::detectCycle(ListNode* A) 
{  

    int k = 0;
  ListNode* slow = A;
  ListNode* fast = A;

  while (fast->next != NULL && fast->next->next != NULL)
  {
    slow = slow->next;
    fast = fast->next->next;
    
    k++;
    
    if (slow == fast)
    {
        ListNode* endk = A;
        ListNode* startk = A;
        
        for(int i=0;i<k;i++)
            endk = endk->next;
            
        while(endk!=startk)
        {
            endk=endk->next;
            startk = startk->next;
        }
        
        return startk;
    }
  }

  return NULL;
}
