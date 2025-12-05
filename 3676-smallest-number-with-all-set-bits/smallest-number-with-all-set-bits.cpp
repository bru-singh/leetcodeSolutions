class Solution {
public:
    int smallestNumber(int n) {
        int res = 0;
        // jsut set all the bits of the number to 1
        while(n>0){
            res = 2*res +1;
            n/=2;
        }
        return res;
    }
};