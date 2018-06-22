#include <bits/stdc++.h>
using namespace std;
// main idea of algorithm is something similar to 0/1 knapsack problem/...an item can be included or not included in the given iteration

bool isSubSetSum(vector<int> arr, int n, int sum)
{
    // create a 2d matrix of size (n+1) * (sum+1)
    // dp[i][j] is true when there exists a subset arr[0 to i-1] with sum equals to j
    vector<vector<bool>>dp(n+1,(vector<bool>(sum+1,false)));
    
    // if j=0, means that sum = 0, then it is possible to obtain the empty susbet whose sum equals to 0
    for(int i =0; i <=n; i++)
        dp[i][0] = true;
        
    //if the input array is of length zero then sum is not all possible
    for(int i=1; i<= sum; i++)
        dp[0][i] = false;
        
        
    for(int i = 1; i<=n; i++)
    {
        for(int j=1; j<=sum; j++)
        {
            // if the current array element is greater than sum, then  dont include this element.
            if(arr[i-1] > j)
                dp[i][j] = dp[i-1][j];
            else 
                dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
        }
    }
    
    return dp[n][sum];
}


int
main()
{
    
    vector<int> arr = {1,2,45,54,7};
    int n = arr.size();
    cout << isSubSetSum(arr,n,9);
    
    return 0;
}