class Solution {
public:
    int maximumLength(string s) {
        // basically for each special substring, we can check how many tiems 
        // they appear in the string s.
        // store it in the hashmap and then return the maxlen for those
        // who occure mroe than 3
        int n = s.size();
        // tc: o(n^2)
        // but will work cos n<=50
        unordered_map<string,int> hashMap;
        int maxLen = -1;
        for(int i=0;i<n;i++){
            string curr = "";
            for(int j=i;j<n;j++){
                if(curr.empty() or curr.back()==s[j]){
                    curr+=s[j];
                    hashMap[curr]++;
                }
                else break;
            }
        }
        for(auto it: hashMap){
            if(it.second>=3)
                maxLen = max(maxLen,static_cast<int>(it.first.size()));
        }
        return maxLen;
    }
};