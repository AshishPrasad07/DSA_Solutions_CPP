/*
Problem: 3766. Minimum Operations to Make Binary Palindrome

You are given an integer array nums.

For each element nums[i], you may perform the following operations any number of times:
- Increase nums[i] by 1, or
- Decrease nums[i] by 1.

A number is called a binary palindrome if its binary representation without leading zeros reads the same forward and backward.

Return an integer array ans, where ans[i] represents the minimum number of operations required to convert nums[i] into a binary palindrome.

Approach:
- Generate all binary palindromes up to a certain limit (10000 in this case).
- For each number in nums, compute the minimum absolute difference with all generated palindromes.
- Return the array of minimum operations.

Time Complexity:  O(n * m) where n = nums.size() and m = number of palindromes generated  
Space Complexity: O(m) for storing generated palindromes
*/

class Solution {
public:
    bool isPalindrome(string& s){
        int i = 0, j = s.size() - 1;
        while(i < j){
            if(s[i] != s[j]){
                return false;
            }
            i++, j--;
        }
        return true;
    }

    vector<int> generate(int n){
        vector<int> palindrome;
        for(int i = 0; i <= n; i++){
            string s;
            int n = i;
            while(n){
                s.push_back((n % 2) + '0'); // convert to binary
                n /= 2;
            }
            reverse(s.begin(), s.end()); // reverse to correct order
            if(isPalindrome(s)){
                palindrome.push_back(i); // store if binary palindrome
            }
        }
        return palindrome;
    }

    vector<int> minOperations(vector<int>& nums) {
        vector<int> palindrome = generate(10000); // precompute palindromes
        vector<int> res;
        for(int num: nums){
            int mini = INT_MAX;
            for(int p: palindrome){
                mini = min(mini, abs(num - p)); // find min operations
            }
            res.push_back(mini);
        }
        return res;
    }
};
