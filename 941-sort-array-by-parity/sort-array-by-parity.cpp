class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int left = 0, right = 0;
        int n = nums.size();
        while(right<n){
            // if(nums[right]%2==0){
            // use bitmask instead for faster computation
            if((nums[right]&0x1)==0){
                swap(nums[left], nums[right]);
                left++;
            }
            right++;
        }
        return nums;
    }
};