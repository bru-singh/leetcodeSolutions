class Solution {
public:
    int mod = 1e9+7;
    int countPermutations(vector<int>& complexity) {
        // first one is always the root i =0;
        // to unlock:
        // 1. for any index i, to unlock it we can unloack it with
        // a previous index which have the lower complexity

        // find the permutation of indexes which result in the value ans

        // in the initial seq only the first element is unlocked. 
        
        // we need to check if the first element is minimum or not, 
        // and fix that as the first element, 
        // and then for the remaining 1 to n-1 element, 
        // the answer will be: 1 to n-1 => (n-1)!
        int first = complexity[0];
        int n  = complexity.size();
        long long ans =1;
        for(int i=1;i<n;i++){
            if(complexity[i]<=first)return 0;
            ans = (ans*i)%mod;
        }
        return ans;
    }
};