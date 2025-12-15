class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> hashMap;
        int n = nums2.size();
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            // this is for next greater 
            while(!st.empty() and st.top()<nums2[i])st.pop();
            if(st.empty())hashMap[nums2[i]]=-1;
            else hashMap[nums2[i]]=st.top();
            st.push(nums2[i]);
        }
        vector<int> ans;
        for(auto it: nums1){
            ans.push_back(hashMap[it]);
        }
        return ans;
    }
};