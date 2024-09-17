/*

tc: o(n!)
sc: o(1) ac, o(n) recursive stack 

*/

class Solution {
public:
    vector<vector<string>> ans;
    int N;
    bool isValid(vector<string>& board, int row, int col){
        // upward
        for(int i=row-1; i>=0; i--){
            if(board[i][col] == 'Q'){
                return false;
            }
        }

        // diagonal left
        for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--){
            if(board[i][j] == 'Q'){
                return false;
            }
        }

        // diagonal right
        for(int i=row-1, j=col+1; i>=0 && j<N; i--, j++){
            if(board[i][j] == 'Q'){
                return false;
            }
        }
        return true;
    }
    void solve(int row, vector<string>& board){
        if(row >= N){
            ans.push_back(board);
            return;
        }

        for(int i=0; i<N; i++){
            if(isValid(board, row, i)){
                board[row][i] = 'Q';
                solve(row+1, board);
                board[row][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        N = n;
        vector<string> board(n, string(n, '.'));

        solve(0, board);

        return ans;
    }
};


/*

tc: o(n!)
sc: o(n)

*/

class Solution {
public:
    unordered_set<int> diags;
    unordered_set<int> antiDiag;
    unordered_set<int> cols;
    vector<vector<string>> ans;
    int N;
    void solve(int row, vector<string>& board){
        if(row >= N){
            ans.push_back(board);
        }

        for(int col = 0; col < N; col++){
            int diagConst = row + col;
            int antiDiagConst =row - col;

            if(cols.find(col) != cols.end() || diags.find(diagConst) != diags.end() || antiDiag.find(antiDiagConst) != antiDiag.end()){
                continue; 
            }

            cols.insert(col);
            diags.insert(diagConst);
            antiDiag.insert(antiDiagConst);
            board[row][col] = 'Q';

            solve(row+1, board);

            cols.erase(col);
            diags.erase(diagConst);
            antiDiag.erase(antiDiagConst);
            board[row][col] = '.';
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        N = n;
        vector<string> board(n, string(n, '.'));
        solve(0, board);
        return ans;
    }
};