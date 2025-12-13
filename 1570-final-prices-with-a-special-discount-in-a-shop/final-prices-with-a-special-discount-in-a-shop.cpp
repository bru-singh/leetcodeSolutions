class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        // basically we need to find the next smallest element
        // if we follow the brute force method: we can say that,
        // for each of the index i, check from i to n, and then 
        // if you find the smallest element append it's value to ans.
        // tc: o(n^2)

        // optimized way will be to find the next smallest element after the current index
        int n = prices.size();
        stack<int> st;
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() and st.top()>prices[i])st.pop();
            int discount = st.empty()? 0: st.top();
            ans[i]=prices[i]-discount;
            st.push(prices[i]);
        }
        return ans;
    }
};