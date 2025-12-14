class Solution {
public:
    string smallestSubsequence(string s) {
        int n=s.size();
        vector<int> seenSoFar(26,0);
        vector<int> lastIndx(26,0);
        // a chceker if the current element is seen so far or not. 
        // and a checker to see if we have this element after any index after curr indx or not. 
        string st; 
        for(int i=0;i<n;i++)lastIndx[s[i]-'a']=i;
        for(int i=0;i<n;i++){
            if(seenSoFar[s[i]-'a'])continue;
            while(!st.empty() and st.back()>s[i]){
                // if we are not gonna see this char after this, 
                // we should not remove it 
                if(lastIndx[st.back()-'a']<i)break;
                seenSoFar[st.back()-'a']=false;
                st.pop_back();
            }
            st.push_back(s[i]);
            seenSoFar[s[i]-'a']=true;
        }
        return st;
        
    }
};