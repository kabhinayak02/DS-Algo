/*
Brute force 

Sort the array and return the kth element

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

Just storing the k element in th min heap and returning the top elemen

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

Solve(n, L, R) -> This function partitions the array using the first element as the pivot. 
It swaps elements to ensure elements smaller than the pivot are on its left and larger elements are on 
its right. It returns the index of the pivot after partitioning.

tc: o(n)
sc: o(1)

*/

class Solution {
public:
    int partition(vector<int>& nums, int L, int R){
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
        swap(nums[L], nums[j]); // swap pivot with nums[j]. Now pivot is at its correct position.
        return j;
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();

        int L = 0;
        int R = n-1;

        int pivot_idx = 0; // you can choose any index at pivot_index

        while(true){
            pivot_idx = partition(nums, L, R);

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