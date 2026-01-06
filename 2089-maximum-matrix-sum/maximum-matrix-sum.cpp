class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        long long smallest = INT_MAX, neg = 0;
        for(auto it: matrix){
            for(auto curr: it){
                sum+=abs(curr);
                smallest = min(smallest, 1ll*abs(curr));
                if(curr<0)neg++;
            }
        }
        if(neg%2)return sum - 2*smallest;
        return sum;
    }
};