/*

subset + PNC problem 
tc : o(n!)
sc: o(n * n! + n)
*/

class Solution {
    public:
        int n;
        void solve(string tiles, vector<bool>& used, unordered_set<string>& result, string& curr){
            result.insert(curr);
            for(int i=0; i<n; i++){
                if(used[i] == false){
                    used[i] = true;
                    curr.push_back(tiles[i]);
    
                    solve(tiles, used, result, curr);
    
                    used[i] = false;
                    curr.pop_back();
                }
            }
        }
        int numTilePossibilities(string tiles) {
            n = tiles.size();
            vector<bool> used(n, false);
            unordered_set<string> result;
            string curr = "";
    
            solve(tiles, used, result, curr);
            return result.size()-1;
        }
};

/*

tc: o(26 ^ n)
sc: o(n) , improved space 
*/

class Solution {
public:
    int count;
    void solve(vector<int>& freq){
        count++;

        for(int i=0; i<26; i++){
            if(freq[i] > 0){
                freq[i]--;
                solve(freq);
                freq[i]++;
            }
        }
    }
    int numTilePossibilities(string tiles) {
        vector<int> freq(26, 0);
        count = 0;
        for(auto& ele: tiles){
            freq[ele-'A']++;
        }
        solve(freq);
        return count-1;
    }
};