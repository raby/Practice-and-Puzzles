/*
Sort a linked list in O(n log n) time using constant space complexity.

Example :

Input : 1 -> 5 -> 4 -> 3

Returned list : 1 -> 2 -> 4 -> 5
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 struct ListNode* sortedMerge(struct ListNode* a, struct ListNode* b);
 void frontBackSplit(struct ListNode* source, struct ListNode** frontRef, struct ListNode** backRef);
 
 ListNode* mergeSort(struct ListNode** headRef)
 {
    struct ListNode* head = *headRef;
    struct ListNode* a;
    struct ListNode* b;
    
    if((head == nullptr) || (head->next == nullptr) )
        return head;
        
    frontBackSplit(head, &a, &b);
    mergeSort(&a);
    mergeSort(&b);
    
    *headRef = sortedMerge(a,b);
    
 }
 
 struct ListNode* sortedMerge(struct ListNode* a, struct ListNode* b)
 {
    struct ListNode* result = nullptr;
     
     if(a == nullptr)
        return(b);
    else if(b==nullptr)
        return(a);
        
    if(a->val <= b->val)
    {
        result = a;
        result->next = sortedMerge(a->next, b);
    }
    else
    {
        result = b;
        result->next = sortedMerge(a, b->next);
    }
    return(result);
 }
 
 void frontBackSplit(struct ListNode* source, struct ListNode** frontRef, struct ListNode** backRef)
 {
     struct ListNode* fast;
     struct ListNode* slow;
     if(source == nullptr || source->next == nullptr)
     {
         *frontRef = source;
         *backRef = nullptr;
     }
     else
     {
         slow = source;
         fast = source->next;
         
         while(fast != nullptr)
         {
             fast = fast->next;
             if(fast!=nullptr)
             {
                 slow = slow->next;
                 fast = fast->next;
             }
         }
         
         *frontRef = source;
         *backRef = slow->next;
         slow->next = nullptr;
         
     }
 }
 
ListNode* Solution::sortList(ListNode* A) {
    ListNode** h = &A;
    return mergeSort(h);
    
}
