class Solution {
public:
    int lowerBound(vector<int> &ages, int indx, int target){
        int start = 0, end = indx;
        int ans = 0;
        while(start<end){
            int mid = start+ (end-start)/2;
            if(ages[mid]>=target){
                end = mid;
            }
            else start = mid+1;
        }
        return start;
    }
    int upperBound(vector<int> &ages, int indx, int target){
        int start = indx, end = ages.size();
        int ans = 0;
        while(start<end){
            int mid = start+ (end-start)/2;
            if(ages[mid]>target){
                end = mid;
            }
            else start = mid+1;
        }
        return start-1;
    }
    int numFriendRequests(vector<int>& ages) {
        // so the only cases wehere x acan send a request to y is: 
        // 1. y should be less then x, and less then 100( x >100 too )
        // 2. y should be more then x/2 + 7

        // brute force for this will be O(n^2)
        // as for each of the friend you have to check for all the other and see which all fit.

        // range for y: (x/2+7, x] < 100
        sort(ages.begin(), ages.end());
        int n= ages.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            if(ages[i]<15)continue;
            // range for x: 
            int minAge = (ages[i]/2)+8;
            int maxAge = ages[i];
            int left = lowerBound(ages, i, minAge);
            int right = upperBound(ages, i, maxAge);
            if(right-left>0)ans += right-left;
        }
        return ans;
    }
};