class Solution {
public:
    
    /* main idea;
    let i be start of the substring
    let j be end of the substring
    eg - "bbab" - i = 0, j = 2 -> "bba"
    We go on bulding the dp matrix based on the logic below.
    The matrix for the string "bbab" would like this
         b b a b    
      b  1 2 2 3 
      b  0 1 1 3 
      a  0 0 1 1 
      b  0 0 0 1
    

    */
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        if (n == 0)
            return 0;
        
        vector<vector<int>>dp(n,vector<int>(n,0));
        
        for(int i=0 ; i<n ; i++)
            dp[i][i] = 1;
        
    
        int j;
        //0 1 2 3 4
        for(int c = 2; c<= n; c++)
        {
            for(int i = 0; i < n-c+1; i++)
            {
                j = i + c -1;
                if(s[i] == s[j] && c == 2)
                {
                    dp[i][j] = 2;
                }
                else
                    if(s[i] == s[j])
                    {
                        dp[i][j] = 2 + dp[i+1][j-1];
                    }
                else
                    dp[i][j] = max(dp[i][j-1],dp[i+1][j]);
            }
        }
    
        
        return dp[0][n-1];
    }
};