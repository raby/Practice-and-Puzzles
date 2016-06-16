/*
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

 Balanced tree : a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1. 
Example :


Given A : [1, 2, 3]
A height balanced BST  : 

      2
    /   \
   1     3
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
 
TreeNode* constructTree(const vector<int> &A, int low, int high)
 {
     if(low>high)
        return NULL;
    int mid = (low+high)/2;
    TreeNode* t = new TreeNode(A[mid]);
    t->left = constructTree(A,low,mid-1);
    t->right = constructTree(A,mid+1,high);
    return t;
 }
 
TreeNode* Solution::sortedArrayToBST(const vector<int> &A) 
{
    if(A.empty())
        return NULL;
    return constructTree(A, 0, (A.size()-1) );
}

 
