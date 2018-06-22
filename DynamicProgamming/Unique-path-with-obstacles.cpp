class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        // if the starting position is an obstacle then it is flipped to 0. Thus no paths are possible at all.
        obstacleGrid[0][0] ^= 1;
        
        // First row
        for(int i = 1; i < n; i++)
            obstacleGrid[0][i] = obstacleGrid[0][i] == 1 ? 0:obstacleGrid[0][i-1];
        
        // First column
        for(int i = 1; i < m; i++)
            obstacleGrid[i][0] = obstacleGrid[i][0] == 1 ? 0:obstacleGrid[i-1][0];
        
        // if an obstacle is present make it 0,else replace it with sum of left cell and right cell.
        for(int i = 1;i < m; i++)
            for(int j=1;j<n;j++)
                obstacleGrid[i][j] = obstacleGrid[i][j] == 1 ? 0 : obstacleGrid[i-1][j] + obstacleGrid[i][j-1];
        //return the final value,present at the corner end of the given matrix
        return obstacleGrid[m-1][n-1];

    }
};