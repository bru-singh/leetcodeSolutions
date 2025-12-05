class Solution {
public:
    int checkPalindrome(string s, int left, int right){
        int n= s.size();
        int len = 0;
        while(left>=0 and right<n and s[left]==s[right]){
            right++; left--;
        }
        return right-left-1;
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
        int start = 0, end = 0;
        string ans ="";
        while(curr<n){
            int len1 = checkPalindrome(s, curr, curr);
            int len2 = checkPalindrome(s, curr, curr+1);
            int len = max(len1, len2);
            if(len>end-start){
                start = curr - (len-1)/2;
                end = curr + (len)/2;
            }
            curr++;
        }
        return s.substr(start, end - start + 1);
        
    }
};