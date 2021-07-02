/*You are driving a vehicle that has capacity empty seats initially available for passengers.  The vehicle only drives east (ie. it cannot turn around and drive west.)

Given a list of trips, trip[i] = [num_passengers, start_location, end_location] contains information about the i-th trip: the number of passengers that must be picked up, and the locations to pick them up and drop them off.  The locations are given as the number of kilometers due east from your vehicle's initial location.

Return true if and only if it is possible to pick up and drop off all passengers for all the given trips. 

 ---------------------------------------------------------------
 ---------------------------------------------------------------*/


class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<pair<int,pair<int,int>>> v;
        for(int i=0;i<trips.size();i++){
            v.push_back(make_pair(trips[i][1],make_pair(trips[i][0],trips[i][2])));
        }
        sort(v.begin(),v.end());
        int pass=0,n=trips.size();
        vector<bool> b(n,0);
        for(int i=0;i<n;i++){
            pass += v[i].second.first; 
            for(int j=i;j>=0;j--){
                if(v[j].second.second<=v[i].first && b[j]==0){
                    b[j] = 1;
                    pass = pass-v[j].second.first;
                }
            }
            if(pass>capacity)
                return false;
        }
        return true;
        
    }
};
