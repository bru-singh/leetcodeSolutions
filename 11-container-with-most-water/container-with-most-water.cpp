class Solution {
public:
    int maxArea(vector<int>& height) {
        // by going through the example: 
        // we can see that at any point, the water stored in the container
        // depends on two things: the distance between the two walls
        // and the min height between the two walls
        
        // maxWater = min(height[i], height[j])*(j-i+1);
        // we can maximise this value, by 1: maximising the distance j-i+1;
        // or we can maximise this value by maximising the min height;

        // so let's do that; we start from the start and the end( maximum distance)
        // and we only move the height which is shroter because =>
        // 1. there might be chance of getting a larger height next
        // if we get a largest value: our prev large hight will be min -> increase the capacity
        // else we will anyways store the value in maxWater anwyays

        int n = height.size();
        int left = 0, right = n-1;
        int maxWater =0 ;
        while(left<right){
            int currWater = min(height[left], height[right])*(right-left);
            maxWater  = max(maxWater, currWater);
            if(height[left]<=height[right])left++;
            else right--;
        }
        return maxWater;
    }
};