class Solution {
public:
    int minSteps(string s, string t) {
        int n = s.size();
        vector<int> charHash(26,0);
        for(int i=0;i<n;i++){
            charHash[s[i]-'a']++;
            charHash[t[i]-'a']--;
        }
        int ans =0;
        for(int i=0;i<26;i++){
            if(charHash[i]>0)ans+=charHash[i];
        }
        return ans;
    }
};