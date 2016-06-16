/* Given a binary tree, return the inorder/postorder/preorder traversal of its nodes’ values.

Example :
Given binary tree

   1
    \
     2
    /
   3
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
void iot(TreeNode* A, vector<int> &ans)
{
    if(A->left)
        iot(A->left,ans);
        
    ans.push_back(A->val);
    
    if(A->right)
        iot(A->right,ans);
}
 
vector<int> Solution::inorderTraversal(TreeNode* A) 
{
    vector<int> ans;
    ans.clear();
    iot(A, ans);
    return ans;
}

//post order is right left root 

vector<int> ans;
void pot(TreeNode* A)
{
    if(A->left)
        pot(A->left);
    if(A->right)
        pot(A->right);
    ans.push_back(A->val);
}
vector<int> Solution::postorderTraversal(TreeNode* A) 
{
    ans.clear();
    pot(A);
    return ans;
}

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 //root right left 
 vector<int> ans;
void preot(TreeNode* A)
{
    ans.push_back(A->val);
    
    if(A->left)
        preot(A->left);
        
    if(A->right)
        preot(A->right);
}
vector<int> Solution::preorderTraversal(TreeNode* A) {
    ans.clear();
    preot(A);
    return ans;
}
