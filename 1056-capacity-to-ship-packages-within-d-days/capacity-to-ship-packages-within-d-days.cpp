class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        // so ship capactiy can be 1, 2 , 3 ,4 , 5, 6
        // day1 we load x1+ x2+ x3+ x4+ x5... <=cap
        // days = day1 + day2 + day3.....
        int left=0, right =0;
        for(auto &w: weights){
            left = max(left, w);
            right+=w;
        }
        int ans = 0;
        while(left<=right){
            int mid = left + (right-left)/2;
            int sum=0, cnt=1;
            for(auto &w: weights){
                if(sum+w>mid){
                    cnt++;sum=0;
                }
                sum+=w;
            }
            // this works, lets check more
            if(cnt<=days){
                ans =mid;
                right = mid-1;
            }
            else left =mid+1;
        }
        return ans;
    }
};