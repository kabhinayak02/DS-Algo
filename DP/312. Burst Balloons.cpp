/*
If you start solving from the top, you won't get independent subproblems. Why?

Consider the array with 1's padded at both ends:
1   b1  b2  b3  b4  b5  b6  1

Let’s choose b4 to burst first. This would split the problem into two subproblems:
- (b1 -> b3)
- (b5 -> b6)

However, the problem is that b3 depends on its right neighbor, i.e., b4.
Similarly, b5 depends on its left neighbor, i.e., b4.

Moreover, there may be cases where b3 can depend on elements from the subproblem (b5 -> b6), and vice versa. 
By dividing the problem this way, you lose critical connections between subproblems, 
which makes the solution dependent on other subproblems.

As you can observe, solving the problem from top to bottom (or front to back) doesn't work because the 
subproblems aren't independent due to these dependencies. However, if we solve the problem from back to front 
(or bottom to top), we get independent subproblems.

Why? Because when solving from the back, we know that the current element will be part of the next iteration. 
For example, when we burst a balloon at index `ind` (nums[ind]), it will always act as the right neighbor of 
the left subproblem and the left neighbor of the right subproblem.

Thus, starting from the back allows you to work with independent subproblems. Let’s assume that b3 is the 
last balloon to burst, and `i` and `j` are the left and right bounds of b3:
1   b1  b2  b3  b4  b5  b6  1
    i       ind         j

# Case: Lets take b3 is the last balloon, so the array looks like this:
1   b3   1
    ind

# Second-to-last iteration:
In this step, we will consider all possible combinations like:
- (b1, b3)
- (b2, b3)
- (b3, b4)
- (b3, b5)

The key point here is that we know b3 will definitely be present in all possible combinations, 
ensuring that elements to the left of b3 are independent of the right subproblem, and vice versa.

The approach works because solving from the back ensures that every subproblem remains independent.

Time complexity: O(n^3)
Space complexity: O(n^2)
*/

class Solution {
public:
    int t[301][301];
    int solve(int i, int j, vector<int>& nums){
        if(i > j) return 0;

        if(t[i][j] != -1) return t[i][j];

        int maxi = INT_MIN;
        for(int ind = i; ind <= j; ind++){
            int cost = nums[i-1]*nums[ind]*nums[j+1] + solve(i, ind-1, nums) + solve(ind+1, j, nums);
            maxi = max(maxi, cost);
        }
        return t[i][j] = maxi;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        memset(t, -1, sizeof(t));

        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        return solve(1, n, nums);
    }
};



/*
Bottom - Up Approach 

tc: o(n^3)
sc: o(n^2)
*/
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);

        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));

        for(int i=n; i>=1; i--){
            for(int j=1; j<=n; j++){
                
                if(i > j) continue;

                int maxi = INT_MIN;
                for(int ind = i; ind <= j; ind++){
                    int cost = nums[i-1]*nums[ind]*nums[j+1] + dp[i][ind-1] + dp[ind+1][j]; 
                    maxi = max(maxi, cost);
                }
                dp[i][j] = maxi;

            }
        }
        return dp[1][n];
    }
};