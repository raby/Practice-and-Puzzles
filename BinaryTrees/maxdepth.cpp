/*
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the nearest leaf node.

 NOTE : The path has to end on a leaf node. 
Example :

         1
        /
       2
max depth = 2.
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
 
 
int Solution::maxDepth(TreeNode* A) 
{
    if(A == NULL)
        return 0;
    else
    {
        int ld = maxDepth(A->left);
        int rd = maxDepth(A->right);
        if(ld>rd)
            return (ld+1);
        else return (rd+1);
    }
    
}
