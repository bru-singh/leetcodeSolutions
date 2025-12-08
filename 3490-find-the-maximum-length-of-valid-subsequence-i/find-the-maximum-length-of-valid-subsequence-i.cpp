class Solution {
public:
    // selection: 
    // 0 --> all even
    // 1 --> all odd
    // 2 -->even then odd
    int maximumLength(vector<int>& nums) {
        // let's solve this greedyly
        // we have 3 ways of choosing any number: 
        // 1. choose all even 
        // 2. choose all odds
        // 3. choose alternating even and odds
        // since we want to find the maxLen, it is better to choose all the numbers
        // and approach this problem greedyly

        vector<int> choice(3, 0);
        int parity = nums[0]&1;
        choice[0] = !parity; // even 
        choice[1] = parity; // odd
        choice[2] = 1; // even or odd, alternating 
        int n = nums.size();
        if(n==2)return 2;
        for(int i=1;i<n;i++){
            bool currParity = nums[i]&1;
            // if currParity == 0: i.e even
            // i.e previously we can take even so increase the even choice
            // if currParity == 1: i.e odd
            // i.e previously we can take odd so increase the odd choice
            // if currParity != partiy: 
            // incrase the choice of alternating 
            // parity = currParity
            if(currParity==0)choice[0]++;
            else choice[1]++;
            if(currParity != parity){
                choice[2]++;
                parity = currParity;
            }
        }
        return max(choice[0], max(choice[1], choice[2]));
        // return max( choice 0,  choice 1, choice 2);


    }
};