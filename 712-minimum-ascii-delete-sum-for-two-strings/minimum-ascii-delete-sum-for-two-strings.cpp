class Solution {
public:
    int summ(string &s, int &x){
        int sum = 0;
        for(int i=x;i<s.size();i++){
            sum+=int(s[i]);
        }
        return sum;
    }
    int recc(string &s1, string &s2, int i, int j, vector<vector<int>> &dp){
        // case 1 : some ith and jth character matches in both string
        // case 2 : it doesn't matches

        // so we have two casses , lets us analyze them one by one 
        // case 1: if some ith and jth character matches then we 
        //         can reduce the ASCII sum if we include both ith and jth character in sequence,
        //         so we dont add their's ASCII values 
        // case 2: ith and jth character doesn't matches , so we have 2 option for these
        
        //     option 1 : skip ith character assuming jth character might be useful later
        //                  on , so we add ASCII of ith and recurr for rest 
        //     option 2 : skip jth character assuming ith matches somewhere late in string ,
        //                  same as option 1 for other string
        if(i==s1.size() or j==s2.size()){
            if(i==s1.size() and j==s2.size()){
                return dp[i][j] = 0;
            }
            return dp[i][j] = i==s1.size()? summ(s2, j) : summ(s1, i); // non empty sum
        }
        if(dp[i][j]!=-1)return dp[i][j];
        // case 1:
        if(s1[i]==s2[j])dp[i][j] = recc(s1, s2, i+1, j+1, dp);
        // case 2: 
        // remove i or remove j
        else{
            dp[i][j] = min(int(s1[i]) + recc(s1, s2, i+1, j, dp),
                      int(s2[j]) + recc(s1, s2, i, j+1, dp));
        }
        return dp[i][j];
    }
    int minimumDeleteSum(string s1, string s2) {
        // for each of the index in s1 and s2, 
        // we have 2 choices to make, either to delete this, 
        // or to keep it
        // and then check if the strings are equal or not

        // basically we need to find the sum of 
        // all the char which are not part of the longest common subseq
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
        int ans = recc(s1, s2, 0, 0, dp);
        return ans;
    }
};