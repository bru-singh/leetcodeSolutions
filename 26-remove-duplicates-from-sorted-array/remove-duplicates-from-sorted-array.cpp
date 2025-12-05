class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // if we use 2 pointers: curr and pos
        // 1. curr is same as pos
        //          curr++
        // 2. if it is diff: 
        //          pos++;
        //          set the num[pos] = num[curr]
        //          curr++;
        // pos+1 length

        int n = nums.size();
        int pos =0, curr = 1;
        while(curr<n){
            if(nums[curr]!=nums[pos]){
                pos++;
                nums[pos] = nums[curr];
            }
            curr++;
        }
        return pos+1;
        // tc: O(n)
        // sc: O(1)
    }
};