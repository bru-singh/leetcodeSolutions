class Solution1 {
public:
    // choice: 
    // 0: transaction complete: can do both buy or sell. 
    // 1: prev buy, you can only sell or skip 
    // 2: prev sell, you can only buy or skip

    // chaing things: 
    // indx, choice and k
    // dp[indx][k][choice]

    long long dp[1001][501][3];
    long long mn = -1e14;
    long long recc(vector<int>& prices, int indx, int choice, int k){
        if(indx==prices.size()){
            if(choice == 0){
                return 0;
            }
            return mn;
        }
        if(dp[indx][k][choice]!=mn)return dp[indx][k][choice];
        
        long long profit = -1e14;
        profit = max(profit, recc(prices, indx+1, choice, k));
        if(choice == 0){
            profit = max(profit, max(
                        -prices[indx] + recc(prices, indx+1, 1, k), 
                        prices[indx] + recc(prices, indx+1, 2, k)));
        }
        else if(k>0){
            if(choice == 1){
                profit = max(profit, 
                prices[indx] + recc(prices, indx+1, 0, k-1));
            }
            else if(choice == 2){
                profit = max(profit, 
                -prices[indx] + recc(prices, indx+1, 0, k-1));
            }
        }
        return dp[indx][k][choice]= profit;
    }
    long long maximumProfit(vector<int>& prices, int k) {
        // at each point, for eadch index we have two point: 
        // do not do anything
        // short sell or buy ->
        // 1. if buy, only can sell in the future
        // 2. if sell, only can buy in the future
        // we can proceed recursivily in this and process each of the prices.
        int n= prices.size();
        for(int i=0;i<n+1;i++){
            for(int j=0;j<k+1;j++){
                for(int choice = 0; choice<3;choice++){
                    dp[i][j][choice]=-1e14;
                }
            }
        }
        return recc(prices, 0, 0, k);
    }
};
// bottoms up approach
class Solution {
public:
    // choice: 
    // 0: transaction complete: can do both buy or sell. 
    // 1: prev buy, you can only sell or skip 
    // 2: prev sell, you can only buy or skip

    // chaing things: 
    // indx, choice and k
    // dp[indx][k][choice]
    long long maximumProfit(vector<int>& prices, int K) {
        // at each point, for eadch index we have two point: 
        // do not do anything
        // short sell or buy ->
        // 1. if buy, only can sell in the future
        // 2. if sell, only can buy in the future
        // we can proceed recursivily in this and process each of the prices.
        int n= prices.size();
        long long dp[n+1][K+1][3];
        // base case: 
        // dp[n][k][0] = 0;
        // dp[n][k][1] or dp[n][k][2]=-1e14;
        for(int i=0;i<=K;i++){
            dp[n][i][0]=0;
            dp[n][i][1]= -1e14;
            dp[n][i][2]= -1e14;
        }
        for(int i=n-1;i>=0;i--){
            for(int k=0;k<=K;k++){
                // dont take
                dp[i][k][0] = dp[i+1][k][0];
                // choice 0
                if(k>0){
                    dp[i][k][0] = max(dp[i][k][0],
                                    max( 
                                        -prices[i] + dp[i+1][k][1], 
                                        prices[i] + dp[i+1][k][2]
                                        )
                                    );
                }
                // dont take
                dp[i][k][1] = dp[i+1][k][1];
                // choice 1
                if(k>0){
                    dp[i][k][1]=max(dp[i][k][1],prices[i] + dp[i+1][k-1][0]);
                }
                // dont take 
                dp[i][k][2] = dp[i+1][k][2];
                // choice 2
                if(k>0){
                    dp[i][k][2] = max(dp[i][k][2], -prices[i] + dp[i+1][k-1][0]);
                }
            }
        }
        return dp[0][K][0];
    }
};