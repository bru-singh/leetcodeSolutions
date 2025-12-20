class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int cnt =0;
        int n= strs.size(), m = strs[0].size();
        for(int i=0;i<m;i++){
            string s, t; 
            for(int j = 0;j<n;j++){
                s+=strs[j][i];
            }
            t=s;
            sort(t.begin(), t.end());
            if(t!=s)cnt++;
        }
        return cnt;
    }
};