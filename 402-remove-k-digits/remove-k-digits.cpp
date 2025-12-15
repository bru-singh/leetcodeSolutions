class Solution {
public:
    string removeKdigits(string s, int k) {
        // this seem very similar to the question: 
        // we need to find a lexicographically smallest subseq string
        // of lenght n-k in the string num.

        // so to find the lexicographically smallest, we greedyly remove
        // all the larger elemetns we can from the start, and only keep
        // all the smaller element

        int n = s.size();
        string st; // we will use this string as our stack
        // this will reduce the need to pop the stack at the end and reverse the string.
        for(int i=0;i<n;i++){
            int curr = s[i];
            while(!st.empty() and k>0 and st.back()>curr){
                k--;
                st.pop_back();
            }
            st.push_back(s[i]);
        }
        // after this traversal, if the K is still left you remove the elements from the back of the st
        while(k>0){
            st.pop_back();k--;
        } 
        // removeLeadingZero
        while(!st.empty() and st[0]=='0'){
            st.erase(0,1);
        }
        if(st.empty())return "0";
        return st;
        
    }
};