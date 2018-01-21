#include<bits/stdc++.h>

using namespace std;
//idea of the algorithm is to do a dfs on the given array and for every iteration excluded the previosuly included elements.


bool dfs(vector<int> arr, vector<bool> &visited, int curren_sum, int k, int target,int pos)
{
    //if k==1 means that,this arry can be easily partitioned into any sum.
    if (k == 1)
        return true;
    //if the curren_sum is greater than target,then lastly added element cannot be inlcuded as part of the partition
    if (curren_sum > target)
        return false;
    // if the curren_sum reaches target , then call dfs on the rest of elements until k reaches 1
    if (curren_sum == target) return dfs(arr, visited, 0, k-1, target,0);
    
    for(int i = pos; i < arr.size(); i++)
    {   // watch out for the previosuly visited elements
        if(!visited[i])
        {
            visited[i] = true;
            if(dfs(arr, visited, curren_sum + arr[i], k, target,i+1))
                return true;
            visited[i] = false;
        }
    }
    return false;
}

int  
main()
{
    
    vector<int>arr = {4, 3, 2, 3, 5, 2, 1};
    int k = 4;
    int sum = 0;
    int n = arr.size();
    for(auto e:arr)
        sum += e;
    // check if the sum is divisible by the given k value.
    if(sum%k != 0)
        return false;
    
    vector<bool>visited(n,false);
    cout << dfs(arr,visited,0,k,sum/k,0);
    return 0;
    
}