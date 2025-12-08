class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        // BRUTE FORCE: 
        // unordered_set<int> hashSet;
        // for(auto num: nums)hashSet.insert(num);
        // int uniqueNum = hashSet.size();
        // int n = nums.size();
        // int count =0 ;
        // // the goal is the find the numebr of subarrays
        // // with k distinct elements
        // for(int i=0;i<n;i++){
        //     hashSet.clear();
        //     for(int j=i;j<n;j++){
        //         hashSet.insert(nums[j]);
        //         if(hashSet.size()==uniqueNum){
        //             count += n-j;
        //             break;
        //         }
        //     }
        // }
        // return count;

        // OPTIMIZED: Sliding Window: 
        unordered_set<int> hashSet;
        vector<int> hashMap(20001,0);
        for(auto num: nums)hashSet.insert(num);
        int uniqueNum = hashSet.size();
        int n = nums.size();
        int count =0 ;
        int left = 0, right = 0;
        hashSet.clear();
        while(right<n){
            // include right;
            hashSet.insert(nums[right]);
            hashMap[nums[right]]++;
            while(hashSet.size()==uniqueNum){
                count += n-right;
                hashMap[nums[left]]--;
                if(hashMap[nums[left]]==0)hashSet.erase(nums[left]);
                left++;
            }
            right++;
        }
        return count;
    }
};