class Solution {
private:
public:
    pair<int,int> divisorCount(int num){
        int cnt = 0, sum = 0;
        for(int i=1;i*i<=num;i++){
            if(num%i==0){
                if(num/i==i){
                    cnt+=1;
                    sum+=i;
                }
                else{
                    cnt+=2;
                    sum+=i+num/i;
                }
            }
        }
        return {sum, cnt};
    }
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for(auto it: nums){
            auto curr = divisorCount(it);
            if(curr.second==4)ans+=curr.first;
        }
        return ans;
    }
};