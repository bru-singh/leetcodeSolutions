class Solution {
public:
    long long tripCompleted(vector<int>& time, long long t){
        long long ans = 0;
        for(int i=0;i<time.size();i++){
            long long x = time[i];
            ans += t/x;
        }
        return ans;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        // let x be the trip completed per time for each bus
        // in time t1, bus 1 will complete x1*t1 trips
        // so totalTrip = t*(1/time1 + 1/time2 + 1/time3....);
        // totalTrip = t*(sum)/prod;
        // t*sum= prod*totalTrip;
        // t =>totalTrip/(1/time1 + 1/time2.... )
        // or t = totalTrip *(totalProd)/(totalProd/time1 + totalProd/time2....);

        long long start = 0, end = 1e14;
        long long ans = 0;
        while(start<end){
            long long mid = start +(end-start)/2;
            long long trips = tripCompleted(time, mid);
            if(trips>=totalTrips){
                end = mid;
            }
            else start = mid+1;
        }
        return start;
    }
};