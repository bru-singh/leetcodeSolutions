class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        int n= flips.size(), ans=0;
        // string binary, prefix; 
        // for(int i =0;i<n;i++){
        //     flips[i]-=1;binary+="0";prefix+="0";
        // }
        int runningSum=0, total=0;
        for(int i =0;i<n;i++){
            runningSum += flips[i];
            total +=i+1;
            if(runningSum == total)ans++;
        }
        return ans;

    }
};