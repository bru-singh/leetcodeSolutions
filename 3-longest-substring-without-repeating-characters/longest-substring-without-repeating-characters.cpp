class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Q: can the string have mroe than jsut english characters?
        // if yes, do we treat them as uniqye characters or we need to do some preprocessing
        // on the string to only consider the eng characters

        int n = s.size();
        int left = 0, right = 0;
        int maxLen = 0;
        vector<int> charHash(256,0);
        while(right<n){
            // choose the right element
            charHash[s[right]]++;
            while(charHash[s[right]]>1){
                charHash[s[left]]--;
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
            right++;
        }
        return maxLen;
    }
};