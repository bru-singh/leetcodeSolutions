class Solution {
public:
    string generateTheString(int n) {
        // len should be n 
        // each char should appear odd number of times
        string ans; 
        if((n&0x1)==0){
            n--;
            ans+="b";
        }
        while(n--)ans+="a";
        return ans;
        
    }
};