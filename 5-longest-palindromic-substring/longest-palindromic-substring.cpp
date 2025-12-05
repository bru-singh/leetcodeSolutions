class Solution {
public:
    pair<int,int> checkPalindrome(string s, int left, int right){
        int n= s.size();
        int len = 0;
        int start = 0;
        while(left>=0 and right<n and s[left]==s[right]){
            if(len<right - left + 1){
                start = left;
                len = right - left + 1;
            }
            right++; left--;
        }
        return {start, len};
    }
    string longestPalindrome(string s) {
        // Ques: question constraints? 
        // Ques: does this only contains english alphabets?
        // if not? they, does it mean we should only consider eng alphabets, 
        // and do some pre processing on the string and remove all the non eng?

        // we can use soemthing similar to sliding window here
        // but let's thing of the palindrome condition. 
        // start from the middle: if the left and right is equal, 
        // then it is a palindrome, move the left-- and right++ and check. 

        // else we should mvoe the current;
        // should we consider current or current and current +1

        int n = s.size();
        int curr = 0;
        int start = 0, maxLen = 0;
        while(curr<n){
            auto odd = checkPalindrome(s, curr, curr);
            auto even = checkPalindrome(s, curr, curr+1);
            int len = max(odd.second, even.second);
            if(len>maxLen){
                maxLen =len;
                if(len == odd.second)start = odd.first;
                else start = even.first;
            }
            curr++;
        }
        return s.substr(start, maxLen);
        
    }
};