class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for(int i=0;i<n;i++){
            int j=0;
            for(j = 0;j<m;j++){
                if(grid[i][j]<0)break;
            }
            ans+=m-j;
        }
        return ans;
    }
};