
/*
Brute force 

tc: o(nlogn)
sc: o(1)
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        return nums[n-k];
    }
};


/*
Using Min-heap 

tc: o(nlogk)
sc: o(k)
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto num: nums){
            pq.push(num);
            if(pq.size() > k) pq.pop();
        }
        return pq.top();

    }
};

/*
Using Quick select

tc: o(n)
sc: o(1)

*/

class Solution {
public:
    int solve(vector<int>& nums, int L, int R){
        int P = nums[L];
        int i = L+1;
        int j = R;

        while(i <= j){
            if(nums[i] < P && nums[j] > P){
                swap(nums[i], nums[j]);
                i++;
                j--;
            }
            if(nums[i] >= P){
                i++;
            }
            if(nums[j] <= P){
                j--;
            }
        }
        swap(nums[L], nums[j]);
        return j;
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();

        int L = 0;
        int R = n-1;

        int pivot_idx = 0;

        while(true){
            pivot_idx = solve(nums, L, R);

            if(pivot_idx == k-1){
                break;
            }
            else if(pivot_idx > k-1){
                R = pivot_idx - 1;
            }
            else{
                L = pivot_idx + 1;
            }
            
        }
        return nums[pivot_idx];

    }
};