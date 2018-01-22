class Solution {
public:
    // idea is very similar to the knapsack problem. Start from the end, an element can be either positive or negative.
    //when n becomes less than 0, check whether the cummulative sum has reached the target, if it has then increase the count.
    
    void getcount(vector<int> &nums, int target, int &count, int cum_sum,int n)
    {
       
        if (n < 0)
        {
            if(cum_sum == target)
            {
                count++;
                
            }
            return;
        }
        //recurse for both the possibilites.
        getcount(nums,target,count,cum_sum + (1 * nums[n]),n-1);
        getcount(nums,target,count,cum_sum + (-1 * nums[n]),n-1);

    }
    
    int findTargetSumWays(vector<int>& nums, int S) {
        int count = 0;
        getcount(nums,S,count,0,nums.size()-1);
        return count;        
    }
};