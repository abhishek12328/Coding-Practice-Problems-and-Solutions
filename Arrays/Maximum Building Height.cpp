/*You want to build n new buildings in a city. The new buildings will be built in a line and are labeled from 1 to n.

However, there are city restrictions on the heights of the new buildings:

The height of each building must be a non-negative integer.
The height of the first building must be 0.
The height difference between any two adjacent buildings cannot exceed 1.
Additionally, there are city restrictions on the maximum height of specific buildings. These restrictions are given as a 2D integer array restrictions where restrictions[i] = [idi, maxHeighti] indicates that building idi must have a height less than or equal to maxHeighti.

It is guaranteed that each building will appear at most once in restrictions, and building 1 will not be in restrictions.

Return the maximum possible height of the tallest building.*/


class Solution {
public:
   int pass(vector<vector<int>>& r) {
    int res = 0;
    for (int i = 0; i < r.size() - 1; ++i) {
        auto h1 = r[i][1], h2 = r[i + 1][1];
        auto h = h1 + abs(r[i + 1][0] - r[i][0]);
        if (h > h2)
            h = h2 + (h - h2) / 2;
        res = max(res, h);
        r[i + 1][1] = min(h, h2);
    }
    return res;
}
int maxBuilding(int n, vector<vector<int>>& r) {
    r.insert(r.end(), {{1, 0}, {n, n - 1}});
    sort(begin(r), end(r));
    pass(r);
    reverse(begin(r), end(r));
    return pass(r);
}

};
