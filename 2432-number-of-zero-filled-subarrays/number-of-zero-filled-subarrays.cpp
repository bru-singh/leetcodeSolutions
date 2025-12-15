class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        int count = 0;
        for(auto it: nums){
            if(it==0)count++;
            else count=0;
            ans+=count;
        }
        return ans;
    }
};