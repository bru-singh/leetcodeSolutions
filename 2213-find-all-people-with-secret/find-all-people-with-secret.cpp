class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        // initially only 0 and firstPerson know the secret
        // sort the meetings based on the time
        // sort(meetings.begin(), meetings.end(), [&](vector<int> &a, vector<int> &b){
        //     if(a[2]==b[2]){
        //         if(a[1]==b[1]){
        //             return a[0]<b[0];
        //         }
        //         return a[1]<b[1];
        //     }
        //     return a[2]<b[2];
        // });
        // unordered_map<int,int> mp;
        // mp[0]=1;
        // mp[firstPerson]=1;
        // // at time t=0, both the person 0 and firstperson know the secret

        // for(auto meeting: meetings){
        //     int p1 = meeting[0];
        //     int p2 = meeting[1];
        //     if(mp[p1] || mp[p2]){
        //         mp[p1]=mp[p2]=1;
        //     }
        // }
        // vector<int> ans;
        // for(auto it: mp){
        //     if(it.second==1)ans.push_back(it.first);
        // }
        // sort(ans.begin(), ans.end());
        vector<vector<pair<int,int>>> graph(n);
        for(auto meeting: meetings){
            graph[meeting[0]].push_back({meeting[1], meeting[2]});
            graph[meeting[1]].push_back({meeting[0], meeting[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        // min heap: take min time first
        vector<int> vis(n,0); 
        // to track if this person have shared the secret before or not
        pq.push({0,firstPerson});
        pq.push({0,0});
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            int time = curr.first;
            int person = curr.second;
            if(vis[person])continue;
            vis[person]=true;
            for(auto it: graph[person]){
                if(vis[it.first]!=true and time<=it.second){
                    pq.push({it.second, it.first});
                }
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(vis[i])ans.push_back(i);
        }
        return ans;
    }
};