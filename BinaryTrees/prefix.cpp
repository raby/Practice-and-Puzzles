/*
Find shortest unique prefix to represent each word in the list.

Example:

Input: [zebra, dog, duck, dove]
Output: {z, dog, du, dov}
where we can see that
zebra = z
dog = dog
duck = du
dove = dov
 NOTE : Assume that no word is prefix of another. In other words, the representation is always possible. 
 */
 class BT
{
	protected:
		class node
		{
			public:
				int count;
				int end;
				node* alph[26];
				node()
				{
					count = 0;
					end = 0;
					for(int i=0;i<26;i++)
					{
						alph[i] = NULL;
					}
				}
		};
		node* root;
	public:
		
		vector<string> ans;
		BT()
		{
			root = new node();
			words = 0;
			ans.clear();
		}
		node* getRoot()
		{
			return root;
		}
		void insert(string v_)
		{
			words++;
			int i=0;
			node* t = root;
			for(int i=0;i<v_.size();i++)
			{
				int ind = (int)(v_[i]-'a');
				if(!t->alph[ind])
					t->alph[ind] = new node();
				t = t->alph[ind];
				t->count++;
				if(i==v_.size()-1)
					t->end = 1;
			}
		}
		
		void getPrefix(const vector<string> &A)
		{
			for(int i=0;i<A.size();i++)
			{
				int j = 0;
				node *t = root->alph[(int)(A[i][j]-'a')];
				while(t->count>1 && (j!=A[i].size()-1) )
					t = t->alph[(int)(A[i][++j]-'a')];
				ans.push_back(A[i].substr(0,j+1));
			}	
		}

		vector<string> getAns()
		{
			return ans;
		}
		
};


vector<string> Solution::prefix(vector<string> &A) 
{
    BT p;
    for(int i=0;i<A.size();i++)
        p.insert(A[i]);   
        
    p.getPrefix(A);
    
    return p.getAns();
}
