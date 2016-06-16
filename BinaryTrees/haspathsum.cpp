/*
iven a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

Example :

Given the below binary tree and sum = 22,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

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
void dfs(TreeNode* A, int B, int &ans)
{
    
    if(A->left==NULL && A->right==NULL && B==0)
    {
        ans=1;
        return;
    }
    
    
    if(A->left)
    {
        dfs(A->left, B-A->left->val, ans);
    }
    
    if(A->right)
    {
        dfs(A->right,B-A->right->val, ans); 
    }
    
}

int Solution::hasPathSum(TreeNode* A, int B) 
{
    int ans = 0;
    dfs(A,B-A->val,ans);
    return ans;
}
