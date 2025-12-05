class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int pos = 0, curr = 0;
        while(curr<n){
            if(nums[curr]!=0){
                swap(nums[curr], nums[pos]);
                pos++;
            }
            curr++;
        }
        // tc: O(n)
        // sc: O(1)
    }
};