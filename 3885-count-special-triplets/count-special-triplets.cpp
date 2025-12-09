class Solution {
private:
static const int m = 1e5+1;
int mod = 1e9+7;
int leftCount[m], rightCount[m];
public:
    int specialTriplets(vector<int>& nums) {
        memset(leftCount, 0 , sizeof(leftCount));
        memset(rightCount, 0 , sizeof(rightCount));
        int n = nums.size();
        for(int i=n-1;i>=0;i--)rightCount[nums[i]]++;
        long long res = 0;
        for(int i=0;i<n;i++){
            rightCount[nums[i]]--;
            int specialNum = 2*nums[i];
            if(specialNum>m){
                leftCount[nums[i]]++;
                continue;
            }
            int left = leftCount[specialNum]%mod;
            int right = rightCount[specialNum]%mod;
            res = (res + (1ll*left*right)%mod)%mod;
            leftCount[nums[i]]++;
        }
        return res%mod;
    }
};