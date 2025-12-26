class Solution {
public:
    int bestClosingTime(string customers) {
        // basically take the prefix and suffix 
        // and choose a index such that the sum is min. 
        int n = customers.size();
        int leftSum = 0, rightSum = 0;
        for(int i=n-1;i>=0;i--)rightSum += customers[i]=='Y'? 1: 0;
        int minTotal = leftSum + rightSum, ans = 0;

        for(int i=0;i<n;i++){
            leftSum += customers[i]=='N'? 1:0;
            rightSum -= customers[i]=='Y'? 1:0;
            int total = leftSum + rightSum;
            if(total<minTotal){
                minTotal = total;
                ans = i+1;
            }
        }
        return ans;
    }
};