class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans =0, n = points.size();
        int prev_x = points[0][0], prev_y = points[0][1];
        for(int i=1;i<n;i++){
            int x_dist = abs(points[i][0]-prev_x), y_dist = abs(points[i][1]-prev_y);
            ans+= min(x_dist, y_dist);
            ans+=max(x_dist,y_dist) - min(x_dist, y_dist);
            prev_x = points[i][0], prev_y = points[i][1];
        }
        return ans;
    }
};