#include<numeric>
class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        // basically we need to find the prefix, suffix and only move
        // and then decide the index i, where it is the most feasible to 
        // move down, and then mark everything till that index in the first row
        // as 0 and everything after that index, in the secodn row as 0

        // and then do the same for the second robot
        int n = grid[0].size();
        long long firstRow = accumulate(grid[0].begin(), grid[0].end(), 0ll);
        long long secondRow = 0, maxSum = LONG_MAX;
        for(int i=0;i<n;i++){
            firstRow -= grid[0][i];
            maxSum = min(maxSum, max(secondRow, firstRow));
            secondRow +=grid[1][i];
        }
        return maxSum;


    }
};