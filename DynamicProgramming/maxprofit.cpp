/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Example :

Input : [1 2]
Return :  1
*/
int max(int a, int b)
{
    return (a>b) ? a : b;    
}
int min(int a, int b)
{
    return (a<b)? a : b;
}

int Solution::maxProfit(const vector<int> &A) {
    
    int profit = 0;
    int minElement = INT_MAX;
    for(int i=0; i<A.size(); i++){
       profit = max(profit, A[i]-minElement);
       minElement = min(minElement, A[i]);
    }
    return profit;
}
