#include <bits/stdc++.h>

using namespace std;

int KnapSack(vector<int> val, vector<int> wt,int W, int n)
{
    // dp[i][j] gives the max value that can be obtained by including elements from [0-i] summing up to j.
    // allocate a 2d matrix
    vector<vector<int>>dp(n+1, vector<int>(W+1));
    
    
    for(int i=0; i<= n; i++)
    {
        for(int j=0; j<= W; j++)
        {
            if(i == 0 || j ==0)
                dp[i][j] = 0;
            else if(wt[i-1] > j)
                dp[i][j] = dp[i-1][j];
            // val[i-1] + dp[i-1][j-wt[i-1]] => if the current element is considered ,
            // then add its val[i-1] and identify the val that can be obtained by reducing the current weight i.e j-wt[i-1]
            else
                dp[i][j] = max(dp[i-1][j],val[i-1]+dp[i-1][j-wt[i-1]]);
        }
    }
    return dp[n][W];
    
    
}

int main()
{
	vector<int>val = {60, 100, 120};
	vector<int>wt = {10, 20, 30};
	int W = 60;
	cout << KnapSack(val,wt,W,val.size());
	return 0;
}
