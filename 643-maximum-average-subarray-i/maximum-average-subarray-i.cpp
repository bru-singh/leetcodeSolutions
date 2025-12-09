class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int maxSum = 0, sum =0;
        int n = nums.size();
        int left = 0;
        for(int i=0;i<k;i++)sum+=nums[i];
        maxSum = sum;
        for(int i=k;i<n;i++){
            sum-=nums[left];
            sum+=nums[i];
            left++;
            maxSum = max(sum, maxSum);
        }
        double res = (double)maxSum/k;
        return res;
    }
};