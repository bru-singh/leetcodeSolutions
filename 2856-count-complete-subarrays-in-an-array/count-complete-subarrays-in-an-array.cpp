class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> hashSet;
        for(auto num: nums)hashSet.insert(num);
        int uniqueNum = hashSet.size();
        int n = nums.size();
        int count =0 ;
        // the goal is the find the numebr of subarrays
        // with k distinct elements
        for(int i=0;i<n;i++){
            hashSet.clear();
            for(int j=i;j<n;j++){
                hashSet.insert(nums[j]);
                if(hashSet.size()==uniqueNum){
                    count += n-j;
                    break;
                }
            }
        }
        return count;
    }
};