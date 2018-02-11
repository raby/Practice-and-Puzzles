/*
Given a binary tree, flatten it to a linked list in-place.

Example :
Given


         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:

   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
Note that the left child of all nodes should be NULL.
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


TreeNode* Solution::flatten(TreeNode* root) {
    if(!root)
        return NULL;
    TreeNode* node = root;
    while(node) {
        if (node->left) {
            TreeNode *rightMost = node->left;
            while (rightMost->right)
                rightMost = rightMost->right;
            rightMost->right = node->right;
            node->right = node->left;
            node->left = NULL;
        }
            node = node->right;
    }
    return root;
}
