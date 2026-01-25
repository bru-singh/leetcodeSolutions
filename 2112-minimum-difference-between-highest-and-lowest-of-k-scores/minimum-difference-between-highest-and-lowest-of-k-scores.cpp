class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        k--;
        sort(nums.begin(), nums.end());
        int ans = INT_MAX, n = nums.size();
        for(int i=k;i<n;i++){
            ans = min(ans, nums[i]-nums[i-k]);
        }
        return ans;
    }
};