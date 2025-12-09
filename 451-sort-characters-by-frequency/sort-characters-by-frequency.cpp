class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        unordered_map<char,int> hashMap;
        vector<string> bucket(n+1,"");
        for(auto ch: s)hashMap[ch]++;
        for(auto &it : hashMap){
            int count = it.second;
            int ch = it.first;
            bucket[count].append(count, ch);
        }
        string ans;
        for(int i=n;i>=0;i--){
            if(!bucket[i].empty())ans+=bucket[i];
        }
        return ans;
    }
};