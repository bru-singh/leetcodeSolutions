class Solution {
public:
    int lowerBound(vector<int>& nums, int target){
        int start = 0, end = nums.size()-1;
        int ans = 0;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(nums[mid]>=target){
                // potential ans
                ans = mid;
                end = mid-1;
            }
            else start = mid+1;
        }
        return ans;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        for(int i=0;i<n;i++){
            int indx = lowerBound(matrix[i], target);
            if(matrix[i][indx]==target)return true;
        }
        return false;
    }
};