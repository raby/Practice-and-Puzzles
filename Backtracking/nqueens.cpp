/*
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.



Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens’ placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
*/
vector<vector<string>> ans;


bool isSafe(int queen_number, int row_position, int position[])
{
	// Check each queen before this one
	for (int i = 0; i < queen_number; i++)
	{
		// Get another queen's row_position
		int other_row_pos = position[i];

		// Now check if they're in the same row or diagonals
		if (other_row_pos == row_position || // Same row
			other_row_pos == row_position - (queen_number - i) || // Same diagonal
			other_row_pos == row_position + (queen_number - i))   // Same diagonal
			return false;
	}
	return true;
}


// Recursively generate a tuple like [0 0 0 0], then [0 0 0 1] then etc...
void solve(int k, int N, int position[])
{
	if (k == N) // We placed N-1 queens (0 included), problem solved!
	{
		// Solution found!
		string r = "";
		vector<string> rp;
		rp.clear();
		for (int i = 0; i < N; i++)
		{
		    r = "";
			for(int j = 0; j< N; j++)
			{
				if(j==position[i])
					r+="Q";
				else
					r+=".";
			}
			rp.push_back(r);
		}
		ans.push_back(rp);
	}
	else
	{
		for (int i = 0; i < N; i++) // Generate ALL combinations
		{
			// Before putting a queen (the k-th queen) into a row, test it for safeness
			if (isSafe(k, i, position))
			{
				position[k] = i;
				// Place another queen
				solve(k + 1, N, position);
			}
		}
	}
}

vector<vector<string> > Solution::solveNQueens(int A) {
	ans.clear();
	if(A==1)
	{
	    string r = "Q";
	    vector<string> rp;
	    rp.push_back(r);
	    ans.push_back(rp);
	    return ans;
	}
	else if(A<=3)
	    return ans;
	else
	{
	    int position[A];
	    solve(0,A,position);
	    return ans;
	}
	

}
