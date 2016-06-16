/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

Example :

    1
   / \
  2   2
 / \ / \
3  4 4  3
The above binary tree is symmetric. 
But the following is not:

    1
   / \
  2   2
   \   \
   3    3
Return 0 / 1 ( 0 for false, 1 for true ) for this problem
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
int Solution::isSymmetric(TreeNode* A) 
{
    stack<TreeNode*> s1;
    stack<TreeNode*> s2;
    
    if(A->left)
        s1.push(A->left);
    if(A->right)
        s2.push(A->right);
    
    if(s1.size()!=s2.size())
        return 0;
    
    TreeNode* l;
    TreeNode* r;
    
    while(!s1.empty() || !s2.empty())
    {
        l = s1.top();
        r = s2.top();
        s1.pop();
        s2.pop();
        if(l->val!=r->val)
            return 0;
        if(l->left && r->right)
        {
            s1.push(l->left);
            s2.push(r->right);
        }
        if(l->right && r->left)
        {
            s1.push(l->right);
            s2.push(r->left);
        }
            
    }
    
    return 1;
    
}
