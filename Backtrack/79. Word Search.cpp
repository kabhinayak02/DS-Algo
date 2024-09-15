/*

This code is same as DFS Traversal in graph.

tc: (n.m.4^k)
sc: o(k), k -> length of word
*/
class Solution {
private:
    bool solve(vector<vector<char>>& board, string &word, int row, int col, int ind){
        if(ind == word.size()) return true;
        if(row < 0 || col < 0 || row > board.size()-1 || col > board[0].size()-1) return false;
        if(board[row][col] != word[ind]) return false;

        board[row][col] = '*'; 
        bool ans = solve(board, word, row+1, col, ind+1) || 
                    solve(board, word, row, col+1, ind+1) ||
                    solve(board, word, row-1, col, ind+1) ||
                    solve(board, word, row, col-1, ind+1);
        board[row][col] = word[ind];
        return ans;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(); // row
        int m = board[0].size(); // col 

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(solve(board, word, i, j, 0)){
                    return true;
                }     
            }
        }
        return false;
    }
};