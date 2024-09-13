#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

/*
Using 3D Dp

sc: o(n*m*N)
tc: o(n*m*N)
*/

class Solution {
public:
    int t[101][101][201];
    bool solve(int i, int j, int k, string& s1, string& s2, string& s3){
        if(i == s1.size() && j == s2.size() && k == s3.size()) return 1;

        if(k >= s3.size()) return 0;

        if(t[i][j][k] != -1) return t[i][j][k];

        int result = false;
        if(s1[i] == s3[k]){
            result = solve(i+1, j, k+1, s1, s2, s3);
        }
        if(result == true) return t[i][j][k] = true;

        if(s2[j] == s3[k]){
            result = solve(i, j+1, k+1, s1, s2, s3);
        }

        return t[i][j][k] = result;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        int k = s3.size();
        memset(t, -1, sizeof(t));
        return solve(0, 0, 0, s1, s2, s3);
    }
};

/*
Using 2D Dp

you can find the length by adding i+j so no need to store 3rd element dp

sc: o(n*m)
tc: o(n*m)
*/

class Solution {
public:
    int t[101][101];
    bool solve(int i, int j, string& s1, string& s2, string& s3){
        if(i == s1.size() && j == s2.size() && i+j == s3.size()) return 1;

        if(i+j >= s3.size()) return 0;

        if(t[i][j] != -1) return t[i][j];

        int result = false;
        if(s1[i] == s3[i+j]){
            result = solve(i+1, j, s1, s2, s3);
        }
        if(result == true) return t[i][j] = true;

        if(s2[j] == s3[i+j]){
            result = solve(i, j+1, s1, s2, s3);
        }

        return t[i][j] = result;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        memset(t, -1, sizeof(t));
        return solve(0, 0, s1, s2, s3);
    }
};