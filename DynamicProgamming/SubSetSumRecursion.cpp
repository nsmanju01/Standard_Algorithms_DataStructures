#include <bits/stdc++.h>
using namespace std;
// main idea of algorithm is something similar to 0/1 knapsack problem/...an item can be included or not included in the given iteration

bool isSubSetSum(vector<int> arr, int n, int sum)
{
    //base cases
    if (n == 0 && sum > 0)
    return false;
    
    if (sum == 0)
    return true;
    // if the given array element is greater than the sum,then that element has to be excluded.
    if (arr[n-1] > sum)
        return isSubSetSum(arr, n-1, sum);
    // recurse to check whether target can be reached with or without including the current number
    return isSubSetSum(arr,n-1,sum) || isSubSetSum(arr, n-1, sum-arr[n-1]);
    
}


int
main()
{
    
    vector<int> arr = {1,2,45,54,7};
    int n = arr.size();
    cout << isSubSetSum(arr,n,4);
    
    return 0;
}
