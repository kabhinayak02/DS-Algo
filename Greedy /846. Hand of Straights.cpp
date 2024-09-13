/* 
Note: This question is the same as 1296: 
https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/
*/

/*
tc: o(nlogn)
sc: o(n)
*/
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();

        if(n % groupSize) return false;

        map<int,int> mp;

        for(int &i: hand){
            mp[i]++;
        } 

        while(!mp.empty()){

            int curr = mp.begin()->first;

            for(int i=0; i<groupSize; i++){
                if(mp[curr + i] == 0) return false;

                mp[curr + i]--;
                if(mp[curr + i] < 1){
                    mp.erase(curr+i);
                }
            }

        }
        return true;
    }
};