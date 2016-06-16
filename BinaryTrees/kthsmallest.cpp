/*
Given a binary search tree, write a function to find the kth smallest element in the tree.

Example :

Input : 
  2
 / \
1   3

and k = 2

Return : 2

As 2 is the second smallest element in the tree.
 NOTE : You may assume 1 <= k <= Total number of nodes in BST 
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
 
 
int Solution::kthsmallest(TreeNode* root, int k) 
{
    int ksmall = INT_MIN;
    int count =  0;
    TreeNode* cur = root;
    while(cur!=NULL)
    {
        if(cur->left==NULL)
        {
            count++;
            if(count==k)
                ksmall = cur->val;
            cur = cur->right;
        }
        else
        {
            TreeNode *pre = cur->left;
            while(pre->right!=NULL && pre->right!=cur)
                pre=pre->right;
            if(pre->right==NULL)
            {
                pre->right = cur;
                cur = cur->left;
            }
            else
            {
                pre->right = NULL;
                count++;
                if(count==k)
                    ksmall = cur->val;
                cur = cur->right;
            }
        }
    }
    return ksmall;
}
