/*
using vector

tc: o(n.n)
sc: o(n)
*/
class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();

        vector<int> chairs(n, -1);
        int targetFriendArrival = times[targetFriend][0];

        sort(times.begin(), times.end());

        for(vector<int>& time: times){
            int arrival = time[0];
            int depart = time[1];

            for(int i=0; i<n; i++){
                if(chairs[i] <= arrival){
                    chairs[i] = depart;

                    if(arrival == targetFriendArrival){
                        return i;
                    }
                    break;
                }
            }
        }
        return -1;
    }
};

/*
using 2 min heap

tc: o(nlogn)
sc: o(n)
*/
class Solution {
public:
    typedef pair<int,int> P;
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();

        priority_queue<P, vector<P>, greater<P>> occupied; // {depart, chairNo}
        priority_queue<int, vector<int>, greater<int>> freeChairs; // min free chaies 

        int targetFriendArrival = times[targetFriend][0];

        int chairNo = 0;
        sort(times.begin(), times.end());

        for(int i=0; i<n; i++){
            int arrival = times[i][0];
            int depart = times[i][1];

            while(!occupied.empty() && occupied.top().first <= arrival){
                freeChairs.push(occupied.top().second);
                occupied.pop();
            }

            if(freeChairs.empty()){
                occupied.push({depart, chairNo});
                if(arrival == targetFriendArrival){
                    return chairNo;
                }
                chairNo++;
            }
            else{
                occupied.push({depart, freeChairs.top()});
                if(arrival == targetFriendArrival){
                    return freeChairs.top();
                }
                freeChairs.pop();
            }
        }
        return -1;

    }
};