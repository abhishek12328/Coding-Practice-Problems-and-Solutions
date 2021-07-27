/*There is a party where n friends numbered from 0 to n - 1 are attending. There is an infinite number of chairs in this party that are numbered from 0 to infinity. When a friend arrives at the party, they sit on the unoccupied chair with the smallest number.

For example, if chairs 0, 1, and 5 are occupied when a friend comes, they will sit on chair number 2.
When a friend leaves the party, their chair becomes unoccupied at the moment they leave. If another friend arrives at that same moment, they can sit in that chair.

You are given a 0-indexed 2D integer array times where times[i] = [arrivali, leavingi], indicating the arrival and leaving times of the ith friend respectively, and an integer targetFriend. All arrival times are distinct.

Return the chair number that the friend numbered targetFriend will sit on.

 -----------------------------------------------------------------
 -----------------------------------------------------------------*/


class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        priority_queue<int,vector<int>,greater<int>> avail;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> busy;
        int next=0;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> arrti;
        for(int i=0;i<times.size();i++){
            arrti.push(make_pair(times[i][0],make_pair(times[i][1],i)));
        }
        for(int i=0;i<times.size();i++){
            auto k = arrti.top();
            arrti.pop();
            while(!busy.empty() && busy.top().first<=k.first){
                auto temp = busy.top();
                busy.pop();
                avail.push(temp.second);
                
            }
            if(!avail.empty()){
                if(k.second.second == targetFriend)
                    return avail.top();
                else{
                    int z = avail.top();
                    avail.pop();
                    busy.push(make_pair(k.second.first,z));
                }
            }
            else{
                if(k.second.second == targetFriend)
                    return next;
                busy.push(make_pair(k.second.first,next++));
            }
        }
        return 0;
            
            
    }
};
