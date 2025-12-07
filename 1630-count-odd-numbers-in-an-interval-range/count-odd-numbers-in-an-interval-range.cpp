class Solution {
public:
    int countOdds(int low, int high) {
        int range = high-low+1;
        // if range is even: equal number of odd and even numbers
        // if range is odd:{
        //     if starting is odd, then more odd
        //     else more even
        // }
        if(range%2 and low%2){
            return 1+range/2;
        }
        return range/2;
    }
};