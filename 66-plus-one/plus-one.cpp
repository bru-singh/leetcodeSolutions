class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        vector<int> ans;
        int carry = 1;
        for(int i=n-1;i>=0;i--){
            int to_add = digits[i]+carry;
            carry = to_add/10;
            to_add = to_add%10;
            ans.push_back(to_add);
        }
        if(carry!=0)ans.push_back(carry);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};