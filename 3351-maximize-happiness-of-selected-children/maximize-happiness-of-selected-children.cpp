class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        // long long sum = 0;
        // int curr = 0;
        // sort(happiness.rbegin(), happiness.rend());
        // for(auto it: happiness){
        //     sum += max(0, it-curr);
        //     curr++;
        //     k--;
        //     if(k==0)break;
        // }
        // return sum;

        // can also do it using max heap 
        long long sum = 0;
        int n = happiness.size(), curr =0;
        priority_queue<long long> pq;
        for(int i=0;i<n;i++)pq.push(happiness[i]);
        for(int i=0;i<k;i++){sum+=max(pq.top()-curr, 0ll);pq.pop();curr++;}
        return sum;
    }
};