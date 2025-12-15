class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        // brute force will be for each of the i and j, find a k. 
        // more optimzied way will be:
        // find two numbers i and j, such that we have i = min, j = max
        // and then find a k in the range j to n-1;

        // int n=nums.size();
        // int mn = INT_MAX;
        // for(int i=0;i<n;i++){
        //     mn = min(mn, nums[i]);
        //     if(mn==nums[i])continue;
        //     // else for the min, and curr(j) and k 
        //     for(int k=i+1;k<n;k++){
        //         if(nums[k]>mn and nums[k]<nums[i])return true;
        //     }
        // }

        // 132 pattern: 2-> k, 3-> j, 1->i ( s1, s2, s3)
        // your stack will take care of the 32 pattern and then we need to iterate over the array
        // to find the 1. 
        int s2= INT_MIN;
        stack<int> st; // this will be nse
        int n= nums.size();
        // we are iterating over the peak(j) i.e s3

        for(int i=n-1;i>=0;i--){
            // if the current elemnet is smaller than s2, it means we have found the pattern
            // as the stack is gonna take care if the rest 32 pattern
            if(nums[i]<s2)return true;
            int s3 = nums[i];
            // nse
            while(!st.empty() and s3>st.top()){
                s2=st.top();
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};