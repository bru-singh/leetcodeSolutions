class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // 1 2 3.     7 4 1
        // 4 5 6. ==> 8 5 2
        // 7 8 9.     9 6 3

        // 1 2 3 4 5  ==> 4 5 1 2 3 
        // 5 4 3 2 1  ==> 4 5 1 2 3 O(n), O(1)


        // 7 8 9
        // 4 5 6 ==> matrix[i][j] == matrix[j][i] // swap across the diagonal
        // 1 2 3

        int n= matrix.size(), m = matrix[0].size();
        reverse(matrix.begin(), matrix.end());
        for(int i=0;i<n;i++){
            for(int j=i;j<m;j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        return ;
    }
};