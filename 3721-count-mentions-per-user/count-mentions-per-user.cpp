class Solution {
public:
    void parseID(string& users, vector<int> &userID) {
       stringstream ss(users);
       string id;
        while(ss>>id){
            if(id.size()>=2 and id.substr(0,2)=="id"){
                int idInt = stoi(id.substr(2));
                cout<<"User ID: "<<idInt<<endl;
                userID.push_back(idInt);
            }   
        }
       return ;
    }
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {

        int n = numberOfUsers;
        vector<int> mentions(n,0);
        vector<int> offline(n,0); // shows till what time the user is offline
        ranges::sort(events, {}, [](auto &e){
            return pair(stoi(e[1]), e[0][2]);
        });
        for(auto event : events){
            int timestamp = stoi(event[1]);
            string users = event[2];
            if(event[0]=="OFFLINE"){
                offline[stoi(users)] = timestamp + 60;
                continue;
            }
            else if(users == "ALL"){
                for(int i=0;i<n;i++)mentions[i]++;
            }
            else if(users == "HERE"){
                for(int i=0;i<n;i++){
                    if(offline[i]<=timestamp)mentions[i]++;
                }
            }
            else{
                vector<int> userID;
                parseID(users, userID);
                for(auto id: userID){
                    mentions[id]++;
                }
            }
        }
        return mentions;
    }
};