/*
Problem: 3386. Button with Longest Push Time
You are given a 2D array 'events' representing a sequence of button presses.
Each events[i] = [indexi, timei] shows the button pressed and its time.
Return the button that took the longest time to push. If multiple buttons
have the same longest time, return the smallest index.

Approach:
- Start with the first button; its press time is events[0][1].
- Iterate from the second button to the last:
    - Calculate time difference with previous button.
    - If time difference > maxTime, update maxTime and answer.
    - If time difference == maxTime and current index < answer, update answer.
- Return the button index with longest push time.

Time Complexity: O(n), where n = number of events
Space Complexity: O(1)
*/

class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& events) {
        int n = events.size();
        int ans = events[0][0];        // Initialize answer with first button index
        int num = events[0][1];        // Time taken for first button

        for(int i = 1; i < n; i++) {
            int diff = events[i][1] - events[i - 1][1];  // Time difference with previous
            if(diff > num) {       // Found new max time
                num = diff;
                ans = events[i][0];
            } 
            else if(diff == num) { // Same max time, pick smaller index
                if(ans > events[i][0]) {
                    ans = events[i][0];
                }
            }
        }
        return ans;
    }
};
