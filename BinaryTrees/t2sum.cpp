/*

Given a binary search tree T, where each node contains a positive integer, and an integer K, you have to find whether or not there exist two different nodes A and B such that A.value + B.value = K.

Return 1 to denote that two such nodes exist. Return 0, otherwise.

Notes 
- Your solution should run in linear time and not take memory more than O(height of T).
- Assume all values in BST are distinct.

Example :

Input 1: 

T :       10
         / \
        9   20

K = 19

Return: 1

Input 2: 

T:        10
         / \
        9   20

K = 40

Return: 0
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
 stack<TreeNode*> s1;
 stack<TreeNode*> s2;
 
 void inorder(TreeNode* A)
 {
    if(A->left)
        inorder(A->left);
    s1.push(A);
    if(A->right)
        inorder(A->right);
 }
 
 void post(TreeNode* A)
 {
    if(A->right)
        post(A->right);
    s2.push(A);
    if(A->left)
        post(A->left);
     
 }
 
 
int Solution::t2Sum(TreeNode* A, int B) 
{
    while(!s1.empty())
        s1.pop();
    while(!s2.empty())
        s2.pop();
        
    inorder(A);
    post(A);
    
    while(!s1.empty() && !s2.empty())
    {
        if( (s1.top()->val!=s2.top()->val) && ((s1.top()->val+s2.top()->val) == B) )
        {
            return 1;
        }
        else if( (s1.top()->val+s2.top()->val) > B)
        {
            s1.pop();
        }
        else
        {
            s2.pop();
        }
    }
    return 0;
    
}
