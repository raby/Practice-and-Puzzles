/*
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers % 1003.

Example :

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = (12 + 13) % 1003 = 25 % 1003 = 25.
*/

int sum;

void dfs(TreeNode* A, int cur)
{
    if(A==NULL)
        return;
    cur = ((cur * 10) + A->val)%1003;
    if(A->left == NULL && A->right == NULL)
    {
        sum = (cur+sum)%1003;
        return;
    }
    if(A->left)
        dfs(A->left, cur);
    if(A->right)
    dfs(A->right, cur);
    return;
}

int Solution::sumNumbers(TreeNode* A) 
{
    if(A==NULL)
        return 0;
        
    int cur = 0;
    sum = 0;
    dfs(A, cur);
    return sum;
}
