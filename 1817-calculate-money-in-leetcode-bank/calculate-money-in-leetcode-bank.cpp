class Solution {
public:
    int totalMoney(int n) {
        int sum = 0;
        int prevMonday = 0;
        int prevDay = 0;
        for(int i=0;i<n;i++){
            if(i%7){
                sum+=prevDay+1;
                prevDay+=1;

            }
            else{
                sum+=prevMonday+1;
                prevMonday+=1;
                prevDay = prevMonday;
            }
        }
        return sum;
    }
};