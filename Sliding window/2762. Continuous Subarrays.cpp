/*
using sliding window using ordered map

tc: o(n.log(3))
sc: o(3), size of map will never be greater than 3 
*/
class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        long long ans = 0;
        map<int,int> mp;
        while(j < n){
            mp[nums[j]]++;
            while(abs(mp.rbegin()->first - mp.begin()->first) > 2){ // we dont need abs()
                mp[nums[i]]--;
                if(mp[nums[i]] == 0){
                    mp.erase(nums[i]);
                }
                i++;
            }
            ans += (j-i+1);
            j++;
            
        }
        return ans;
    }
};

/*
using min and max heap 

tc: o(nlogn)
sc: o(n)
*/
class Solution {
public:
    #define P pair<int,int>
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        priority_queue<P, vector<P>, greater<P>> minHeap;
        priority_queue<P> maxHeap;
        int i = 0, j = 0;
        long long count = 0;
        while(j < n){
            minHeap.push({nums[j], j});
            maxHeap.push({nums[j], j});

            while(abs(maxHeap.top().first - minHeap.top().first) > 2){ // we dont need abs()
                i++;

                while(!maxHeap.empty() && maxHeap.top().second < i){
                    maxHeap.pop();
                }
                while(!minHeap.empty() && minHeap.top().second < i){
                    minHeap.pop();
                }
            }

            count += (j-i+1);
            j++;
        }
        return count;
    }
};