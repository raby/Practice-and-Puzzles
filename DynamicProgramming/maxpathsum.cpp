/*
Given a binary tree, find the maximum path sum.

The path may start and end at any node in the tree.

Example :

Given the below binary tree,

       1
      / \
     2   3
Return 6.
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
 int findMaxUtil(TreeNode* root, int &res)
{
    if (root == NULL)
        return 0;
 
    int l = findMaxUtil(root->left,res);
    int r = findMaxUtil(root->right,res);
 
    int max_single = max(max(l, r) + root->val, root->val);
 
    int max_top = max(max_single, l + r + root->val);
 
    res = max(res, max_top); // Store the Maximum Result.
 
    return max_single;
}
 
int findMaxSum(TreeNode *root)
{
    int res = INT_MIN;
 
    findMaxUtil(root, res);
    return res;
}
int Solution::maxPathSum(TreeNode* A) {
    
    return findMaxSum(A);
    
}
