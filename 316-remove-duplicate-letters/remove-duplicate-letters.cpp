class Solution {
public:
    string removeDuplicateLetters(string s) {
        // lexicographically means: 
        // the next element should be greater than the current element
        // so if we are selecting a current char, 
        // we need to select the enxt greatest number after that
        
        // for any curr char which is not seen before, 
        // if we select it we need to make sure the previous picked char is the smaller
        // in order to maintain the elxicographical order
        int n = s.size();
        vector<int> charHash(26,0);
        vector<int> lastIndx(26,0);
        for(int i=0;i<n;i++){
            lastIndx[s[i]-'a']=i;
        }
        // we will treat this string st as our stack and as our ans too. 
        string st;
        for(int i=0;i<n;i++){
            int curr = s[i]-'a';
            if(charHash[curr])continue;
            while(!st.empty() and st.back()>s[i]){
                if(lastIndx[st.back()-'a']<=i)break;
                charHash[st.back()-'a']=0;
                st.pop_back();
            }
            st.push_back(s[i]);
            charHash[s[i]-'a']=1;
        }
        return st;
    }
};