class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        int count = 1;
        int i=1;
        long long ans = 0;
        while(i<n){
            if(prices[i]==prices[i-1]-1){
                count++;
            }
            else{
                ans+= 1ll*count*(count+1)/2;
                count=1;
            }
            i++;
        }
        ans+= 1ll*count*(count+1)/2;
        return ans;
    }
};