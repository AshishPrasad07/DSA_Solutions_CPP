/*
Problem: 3809. Best Reachable Tower

You are given a 2D integer array towers, where towers[i] = [xi, yi, qi] represents the 
coordinates (xi, yi) and quality factor qi of the ith tower. You are also given an integer 
array center = [cx, cy] representing your location, and an integer radius.

A tower is reachable if its Manhattan distance from center is less than or equal to radius. 
Among all reachable towers, return the coordinates of the tower with the maximum quality factor. 
If there is a tie, return the tower with the lexicographically smallest coordinate. If no tower 
is reachable, return [-1, -1].

Approach:
- Sort towers by their coordinates to ensure lexicographical order in case of ties.
- Initialize variables to track the best tower and maximum quality factor.
- Iterate through all towers:
    - If a tower is within the given Manhattan radius:
        - Update the best tower if its quality factor is higher than the current maximum.
- Return the coordinates of the best reachable tower, or [-1, -1] if none are reachable.

Time Complexity:   O(n log n) due to sorting
Space Complexity:  O(1)
*/

class Solution {
public:
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center, int radius) {
        sort(towers.begin(), towers.end());
        int x = -1, y = -1, maxi = -1;
        for(auto& t: towers){
            int i = t[0];
            int j = t[1];
            int q = t[2];
            if(abs(i - center[0]) + abs(j - center[1]) <= radius){
                if(q > maxi){
                    x = i, y = j;
                    maxi = q;
                }
            } 
        }
        return {x,y};
    }
};
