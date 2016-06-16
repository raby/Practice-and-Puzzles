/*
Given A, how many structurally unique BST’s (binary search trees) that store values 1...A?

Example :

Given A = 3, there are a total of 5 unique BST’s.


   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

  */

  int Solution::numTrees(int A) 
{
    if(A<=0)
        return 0;
    vector<int> trees(A+1,0);
    trees[0] = 1;
    for(int i=1;i<=A;i++)
        for(int j=0;j<i;j++)
            trees[i] += trees[j] * trees[i-j-1];
            
    return trees[A];
    
}
