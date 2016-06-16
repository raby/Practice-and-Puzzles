/*
Given a binary tree, return the level order traversal of its nodes’ values. (ie, from left to right, level by level).

Example :
Given binary tree

    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:

[
  [3],
  [9,20],
  [15,7]
]
Also think about a version of the question where you are asked to do a level order traversal of the tree when depth of the tree is much greater than number of nodes on a level.
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
vector<vector<int> > Solution::levelOrder(TreeNode* A) 
{
    int l = 0;
    map<int,vector<int>> answerMap;
    queue<pair<TreeNode* , int>> que;
    vector<vector<int>> ans;
    
    answerMap.clear();
    ans.clear();
    
    
    que.push(make_pair(A,l));
    while(!que.empty())
    {
        TreeNode* temp  = que.front().first;
        l =  que.front().second+1;
        answerMap[que.front().second].push_back(temp->val);
        que.pop();
        
        if(temp->left)
            que.push(make_pair(temp->left,l));
        if(temp->right)
            que.push(make_pair(temp->right,l));
    }
    map<int,vector<int>>::iterator it = answerMap.begin();
    for(it;it!=answerMap.end();it++)
        ans.push_back(it->second);
    return ans;
    
    
}
