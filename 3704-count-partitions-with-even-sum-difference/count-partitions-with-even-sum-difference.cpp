class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixSum (n,0);
        prefixSum[0]=nums[0];
        for(int i=1;i<n;i++){
            prefixSum[i]=prefixSum[i-1]+nums[i];
        }
        int res= 0;
        for(int i=0;i<n-1;i++){
            int leftSum = prefixSum[i];
            int rightSum = prefixSum[n-1] - prefixSum[i];
            int diff = abs(leftSum - rightSum)%2;
            if(!diff)res++;
        }
        return res;
    }
};