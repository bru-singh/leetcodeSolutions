class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.size();
        vector<int> charHash(26,0);
        for(auto ch:s)charHash[ch-'a']++;
        for(int i=0;i<n;i++){
            if(charHash[s[i]-'a']==1)return i;
        }
        return -1;


    }
};