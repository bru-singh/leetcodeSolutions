class Solution {
public:
    int countTriples(int n) {
        // from 1 to n: 
        // how many x, y and z exist such that: they follow the
        // pythagores theorem : a^2 + b^2 = c^2;

        // since the range of n: [1,250] we can brute force this

        int ans = 0;
        for(int a=1;a<=n;a++){
            for(int b=1;b<=n;b++){
                int c = a*a + b*b;
                int c_sqrt = sqrt(c);
                if(c_sqrt<=n and c == c_sqrt*c_sqrt)ans++;
                
            }
        }
        return ans;
    }
};