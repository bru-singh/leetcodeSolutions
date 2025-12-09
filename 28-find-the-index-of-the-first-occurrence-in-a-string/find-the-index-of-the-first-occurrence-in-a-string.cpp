class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size()==0)return 0;
        if(needle.size()>haystack.size())return -1;
        int n = haystack.size(), k = needle.size();
        for(int i=0;i<n;i++){
            if(haystack[i]==needle[0]){
                bool match = true;
                for(int j=1;j<k;j++){
                    if(haystack[i+j]!=needle[j]){
                        match = false;
                        break;
                    }
                }
                if(match)return i;
            }
        }
        return -1;
    }
};