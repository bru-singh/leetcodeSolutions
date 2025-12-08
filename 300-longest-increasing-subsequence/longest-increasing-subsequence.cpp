class Solution {
public:
    // int recc(vector<int>& nums, int indx, int prev, vector<vector<int>> &dp){
    //     if(indx==nums.size())return 0;
    //     if(prev !=-1 and dp[indx][prev]!=-1)return dp[indx][prev];
    //     int curr = nums[indx];
    //     int include=0, notInclude;
    //     if(prev == -1 or curr>nums[prev]){
    //         include = max(recc(nums, indx+1, prev,dp), 1+recc(nums, indx+1, indx,dp));
    //     }
    //     notInclude = recc(nums, indx+1, prev, dp);
    //     if(prev ==-1)return max(include, notInclude);
    //     return dp[indx][prev] = max(include, notInclude);
    // }
    int lengthOfLIS(vector<int>& nums) {
        // int n = nums.size();
        // // vector<vector<int>> dp(n+1, vector<int>(n,-1));
        // // int ans = recc(nums, 0,-1, dp);
        // vector<int> dp(n+1,0);
        // dp[0]=1;
        // for(int i=1;i<n;i++){
        //     int maxLen = 0;
        //     for(int j=0;j<i;j++){
        //         if(nums[j]<nums[i])maxLen = max(maxLen, dp[j]);
        //     }
        //     dp[i] = 1 + maxLen;
        // }
        // return *max_element(dp.begin(), dp.end());

        int n = nums.size();
        vector<int> currNums; 
        for(auto num: nums){
            if(currNums.empty() or currNums.back()<num){
                currNums.push_back(num);
            }
            else{
                auto it = lower_bound(currNums.begin(), currNums.end(), num) - currNums.begin();
                currNums[it] = num;
            }
        }
        return currNums.size();
    }
};