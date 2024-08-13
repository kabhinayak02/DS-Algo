#include <vector>
#include <unordered_map>
using namespace std;

// Recursive Approach 
// tc: o(2^n)
class Solution {
public:
    int solve(int i, int n, vector<int> &nums, int target) {
        if (i == n) {
            return target == 0 ? 1 : 0;
        }

        // Calculate the number of ways by either adding or subtracting the current number
        int sub = solve(i + 1, n, nums, target - nums[i]);
        int add = solve(i + 1, n, nums, target + nums[i]);

        return add + sub;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return solve(0, n, nums, target);
    }
};



// Using Offset Approach 
// tc: o(n*m)
// sc: o(n*m)
class Solution {
public:
    int t[21][2001];
    const int OFFSET = 1000; // Offset to handle negative targets
    
    int solve(int i, int n, vector<int> &nums, int target) {
        // If target is out of bounds, return 0
        if (target < -OFFSET || target > OFFSET) return 0;

        if (i == n) {
            return target == 0 ? 1 : 0;
        }

        if (t[i][target + OFFSET] != -1) return t[i][target + OFFSET];

        // Calculate the number of ways by either adding or subtracting the current number
        int sub = solve(i + 1, n, nums, target - nums[i]);
        int add = solve(i + 1, n, nums, target + nums[i]);

        return t[i][target + OFFSET] = add + sub;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        memset(t, -1, sizeof(t));
        return solve(0, n, nums, target);
    }
};


// Using Map (DP implementaion using Map)

class Solution {
public:
    unordered_map<string, int> memo;

    string getKey(int i, int target) {
        return to_string(i) + "," + to_string(target);
    }

    int solve(int i, int n, vector<int>& nums, int target) {
        if (i == n) {
            return target == 0 ? 1 : 0;
        }

        string key = getKey(i, target);
        if (memo.find(key) != memo.end()) {
            return memo[key];
        }

        // Calculate the number of ways by either adding or subtracting the current number
        int sub = solve(i + 1, n, nums, target - nums[i]);
        int add = solve(i + 1, n, nums, target + nums[i]);

        memo[key] = add + sub;
        return memo[key];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return solve(0, n, nums, target);
    }
};
