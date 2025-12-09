class Solution {
public:
    // int strStr(string haystack, string needle) {
    //     if(needle.size()==0)return 0;
    //     if(needle.size()>haystack.size())return -1;
    //     int n = haystack.size(), k = needle.size();
    //     for(int i=0;i<n;i++){
    //         if(haystack[i]==needle[0]){
    //             bool match = true;
    //             for(int j=1;j<k;j++){
    //                 if(haystack[i+j]!=needle[j]){
    //                     match = false;
    //                     break;
    //                 }
    //             }
    //             if(match)return i;
    //         }
    //     }
    //     return -1;
    // }
    // another way to solve this is by using KMP algorithm
    // we make the KMP array
    // second we do the matching
    void makeLPS(vector<int> &lps, string &needle){
        int m = needle.size();
        int len = 0;
        lps[0]=0;
        for(int i=1;i<m;){
            if(needle[i]==needle[len]){
                len++;
                lps[i]=len;
                i++;
            }
            else{
                if(len!=0){
                    len = lps[len-1];
                }
                else{
                    lps[i]=0;
                    i++;
                }
            }
        }
    }
    int strStr(string haystack, string needle){
        int n = haystack.size(), m = needle.size();
        if(m==0)return 0;
        if(m>n)return -1;
        vector<int> lps(m,0);
        makeLPS(lps, needle);
        int i=0,j=0;
        while(i<n){
            if(needle[j]==haystack[i]){
                i++;
                j++;
            }
            if(j==m){
                return i-j; // the pattern match till the index start + j
                // so start = i-j;
            }
            else if(i<n and needle[j]!=haystack[i]){
                // we do not need to match the char from 0, 1, 2 --- j-1 
                // cos they are already matching anyways: which is stored in the lps
                if(j!=0){
                    j=lps[j-1];
                }
                else i++;
            }
        }
        return -1;
    }
};