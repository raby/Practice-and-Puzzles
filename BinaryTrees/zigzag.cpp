/*
Given a binary tree, return the zigzag level order traversal of its nodes’ values. (ie, from left to right, then right to left for the next level and alternate between).

Example : 
Given binary tree

    3
   / \
  9  20
    /  \
   15   7
return

[
         [3],
         [20, 9],
         [15, 7]
]
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
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) 
{
		stack<TreeNode*> q1;
		stack<TreeNode*> q2;
		
		
        vector<vector<int>>ans;
        ans.clear();
        

		q1.push(A);
		TreeNode* t;
		vector<int> l;
		l.clear();
		while(!q1.empty() || !q2.empty() )
		{
		    
			while(!q1.empty())
			{
				t = q1.top();
				q1.pop();
                l.push_back(t->val);
                
				if(t->left!=NULL)
					q2.push(t->left);
				if(t->right!=NULL)
					q2.push(t->right);
		
			}
			if(!l.empty())
			    ans.push_back(l);
            l.clear();
            
			while(!q2.empty())
			{
				t = q2.top();
				q2.pop();
                l.push_back(t->val);    

				if(t->right!=NULL)
					q1.push(t->right);
				if(t->left!=NULL)
					q1.push(t->left);

			}
			if(!l.empty())
			    ans.push_back(l);
			l.clear();

		}
		return ans;
    
}
