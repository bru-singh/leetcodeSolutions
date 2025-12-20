class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int cnt =0;
        int n= strs.size(), m = strs[0].size();
        for(int i=0;i<m;i++){
            for(int j = 1;j<n;j++){
                char curr = strs[j][i];
                char prev = strs[j-1][i];
                if(curr<prev){
                    cnt++;break;
                }
            }
        }
        return cnt;
    }
};