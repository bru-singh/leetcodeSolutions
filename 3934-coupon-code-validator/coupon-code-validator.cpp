class Solution {
public:
    bool isCodeValid(string& code){
        if(code.empty())return false;
        for(char it: code){
            if(isdigit(it) or (it>='a' and it<='z') or (it>='A' and it<='Z') or it=='_')continue;
            else return false;
        }
        return true;
    }
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        // we can use stringstream to treat the string as input stream and then take the values as 
        // individual inputs, 
        vector<string> elec, pharma, rest, groc;
        int n = code.size();
        for(int i=0;i<n;i++){
            bool isValid = isCodeValid(code[i]);
            if(isActive[i] and isValid){
                if(businessLine[i]=="restaurant"){
                    rest.push_back(code[i]);
                }
                else if(businessLine[i]=="grocery"){
                    groc.push_back(code[i]);
                }
                else if(businessLine[i]=="pharmacy"){
                    pharma.push_back(code[i]);
                }
                else if(businessLine[i]=="electronics"){
                    elec.push_back(code[i]);
                }
            }
        }
        vector<string> ans;
        sort(elec.begin(), elec.end());
        sort(groc.begin(), groc.end());
        sort(pharma.begin(), pharma.end());
        sort(rest.begin(), rest.end());
        ans.insert(ans.end(), elec.begin(), elec.end());
        ans.insert(ans.end(), groc.begin(), groc.end());
        ans.insert(ans.end(), pharma.begin(), pharma.end());
        ans.insert(ans.end(), rest.begin(), rest.end());
        return ans;
    }
};