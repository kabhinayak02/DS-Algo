/*

sort the array with arrival time but before that stores the arival time of the target friend as arival time is distinct.

now use priority queue (min heap) to stores the free chaies
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