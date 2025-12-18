class Solution1 {
public:
    int maxProfit(int K, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(K+1, vector<int>( 2, 0)));
        // same as buy or sell stock III, but instead of atmost 2 we have atmost k
        // we are moving from: 
        // indx: 0->n, k: 0->K;
        for(int i=n-1;i>=0;i--){
            for(int k=1;k<=K;k++){
                // choice is 0 
                dp[i][k][0] = max(dp[i+1][k][0], -prices[i] + dp[i+1][k][1]);
                // choice is 1
                dp[i][k][1] = max(dp[i+1][k][1], prices[i] + dp[i+1][k-1][0]);
            }
        }

        return dp[0][K][0];
    }
};
// itirative approach from III, without dp
// so in III what we did was, we had buy1, buy2
// and p1 and p2
// and we wnated to maximise p2
// here instead of 2 we have K total transections, so we can have buy1, buy2,... buyk
// same p1, p2 ....pk
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<int> buy(k+1, INT_MAX);
        vector<int> profit(k+1, INT_MIN);
        profit[0] = 0;
        for(auto price: prices){
            for(int i=1;i<=k;i++){
                buy[i] = min(buy[i], price-profit[i-1]);
                profit[i] = max(profit[i], price-buy[i]);
            }
        }

        return profit[k];
    }
};