#include<numeric>
class Solution {
public:
    vector<int> countingSort(vector<int>&capacity){
        int n = capacity.size();
        int sum = accumulate(capacity.begin(), capacity.end(),0);
        vector<int> counting(sum+1), ans(n);
        for(int i=0;i<n;i++)counting[capacity[i]]++;
        for(int i=0;i<sum;i++)counting[i+1]+=counting[i];
        for(int i=n-1;i>=0;i--){
            ans[counting[capacity[i]]-1]= capacity[i];
            counting[capacity[i]]--;
        }
        return ans;
    }
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        // int sum = 0, ans =0; 
        // for(auto it: apple)sum+=it;
        // sort(capacity.rbegin(), capacity.rend());
        // for(auto it: capacity){
        //     sum-=it;
        //     ans++;
        //     if(sum<=0)return ans;
        // }
        // return -1;

        // we can do this linearly as well by using counting sort 
        // since the range is small only till 50
        int sum =0, ans = 0;
        for(auto it: apple)sum+=it;
        vector<int> sorted = countingSort(capacity);
        for(int i=sorted.size()-1;i>=0;i--){
            sum-=sorted[i];ans++;
            if(sum<=0)break;
        }
        return ans;
    }
};