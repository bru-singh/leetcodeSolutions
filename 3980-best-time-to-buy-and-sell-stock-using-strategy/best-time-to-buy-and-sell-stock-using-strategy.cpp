class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        // take the bucket of len k
        // if we are moving forward: 
        // add the new element to the currSum, 
        // remove the k/2th element from the summ
        // store the maxSum = max(maxSum, currSum);
        int n = prices.size();
        long long maxSum = 0, currSum = 0;
        vector<long long> prefix(n+1,0), suffix(n+1,0);
        for(int i=0;i<n;i++){
            maxSum += (long long)strategy[i]*prices[i];
            prefix[i+1] = prefix[i] + 1ll*strategy[i]*prices[i];
        }
        for (int i=n-1;i>=0;i--)suffix[i] = suffix[i+1] + 1ll*strategy[i]*prices[i];
        int right = k,left = 0,mid = k/2;
        for(int i=mid;i<right;i++)currSum +=prices[i];
        maxSum = max(maxSum, currSum + suffix[right] + prefix[left]);
        while(right<n){
            // remove the mid,add the right, move the righ, calculate the max
            currSum -=prices[mid];
            currSum +=prices[right];
            left++;mid++;right++;
            maxSum = max(maxSum, currSum + suffix[right] + prefix[left]);
        }
        return maxSum;
    }
};