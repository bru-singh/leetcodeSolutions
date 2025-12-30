class Solution {
public:
    int itsMagic(vector<vector<int>>& grid, int x, int y){
        // properties: 
        // it should have all the numbers 1 to 9
        // each row, col and diagonal should have same sum
        vector<int> count(10,0);
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                int num = grid[x+i][y+j];
                if(num<1 or num>9 or count[num]!=0)return 0;
                count[num]++;
            }
        }
        // row check 
        int rowSum = grid[x][y] + grid[x][y+1] + grid[x][y+2];
        int colSum = grid[x][y] + grid[x+1][y] + grid[x+2][y];
        int diaSum = grid[x][y] + grid[x+1][y+1] +grid[x+2][y+2];
        for(int i=1;i<3;i++){
            if(rowSum != grid[x+i][y] + grid[x+i][y+1] + grid[x+i][y+2])
                return 0;
            if(colSum != grid[x][y+i] + grid[x+1][y+i] + grid[x+2][y+i])
                return 0;
        }
        if(diaSum != grid[x+2][y] + grid[x+1][y+1] + grid[x][y+2])return 0;
        if(rowSum == colSum and rowSum == diaSum)return 1;
        return 0;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        if(n<3 or m<3)return 0;
        for(int i=0;i<n-2;i++){
            for(int j=0;j<m-2;j++)ans+=itsMagic(grid, i, j);
        }
        return ans;
    }
};