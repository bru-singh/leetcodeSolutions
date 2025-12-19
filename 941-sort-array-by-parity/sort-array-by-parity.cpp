class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int left = 0, right = 0;
        int n = nums.size();
        while(right<n){
            if(nums[right]%2==0){
                swap(nums[left], nums[right]);
                left++;
            }
            right++;
        }
        return nums;
    }
};