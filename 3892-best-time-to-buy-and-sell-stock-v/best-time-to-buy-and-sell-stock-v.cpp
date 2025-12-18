class Solution {
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