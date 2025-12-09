class Solution {
public:
    int trap(vector<int>& height) {
        // if any indexc i, is not the max height so far, 
        // either from left or right, then it will store water
        // and the water stored = min(leftMax, rightMax)-currHeight
        // this much block of water will be there at the index i

        // basically at each index, we need to find the next greatest height
        // on the right and prev greatest height on the left. 

        // after that the problem becomes simple: 
        // at each index totalWater += min(prevHieght, nextHeight) - currHeight;
        // return totalWater;

        int n=height.size();
        int totalWater = 0;
        vector<int> prevHeights(n,0), nextHeights(n,0);
        int maxSoFar = 0;
        for(int i=0;i<n;i++){
            maxSoFar = max(maxSoFar, height[i]);
            prevHeights[i]=maxSoFar;
        }
        maxSoFar=0;
        for(int i=n-1;i>=0;i--){
            maxSoFar = max(maxSoFar, height[i]);
            nextHeights[i]=maxSoFar;
        }
        // since for index 1 and n, we can not store the water at all
        for(int i=1;i<n-1;i++){
            int currHeight = height[i];
            totalWater += min(prevHeights[i], nextHeights[i])-currHeight;
        }
        return totalWater;

    }
};