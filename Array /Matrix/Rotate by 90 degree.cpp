/*

gfg Link: https://www.geeksforgeeks.org/problems/rotate-by-90-degree0356/1
similar to Leetcode 48: Rotate Image

tc: o(n^2)
sc: o(1) in-place

*/

void rotate(vector<vector<int> >& mat) {
    int n = mat.size();
    // step 1: Transpose the mat
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            swap(mat[i][j], mat[j][i]);
        }
    }
    
    // Step 2: reverse each row
    for(int i=0; i<n; i++){
        reverse(mat[i].begin(), mat[i].end());
    }
}