class Solution {
public:
    int mod = 1e9+7;
    int specialTriplets(vector<int>& nums) {
        unordered_map<int,int> leftCount, rightCount;
        int n = nums.size();
        for(int i=n-1;i>=0;i--)rightCount[nums[i]]++;
        long long res = 0;
        for(int i=0;i<n;i++){
            rightCount[nums[i]]--;
            int specialNum = 2*nums[i];
            long long left = leftCount[specialNum]%mod;
            long long right = rightCount[specialNum]%mod;
            res += 1ll*((left%mod)*(right%mod))%mod;
            leftCount[nums[i]]++;
        }
        return res%mod;
    }
};