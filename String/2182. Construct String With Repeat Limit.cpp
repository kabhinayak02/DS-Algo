/*
string travsersal using count vector

create a char freq/count vector and traverse from the back because we need a lexicographically largest number 
after using limited amount of char now traverse for the next largest char. 

tc : o(n)
sc : o(26)
*/
class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> count(26, 0);

        for(char &ch: s){
            count[ch - 'a']++;
        }
        string ans;

        int i = 25;
        while(i >= 0){
            if(count[i] == 0){
                i--;
                continue;
            }

            char ch = 'a' + i;
            int freq = min(count[i], repeatLimit);

            ans.append(freq, ch);
            count[i] -= freq;

            if(count[i] > 0){
                int j = i-1;
                while(j >= 0 && count[j] == 0){
                    j--;
                }

                if(j < 0) break;

                ans.push_back('a' + j);
                count[j]--;
            }
        }
        return ans;
    }
};

/*
using max heap 

use max heap to store the lexicographically largest char instead of traverse from the back 

tc: o(n)
sc: o(26)
*/
class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> count(26, 0);

        for(char &ch: s){
            count[ch - 'a']++;
        }
        string ans;

        priority_queue<char> pq;

        for(int i=0; i<26; i++){
            if(count[i] > 0){
                pq.push('a' + i);
            }
        }

        while(!pq.empty()){
            char ch = pq.top();
            pq.pop();

            int freq = min(count[ch-'a'], repeatLimit);
            
            ans.append(freq, ch);
            count[ch-'a'] -= freq;

            if(count[ch-'a'] > 0 && !pq.empty()){
                char nextChar = pq.top();
                pq.pop();

                ans.push_back(nextChar);
                count[nextChar-'a']--;

                if(count[nextChar-'a'] > 0){
                    pq.push(nextChar);
                }

                pq.push(ch);
            }
        }
        return ans;
    }
};
