/*
Problem: 3727. Maximum Alternating Sum of Squares

You are given an integer array 'nums'. You may rearrange the elements in any order.

The alternating score of an array arr is defined as:
score = arr[0]^2 - arr[1]^2 + arr[2]^2 - arr[3]^2 + ...

Return the maximum possible alternating score of 'nums' after rearranging its elements.

Approach:
- To maximize the alternating sum, sort the numbers by their squares in descending order.
- Pick the largest square for position 0, the next largest for position 2, and so on.
- Essentially, the maximum alternating sum is achieved by summing squares at even positions
  and subtracting squares at odd positions in sorted descending order.
- This implementation uses max-heap and min-heap to simulate taking largest and smallest squares,
  then computes the alternating sum by differences.

Time Complexity: O(n log n) for heaps
Space Complexity: O(n) for the heaps
*/

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        priority_queue<int> maxHeap;  // Max heap for largest squares
        priority_queue<int, vector<int>, greater<int>> minHeap;  // Min heap for smallest squares

        for(int i = 0; i < nums.size(); i++){
            int sq = nums[i] * nums[i];
            maxHeap.push(sq);
            minHeap.push(sq);
        }

        long long int mini = 0, maxi = 0;
        int size = maxHeap.size();

        // Sum first half of largest and smallest squares
        for(int i = 0; i < size / 2; i++){
            maxi += maxHeap.top();
            mini += minHeap.top();
            maxHeap.pop();
            minHeap.pop();
        }

        // If odd number of elements, add the last largest square to maximize
        if(size % 2 == 1){
            maxi += maxHeap.top();
        }

        // Return the absolute difference
        return abs(maxi - mini);
    }
};
