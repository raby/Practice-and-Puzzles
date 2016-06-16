/*
Given two binary trees T1 and T2, you have to find minimum number of insertions to be done in T1 to make it structurally identical to T2. Return -1 if not possible.

Notes 
- Assume insertions are done in a normal fashion in the BSTs.
- Assume while inserting, if the value of a node v is equal to value being inserted, we insert it in left subtree of node v.
- You can insert any positive or negative integer.

Example :

Input 1: 

T1:       10
         / \
        9   20

T2:       5
         / \
        2   7
       /
      1

If you insert 8 into T1, it will be structurally identical to T2. Hence answer is 1.


Input 2: 

T1:       10
         / \
        9   20

T2:       5
           \
            7

You cannot make T1 and T2 structurally identical. Hence answer is -1.
*/


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 void countMissing(TreeNode* T, int& ans)
 {
     if(T->left)
        countMissing(T->left, ++ans );
    if(T->right)
        countMissing(T->right, ++ans );
 }
 
 void traverseTree(TreeNode* A, TreeNode* B, int& ans)
 {
    
    if( (A->left && !B->left) || (A->right && !B->right) )
        ans =  -1;
    else
    {
        if(!A->left && B->left)
            countMissing(B->left, ++ans);
    
        if(!A->right && B->right)
            countMissing(B->right, ++ans);
    
        if(A->left && B->left)
            traverseTree(A->left,B->left,ans);
    
        if(A->right && B->right)
            traverseTree(A->right,B->right,ans);
    }
     
 }
 
int Solution::cntMatrix(TreeNode* A, TreeNode* B) 
{
    int ans = 0;
    traverseTree(A,B,ans);
    return ans;
    
}
