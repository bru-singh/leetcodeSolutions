class Solution {
public:
    int mod = 1e9+7;
    int numberOfWays(string corridor) {
        int count = 0;
        int prevIndx =-1;
        long long ans =1;
        int n = corridor.size();
        for(int i=0;i<n;i++){
            if(corridor[i]=='S'){
                count++;
                if(prevIndx!=-1){
                    ans=(ans*1ll*(i-prevIndx)%mod)%mod;
                    prevIndx=-1;
                }
            }
            if(count==2){
                prevIndx=i;
                count=0;
            }
        }
        if(prevIndx==-1)return 0;
        return ans;

    }
};