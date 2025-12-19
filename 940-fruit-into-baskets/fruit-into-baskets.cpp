class Solution {
public:
    int solve(vector<int>&nums, int i){
        unordered_set<int> st;
        int val = 0;
        for(int indx = i;indx<nums.size();indx++){
            st.insert(nums[indx]);
            if(st.size()>2)break;
            val++;
        }
        return val;
    }
    int totalFruit(vector<int>& fruits) {
        // so basically we can take only 2 types of fruits
        // go from left to right
        int maxVal = 0;
        int n = fruits.size();
        // we can use sliding window here: 
        int right = 0, left = 0;
        unordered_map<int, int> mp;
        while(right<n){
            // include right
            mp[fruits[right]]++;
            while(mp.size()>2 ){
                if(--mp[fruits[left]]==0)mp.erase(fruits[left]);
                left++;
            }
            maxVal = max(maxVal, right -left+1);
            right++;
        }
        return maxVal;
    }
};