class Solution {
public:
    int votingAlgo(vector<int>&nums){
        int n = nums.size();
        if(nums[0]==nums[1] or nums[0]==nums[2])return nums[0];
        if(nums[1]==nums[2])return nums[1];
        int curr = -1, cnt = 0;
        for(int i=3;i<n;i++){
            if(cnt==0){
                curr=nums[i];
                cnt+=1;
            }
            else if(curr == nums[i])cnt+=1;
            else if(curr != nums[i])cnt-=1;
        }
        return curr;
    }
    int repeatedNTimes(vector<int>& nums) {
        // in voting algorithm we can find a elemnet which repeats more
        // than n/2 times in a n size array
        // but here we have n unique elements and 1 element which repeats n times
        // which is exactly half time
        // if we check the first three elements, if we have any repating char
        // there or not, and more forward: 
        // if we have a repeat in the first three, return that
        // else: 
        // we will have 2n-3 elements and then the repeating int will be
        // present more than half times for sure, so we can use the moore
        // voting algorithm
        return votingAlgo(nums);

    }
};