class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        // basically if i have to put this question in another way,
        // i can say that, 
        // we have a array of positive numbers, and we want to
        // find the maxSum of a subarray where all the elemetns are unique

        // eg: nums = [1,2,3,4,5,6,6,1]: ans => [1,2,3,4,5,6]
        
        // brute force: check all the subarrays and store the one w maxSum
        // tc: o(n^3)

        // precompute the prefix sum, and check all the subarrays and return maxSum
        // also check if we have any repeating char or not. 
        // tc: o(n^2) and sc: o(n)

        // we can maintain a window bucket, and then move over the array, 
        // reduce the bucket anytime we have a repating number. Keep track of the
        // maxSum and return maxSum.

        int n = nums.size();
        int left = 0, right = 0;
        int maxSum = 0;
        int sum = 0;
        unordered_set<int> hashSet;
        while(right<n){
            // include the curr num
            sum+=nums[right];
            while(hashSet.find(nums[right])!=hashSet.end()){
                sum-=nums[left];
                hashSet.erase(nums[left]);
                left++;
            }
            maxSum = max(maxSum, sum);
            hashSet.insert(nums[right]);
            right++;
        }
        return maxSum;
    }
};