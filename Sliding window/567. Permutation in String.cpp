/*
Approach 1: Brute force [TLE]

tc: o(n! * m)
sc: o(n) recusive stack
*/
class Solution {
public:
    int n;
    int ans;
    // find the all the permutations of s1
    void solve(int idx, string& s1, string& s2){
        if(idx == n){
            if(s2.find(s1) != string::npos){
                ans = true;
            }
            return;
        }

        for(int i=idx; i<n; i++){
            swap(s1[i], s1[idx]);
            solve(idx+1, s1, s2);
            swap(s1[i], s1[idx]);
        }
    }

    bool checkInclusion(string s1, string s2) {
        n = s1.size();
        ans = false;

        solve(0, s1, s2);

        return ans;
    }
};

/*
Approach 2: [Accepted] 

we can use freq vector instead of sorting and compare it.

tc: o((m-n )nlogn)
sc: o(n) creating substring 

*/
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();

        if(n > m) return false;

        sort(s1.begin(), s1.end());

        for(int i=0; i<=m-n; i++){
            string substring = s2.substr(i, n);

            sort(substring.begin(), substring.end());

            if(s1 == substring) return true;
        }
        return false;
    }
};


/*
Approach 3: using sliding window [Accepted] 

tc: o(n+m)
sc: o(26)
*/
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();

        if(n > m) return false;

        vector<int> s1_freq(26, 0);
        vector<int> s2_freq(26, 0);

        for(char &ch: s1){
            s1_freq[ch - 'a']++;
        }

        int i = 0, j = 0;
        while(j < m){
            s2_freq[s2[j] - 'a']++;
            if(j-i+1 > n){
                s2_freq[s2[i]-'a']--;
                i++;
            }
            if(s1_freq == s2_freq){
                return true;
            }
            j++;
        }
        return false;
    }
};