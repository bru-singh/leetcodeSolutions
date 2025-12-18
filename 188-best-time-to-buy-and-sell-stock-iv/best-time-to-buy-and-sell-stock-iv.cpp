class Solution {
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