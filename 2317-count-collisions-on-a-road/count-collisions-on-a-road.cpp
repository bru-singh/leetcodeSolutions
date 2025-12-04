class Solution {
public:
    int countCollisions(string directions) {
        int total = 0;
        // int left = 0, right = directions.size()-1;
        // int n = directions.size();
        // while(left<n and directions[left]=='L')left++;
        // while(right>=0 and directions[right]=='R')right--;
        // for(int i=left;i<=right;i++){
        //     if(directions[i]!='S')total++;
        // }
        stack<char> st;
        for(auto dir: directions){
            if(st.empty()){
                st.push(dir);
                continue;
            }
            // head on collision
            if(dir=='L' and st.top()=='R'){
                total+=2;
                st.pop();
                st.push('S');
            }
            // standing collision S and R
            else if(dir =='S' and st.top()=='R'){
                total+=1;
                st.pop();
                st.push('S');
            }
            // standin collision L and S
            else if(dir =='L' and st.top()=='S'){
                total+=1;
            }
            // no collision
            else st.push(dir);
        }
        // remove the right moving cars
        while(!st.empty() and st.top()=='R')st.pop();
        // count the R which are behind S and L
        while(!st.empty()){
            if(st.top()=='R')total++;
            st.pop();
        }
        return total;
    }
};