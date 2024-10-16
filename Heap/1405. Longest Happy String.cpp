/*
using heap 

create a max heap, stores the char with freq. check the last 2 char in answer string if they are same and add
accordinaly, if last 2 char and top element is same then add next highest freq char to the answer else add top element char 
  

tc: o(n)
sc: o(3)
*/
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {

        priority_queue<pair<int, char>> pq;

        if(a > 0) pq.push({a, 'a'});
        if(b > 0) pq.push({b, 'b'});
        if(c > 0) pq.push({c, 'c'});

        string ans = "";
        while(!pq.empty()){
            char currChar = pq.top().second;
            int currFreq = pq.top().first;
            pq.pop();

            if(ans.length() >= 2 && ans[ans.length()-1] == currChar && ans[ans.length()-2] == currChar){
                if(pq.empty()) break;
                char nxtChar = pq.top().second;
                int nxtFreq = pq.top().first;
                pq.pop();
                ans += nxtChar;
                nxtFreq--;
                if(nxtFreq > 0) pq.push({nxtFreq, nxtChar});
                
            }
            else{
                ans += currChar;
                currFreq--;
            }
            if(currFreq > 0) pq.push({currFreq, currChar});
        }
        return ans;
    }
};