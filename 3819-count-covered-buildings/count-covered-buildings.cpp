class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        // we can have 4 vectors: 
        // row max and min
        // col max and min

        // and for all the houses between colMin to col Max, if there rowMax or rowMin! = house
        // mark them as closed and ans++
        vector<int> minRow(n+1,n+1), minCol(n+1,n+1);
        vector<int> maxRow(n+1,0), maxCol(n+1,0);
        for(auto building: buildings){
            int x = building[0], y = building[1];
            
            minRow[y]= min(minRow[y],x);
            maxRow[y]= max(maxRow[y],x);

            minCol[x]= min(minCol[x],y);
            maxCol[x]= max(maxCol[x],y);
        }
        int ans = 0;
        for(auto building: buildings){
            int x = building[0], y = building[1];
            bool xCover = x>minRow[y] && x<maxRow[y];
            bool yCover = y>minCol[x] && y<maxCol[x];
            ans += xCover&&yCover;
        }
        return ans;
    }
};