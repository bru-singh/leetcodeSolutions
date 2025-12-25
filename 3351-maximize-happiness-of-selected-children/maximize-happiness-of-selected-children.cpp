class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long sum = 0;
        int curr = 0;
        sort(happiness.rbegin(), happiness.rend());
        for(auto it: happiness){
            sum += max(0, it-curr);
            curr++;
            k--;
            if(k==0)break;
        }
        return sum;
    }
};