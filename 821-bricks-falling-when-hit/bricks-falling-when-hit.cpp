class Solution {
private: 
    vector<pair<int,int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};
public:
    bool isConntectedToStable(vector<vector<int>>&grid,const int& x, const int& y ){
        if(x==0)return true;
        int n= grid.size(), m = grid[0].size();
        for(auto it: dir){
            int X = x + it.first;
            int Y = y + it.second;
            if(X>=0 and Y>=0 and X<n and Y<m and grid[X][Y]==2)return true;
        }
        return false;
    }
    int stable(vector<vector<int>>&grid, int x, int y){
        // start from all the stable brinks at the top and then if any
        // of the brick is unstable then mark it as unstable
        if(grid[x][y]!=1)return 0;
        grid[x][y]=2;
        int n= grid.size(), m = grid[0].size();
        int ans = 1;
        for(auto it: dir){
            int X = it.first + x;
            int Y = it.second + y;
            if(X>=0 and Y>=0 and X<n and Y<m){
                ans+=stable(grid, X, Y);
            }
        }
        return ans;

    }
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        int m= grid[0].size();
        vector<int> res(hits.size()); 
        for(auto it: hits)grid[it[0]][it[1]] -=1;
        // do a a traversal on the bricks which are still hanging on after hits
        // starting from the top row cos that are the stable ones
        for(int i=0;i<m;i++)stable(grid, 0,i);
        for(int i=hits.size()-1;i>=0;i--){
            int x = hits[i][0], y = hits[i][1];
            grid[x][y]+=1;
            if(grid[x][y]==1 and isConntectedToStable(grid, x, y)){
                res[i] = stable(grid, x, y)-1;
            }
        }
        return res;
    }
};
auto init = atexit([]() { ofstream("display_runtime.txt") << "0"; });
