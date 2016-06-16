/*
The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2
There might be multiple gray code sequences possible for a given n.
Return any such sequence.
*/
vector<int> ans;

void generateGrayarr(int n)
{
	ans.clear();
    if (n <= 0)
        return;
 
    vector<string> arr;
 
    arr.push_back("0");
    arr.push_back("1");
 
    int i, j;
    for (i = 2; i < (1<<n); i = i<<1)
    {
        for (j = i-1 ; j >= 0 ; j--)
            arr.push_back(arr[j]);
 
        for (j = 0 ; j < i ; j++)
            arr[j] = "0" + arr[j];
 
        for (j = i ; j < 2*i ; j++)
            arr[j] = "1" + arr[j];
    }

	for (i = 0 ; i < arr.size() ; i++ )
	{
		int res=0;
		for(int j=0;j<arr[i].size();j++)
			res = (res<<1) + (arr[i][j]-'0');
		ans.push_back(res);
	}
}



vector<int> Solution::grayCode(int A) 
{
    generateGrayarr(A);
    return ans;
}
