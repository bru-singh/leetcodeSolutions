class Solution {
public:
    int maximumLength(string s) {
        // BRUTE FORCE: 
        // basically for each special substring, we can check how many tiems 
        // they appear in the string s.
        // store it in the hashmap and then return the maxlen for those
        // who occure mroe than 3

        // int n = s.size();
        // tc: o(n^2)
        // but will work cos n<=50
        // unordered_map<string,int> hashMap;
        // int maxLen = -1;
        // for(int i=0;i<n;i++){
        //     string curr = "";
        //     for(int j=i;j<n;j++){
        //         if(curr.empty() or curr.back()==s[j]){
        //             curr+=s[j];
        //             hashMap[curr]++;
        //         }
        //         else break;
        //     }
        // }
        // for(auto it: hashMap){
        //     if(it.second>=3)
        //         maxLen = max(maxLen,static_cast<int>(it.first.size()));
        // }
        // return maxLen;

        // OPTIMIZED: 
        // refer to this video: make a 2D table of startChar, len. 
        // take the cumelative sum as: hashTable[char][len] += hashTable[char][len+1];
        // https://www.youtube.com/watch?v=fDUPCtPqzss

        int n = s.size();
        vector<vector<int>> hashTable(26, vector<int> (n+1,0));
        char prev = '1';
        int len = 0;
        int maxLen = -1;
        for(int i=0;i<n;i++){
            if(prev=='1' or s[i]==prev)len++;
            else len = 1;
            hashTable[s[i]-'a'][len]++;
            prev = s[i];
        }
        for(int i=0;i<26;i++){
            int cumSum = 0;
            for(int j=n;j>=1;j--){
                cumSum += hashTable[i][j];
                if(cumSum>=3){
                    maxLen = max(maxLen,j);
                    break;
                }
            }
        }
        return maxLen;


    }
};