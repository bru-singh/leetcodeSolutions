class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> st; // using this char vector as a stack
        int n = s.size();
        int maxLen = 0;
        // basically use a concept similar to sliding window ..anytime you 
        // encounter a invalid paranthesis, it means we need to start from a index
        // after that, cos it will be pointless to start from any palce before that. 
        // i.e any valid parenthsis has already been incountered, and we need to start from
        // the current index i.
        st.push_back(-1);
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push_back(i);
            }
            else st.pop_back();
            if(st.size()==0){
                // start from the index i;
                // start fresh
                st.push_back(i);
            }
            else{
                maxLen = max(maxLen, i-st.back());
            }
        }
        return maxLen;

    }
};