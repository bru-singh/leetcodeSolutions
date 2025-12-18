class Solution1 {
public:
    // choices: 
    // 0: no pngoing transactions we can start a new transaction
    // 1: an ongoing transection going on, only can sell or skip

    // changing: 
    // indx, choice, k 
    int dp[100001][3][3];
    int recc(vector<int>&prices, int indx, int choice, int k){
        if(indx==prices.size())return 0;
        if(dp[indx][choice][k]!=-1e9)return dp[indx][choice][k];

        // each day we can do:
        // skip
        int not_take = recc(prices, indx+1, choice, k);
        // not skip: 
        // 1. sell ( if baught before )
        int sell = -1e9,buy = -1e9;
        if(k>0 and choice==1)sell = prices[indx] + recc(prices, indx+1, 0, k-1);
        // 2. buy (if no transection)
        if(choice == 0 )buy = -prices[indx] + recc(prices, indx+1, 1, k);
        return dp[indx][choice][k] = max(max(buy, sell), not_take);
    }
    int maxProfit(vector<int>& prices) {
        // at any index, we have the choices: 
        // if choice == 0:
        // 1. skip the index
        // 2. buy at this index, and set the choice to 1
        // if choice == 1;
        // 1. sell at this index
        for(int i=0;i<prices.size();i++){
            dp[i][0][0]=-1e9;dp[i][0][1]=-1e9;dp[i][0][2]=-1e9;
            dp[i][1][0]=-1e9;dp[i][1][1]=-1e9;dp[i][1][2]=-1e9;
            dp[i][2][0]=-1e9;dp[i][2][1]=-1e9;dp[i][2][2]=-1e9;
        }
        return recc(prices, 0,0,2);
    }
};

// iterative solution: 
class Solution {
public:
    // choices: 
    // 0: no pngoing transactions we can start a new transaction
    // 1: an ongoing transection going on, only can sell or skip

    // changing: 
    // indx, choice, k 
    int dp[100001][3][3];
    int recc(vector<int>&prices, int indx, int choice, int k){
        if(indx==prices.size())return 0;
        if(dp[indx][choice][k]!=-1e9)return dp[indx][choice][k];

        // each day we can do:
        // skip
        int not_take = recc(prices, indx+1, choice, k);
        // not skip: 
        // 1. sell ( if baught before )
        int sell = -1e9,buy = -1e9;
        if(k>0 and choice==1)sell = prices[indx] + recc(prices, indx+1, 0, k-1);
        // 2. buy (if no transection)
        if(choice == 0 )buy = -prices[indx] + recc(prices, indx+1, 1, k);
        return dp[indx][choice][k] = max(max(buy, sell), not_take);
    }
    int maxProfit(vector<int>& prices) {
        // at any index, we have the choices: 
        // if choice == 0:
        // 1. skip the index
        // 2. buy at this index, and set the choice to 1
        // if choice == 1;
        // 1. sell at this index
        int n = prices.size();
        int dp[n+1][3][2];
        memset(dp, 0, sizeof(dp));
        // we are moving from: 
        // indx: 0->n, k: 0->2;
        for(int i=n-1;i>=0;i--){
            for(int k=1;k<=2;k++){
                // choice is 0 
                dp[i][k][0] = max(dp[i+1][k][0], -prices[i] + dp[i+1][k][1]);
                // choice is 1
                dp[i][k][1] = max(dp[i+1][k][1], prices[i] + dp[i+1][k-1][0]);
            }
        }

        return dp[0][2][0];
    }
};