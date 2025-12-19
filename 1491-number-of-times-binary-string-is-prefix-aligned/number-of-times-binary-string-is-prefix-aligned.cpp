class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        int n= flips.size(), ans =0;
        string binary, prefix; 
        for(int i =0;i<n;i++){
            flips[i]-=1;binary+="0";prefix+="0";
        }
        for(int i =0;i<n;i++){
            binary[flips[i]]='1';
            prefix[i]='1';
            if(binary==prefix)ans++;
        }
        return ans;

    }
};