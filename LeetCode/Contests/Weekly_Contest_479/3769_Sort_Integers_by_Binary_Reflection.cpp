/*
Problem: 3769. Sort Integers by Binary Reflection

You are given an integer array nums.

The binary reflection of a positive integer is defined as the number obtained by reversing the order of its binary digits (ignoring any leading zeros) and interpreting the resulting binary number as a decimal.

Sort the array in ascending order based on the binary reflection of each element. If two different numbers have the same binary reflection, the smaller original number should appear first.

Approach:
- Reverse the binary digits of each number and convert back to decimal.
- Sort by reflected value, then by original number if ties occur.

Time Complexity:  O(n log n * log(max(nums)))
Space Complexity: O(n)
*/

class Solution {
public:
    pair<int, int> func(int num){
        string s;
        int a = num;
        while(a){
            s.push_back((a % 2) + '0'); // extract bits into string
            a /= 2;
        }
        int j = 0, n = 0;
        for(int i = s.size() - 1; i >= 0; i--){ // reverse binary manually
            n = (s[i] - '0') * pow(2, j) + n; // convert to decimal
            j++;
        }
        return {n, num}; // reflection, original
    }

    vector<int> sortByReflection(vector<int>& nums) {
        vector<pair<int,int>> res;
        for(int num: nums){
            res.push_back(func(num)); // compute reflection
        }
        sort(res.begin(), res.end()); // sort by reflection then number
        vector<int> ans;
        for(auto p: res){
            ans.push_back(p.second); // take original numbers
        }
        return ans;
    }
};
