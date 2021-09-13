/*You are given n rectangles represented by a 0-indexed 2D integer array rectangles, where rectangles[i] = [widthi, heighti] denotes the width and height of the ith rectangle.

Two rectangles i and j (i < j) are considered interchangeable if they have the same width-to-height ratio. More formally, two rectangles are interchangeable if widthi/heighti == widthj/heightj (using decimal division, not integer division).

Return the number of pairs of interchangeable rectangles in rectangles.*/

class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        long long ans = 0;
        vector<double> v;
        for(int i=0;i<rectangles.size();i++){
            cout << (double)rectangles[i][0]/(double)rectangles[i][1];
            v.push_back((double)rectangles[i][0]/(double)rectangles[i][1]);
        }
        sort(v.begin(),v.end());
        long long cnt = 1;
        
        for(int i=1;i<rectangles.size();i++){
          if(v[i] == v[i-1]){
              cnt ++;
          }
            else{
                ans += (cnt*(cnt-1))/2;
                cnt = 1;
            }
        }
        ans += (cnt*(cnt-1))/2;
        return ans;
    }
};
