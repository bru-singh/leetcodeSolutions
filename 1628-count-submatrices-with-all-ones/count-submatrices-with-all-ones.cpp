class Solution {
public:
    int count1DArray(vector<int> &mat){
        int n = mat.size();
        stack<int> st;
        int res = 0;
        vector<int> sum(n,0);
        for(int i=0;i<n;i++){
            while(!st.empty() and mat[st.top()]>=mat[i])st.pop();
            if(!st.empty()){
                int prevIndx = st.top();
                sum[i]=sum[prevIndx];
                sum[i]+=mat[i]*(i-prevIndx);
            }
            else{
                sum[i] = mat[i]*(i+1);
            }
            st.push(i);
        }
        for(auto it: sum)res+=it;
        return res;
    }
    int numSubmat(vector<vector<int>>& mat) {
        // if we had a 1D array: it would be simple, iterate over the array
        // and increase the count of continuoues one, and add the count to ans.
        // and then if we find a zero, make the count to 0 again. 

        // for a 2D array, for each of the row, we can treat it as a 1D array and then proceed
        // the same way, but for a 2D array, which starts at the row1 and end at row2, 
        // we have to check if all the values in each row are 1 or not, i.e
        // if we can expand our rectange or not. If we can expand our rectangle, 
        // then we will include the count in our ans, else move. 

        // Let's solve 2D matrix by finding all 1 submatrices from row "up" to row "down". 
        // And apply above 1D helper function. 
        // Note: the array h[k] == 1 means all values in column k from row "up" to "down" are 1 
        // (that's why we use &). So overall, the idea is to "compress" the 2D array to the 1D array,
        // and apply 1D array method on it, while trying all heights up to down.

        // int n = mat.size(), m = mat[0].size();
        // int res = 0;
        // for(int startRow = 0; startRow<n;startRow++){
        //     vector<int> colVec(m,1);
        //     for(int endRow =startRow; endRow<n;endRow++){
        //         for(int col=0;col<m;col++){
        //             colVec[col]&= mat[endRow][col];
        //         }
        //         res += count1DArray(colVec);
        //     }
        // }
        // return res;

        // USING STACK
        int n = mat.size(), m =mat[0].size();
        int res = 0;
        vector<int> heights(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1){
                    heights[j]+=1;
                }
                else heights[j]=0;
            }
            res += count1DArray(heights);
        }
        return res;
    }
};