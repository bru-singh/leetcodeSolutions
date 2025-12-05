class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // brute force: 
        // check all the subarrays
        // check there sum and if the sumis equal to k
        // increment your ans, return ans;

        // better: 
        // precompte the sums in a prefix array
        // and check all the subarrays; 
        // the sum of the subarray (i,j) will be: 
        // prefix[j] - prefix[i]
        // if sum == k, ans ++; return ans;

        // prefix[j] - prefix[i] = k
        // prefix[j] = prefix[i] + k
        // ans = how many times does this prefix[j] for each i, exists
        int n = nums.size();
        unordered_map<int,int> hashMap;
        vector<int> prefixSum(n,0);
        prefixSum[0]= nums[0];
        for(int i=1;i<n;i++){
            prefixSum[i] = prefixSum[i-1] + nums[i];
        }
        int res = 0;
        for(int i=0;i<n;i++){
            // for each i, we need to check: 
            // if prefix[i] - nums[i] + k, exist, and if yes, how many times
            if(prefixSum[i]==k)res++;
            int val  = prefixSum[i] - k;
            res += hashMap[val];
            hashMap[prefixSum[i]]++;
        }
        return res;


    }
};