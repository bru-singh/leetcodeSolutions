class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int cnt =0;int i=0;
        int n= strs.size(), m = strs[0].size();
        vector<int> sorted(n-1, false);
        for(int j=0;j<m;j++){
            for( i=0;i<n-1;i++){
                if(!sorted[i] and strs[i][j]>strs[i+1][j]){
                    cnt++;
                    break;
                }
            }
            if(i<n-1)continue;
            for(i=0;i<n-1;i++){
                sorted[i] = sorted[i] || strs[i][j] <strs[i+1][j];
            }
        }
        return cnt;
    }
};