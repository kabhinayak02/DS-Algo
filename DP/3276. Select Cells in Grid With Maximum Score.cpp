/*
Brute force recursive approach [TLE]

tc: O(2^n)
sc: O(1)
*/
class Solution {
public:
    int n, m;
    int solve(int row, int currSum, vector<vector<int>>& grid, vector<int>& freq){
        if(row >= n){
            return currSum;
        }

        int take = 0, notTake = 0;

        for(int col=0; col<m; col++){
            int num = grid[row][col];
            if(freq[num] == 0){
                freq[num]++;
                take = max(take, solve(row+1, currSum+num, grid, freq));
                freq[num]--;
            }
        }
        notTake = solve(row + 1, currSum, grid, freq); // skip the row
        
        return max(take, notTake);
    }
    int maxScore(vector<vector<int>>& grid) {
        n = grid.size(); // row 
        m = grid[0].size(); // colomn 
        vector<int> freq(101, 0); // visited array for uniqness 
        return solve(0, 0, grid, freq);
    }
};

/*
Bitmask Approach [TLE]

*/
class Solution {
public:
    // We traverse the sortedNum and selecting each row and check if it will give maximum sum.
    int solve(int i, vector<int>& sortedNums, unordered_map<int, vector<int>>& mp, int mask){
        if(i >= sortedNums.size()) {
            return 0;
        }
        int ans = 0;
        for(auto j: mp[sortedNums[i]]){ // traverse all the rows of given num from sortedNums
            if((mask & (1 << j)) == 0){ // not visited or not taken or not selected
                ans = max(ans, sortedNums[i] + solve(i+1, sortedNums, mp, (mask | (1 << j))));
            }
        }
        ans = max(ans, solve(i+1, sortedNums, mp, mask)); // skip that(i'th) number num
        return ans;
    }
    int maxScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        set<int> st; // we dont need repeated number so we can sort them later on
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                st.insert(grid[i][j]);
            }
        } 

        vector<int> sortedNums;
        for(auto i: st){
            sortedNums.push_back(i);
        }
        sort(sortedNums.begin(), sortedNums.end(), greater<int>()); // sort the array in decreasing order 
        /*
            We are going to choose large number first int the array because we need to maximise the total sum 
        */
        unordered_map<int, vector<int>> mp; // Stores the grid number with rows numbers // [num: {row1, row3}, num2: {row2}]
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                mp[grid[i][j]].push_back(i); 
            }
        }
        return solve(0, sortedNums, mp, 0);
    }
};

/*
Accepted Solution: Dp with Bitwise Approach 

tc: O(n*m)
sc: O(n*m)

*/

class Solution {
public:
    int t[101][2001];
    // We traverse the sortedNum and selecting each row and check if it will give maximum sum.
    int solve(int i, vector<int>& sortedNums, unordered_map<int, vector<int>>& mp, int mask){
        if(i >= sortedNums.size()) {
            return 0;
        }

        if(t[i][mask] != -1) return t[i][mask];

        int ans = 0;
        for(auto j: mp[sortedNums[i]]){ // traverse all the rows of given num from sortedNums
            if((mask & (1 << j)) == 0){ // not visited or not taken or not selected
                ans = max(ans, sortedNums[i] + solve(i+1, sortedNums, mp, (mask | (1 << j))));
            }
        }
        ans = max(ans, solve(i+1, sortedNums, mp, mask)); // skip that(i'th) number num
        return t[i][mask] = ans;
    }
    int maxScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        set<int> st; // we dont need repeated number so we can sort them later on
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                st.insert(grid[i][j]);
            }
        } 

        vector<int> sortedNums;
        for(auto i: st){
            sortedNums.push_back(i);
        }
        sort(sortedNums.begin(), sortedNums.end(), greater<int>()); // sort the array in decreasing order 
        /*
            We are going to choose large number first int the array because we need to maximise the total sum 
        */
        unordered_map<int, vector<int>> mp; // Stores the grid number with rows numbers // [num: {row1, row3}, num2: {row2}]
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                mp[grid[i][j]].push_back(i); 
            }
        }
        memset(t, -1, sizeof(t));
        return solve(0, sortedNums, mp, 0);
    }
};