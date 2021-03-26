/*The set [1, 2, 3, ..., n] contains a total of n! unique permutations.By listing and labeling all of the permutations in order, we get the following sequence for n = 3:
1."123"
2."132"
3."213"
4."231"
5."312"
6."321"
Given n and k, return the kth permutation sequence.
Example 1: Input: n = 3, k = 3 , Output: "213"
Example 2: Input: n = 4, k = 9 , Output: "2314" */

class Solution {
public:
    string getPermutation(int n, int k) {
        int fact = 1; 
        vector<int> numbers; 
        for(int i = 1;i<n;i++) {
            fact = fact * i; 
            numbers.push_back(i); 
        }
        numbers.push_back(n); 
        string ans = ""; 
        k = k - 1; 
        while(true) {
            ans = ans + to_string(numbers[k / fact]); 
            numbers.erase(numbers.begin() + k / fact); 
            if(numbers.size() == 0) {
                break; 
            }
            
            k = k % fact; 
            fact = fact / numbers.size();
        }
        return ans; 
    }
};