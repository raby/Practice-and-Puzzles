/*
Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

The first call to next() will return the smallest number in BST. Calling next() again will return the next smallest number in the BST, and so on.

 Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
Try to optimize the additional space complexity apart from the amortized time complexity. 
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
queue<TreeNode*> q;
void loadIT(TreeNode* root)
{
    if(root->left)
        loadIT(root->left);
    q.push(root);
    if(root->right)
        loadIT(root->right);
}

BSTIterator::BSTIterator(TreeNode *root) {
    while(!q.empty())
        q.pop();
    if(root!=NULL)
        loadIT(root);
    
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() {
    return !q.empty();
}

/** @return the next smallest number */
int BSTIterator::next() {
    int t = q.front()->val;
    q.pop();
    return t;
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
