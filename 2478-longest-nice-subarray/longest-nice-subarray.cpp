class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        // if a set have a bitwise AND set to zero, it means there is no
        // 1 & 1 pair in the set for all the numbers. 
        // it means all the bits of all the number combined, 
        // appear atmax 1s.

        // brute force: check each subarray, and for each subarray check if
        // all the elements in that subarray have AND = 0 or not. 
        // return the maxLen;

        // better: check each subarray, and for each subarray, 
        // put the number in the bitwise hashSet, and if any count(bit)>1
        // return; else return maxLen;

        // optimized: maintain a bucket, and just add the number, if it doesnt
        // increase the count(bits) in the hashMap > 1 else keep removing
        // till the count(bits)<=1. return maxLen
        // tc: o(n), sc: o(30) ~ o(1)

        int n = nums.size();
        int bitHash = 0;
        int left = 0, right = 0;
        int maxLen = 0;
        while(right<n){
            while((bitHash&nums[right])!=0){
                // remove the left side
                // bitHash = a^b^c^d;
                // bitHash ^ a = b^c^d;
                bitHash= bitHash^nums[left];
                left++;
            }
            bitHash |= nums[right];
            maxLen = max(maxLen, right - left +1);
            right++;
        }
        return maxLen;

    }
};