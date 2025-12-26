class Solution {
public:
    long long minDamage(int power, vector<int>& damage, vector<int>& health) {
        for(auto &h: health)h= ceil((double)h/(1.0*power));
        vector<pair<int,int>> arr; 
        for(int i=0;i<damage.size();i++)arr.push_back({damage[i], health[i]});
        sort(arr.begin(), arr.end(), [](pair<int,int> &a, pair<int,int> &b){
            // sum1= a.first/a.second;
            // sum2= b.first/b.second;
            // sum1>sum2;
            // a.first/a.second > b.first/b.second
            // a.first * b.second > b.first * a.second;
            long long  x= a.first*1ll*b.second;
            long long y= b.first*1ll*a.second;
            return x>y;
        });
        long long sum = 0;
        long long days = 0;
        for(int i=0;i<arr.size();i++){
            days +=arr[i].second;
            sum+= arr[i].first*(days);
        }
        return sum;

    }
};