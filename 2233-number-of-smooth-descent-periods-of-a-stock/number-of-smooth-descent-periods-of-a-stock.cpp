class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        int count = 1;
        int i=1;
        long long ans = 1;
        while(i<n){
            if(prices[i]==prices[i-1]-1){
                count++;
            }
            else{
                count=1;
            }
            ans+=count;
            i++;
        }
        // if(count==1)ans+= 1ll*count*(count+1)/2;
        return ans;
    }
};