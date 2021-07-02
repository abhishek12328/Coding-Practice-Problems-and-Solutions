/*Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.

An integer a is closer to x than an integer b if:

|a - x| < |b - x|, or
|a - x| == |b - x| and a < b

-------------------------------------------------
-------------------------------------------------*/


class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        priority_queue<pair<int,bool>,vector<pair<int,bool>>,greater<pair<int,bool>>> pq;
        for(int i=0;i<arr.size();i++){
            if(arr[i]<=x)
            pq.push(make_pair(abs(arr[i]-x),0));
            else
            pq.push(make_pair(abs(arr[i]-x),1));
            
        }
        while(k--){
            auto temp = pq.top();
            pq.pop();
            if(temp.second == 0)
                ans.push_back(x-temp.first);
            if(temp.second == 1)
                ans.push_back(x+temp.first);
        }
        sort(ans.begin(),ans.end());
            return ans;
        
    }
};
