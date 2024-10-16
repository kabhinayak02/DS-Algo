/*
using sliding window and set

create 2 set pair of ele and freq, right and left 
right -> will stores top x most elements
left -> will stores remaining elements 
now traverse the window with k size and calculate the when to add in set and when to remove 

tc: o(nlogx)
sc: o(n)
*/
class Solution {
public:
    typedef long long ll;
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        unordered_map<ll, ll> freq; // [ele, freq]
        set<pair<ll,ll>> left, right; 
        /*
        right ->  holds the top x most frequent elements.
        left ->  holds the less frequent elements or those that should not be included in right.
        */
        ll sum = 0; // will store the sum of the x most frequent elements in the current window.
        vector<ll> ans; 

        // lambda function to add elements in right set 
        auto add_right = [&](ll count, ll value) {
            right.insert({count, value});
            sum += count * value;
            if(right.size() > x){
                auto smallest = *right.begin();
                sum -= (smallest.first * smallest.second);
                left.insert(smallest);
                right.erase(right.begin());
            }
        };

        // lambda function to remove elements in right set 
        auto remove_right = [&](ll count, ll value) {
            auto smallest = *right.begin();
            auto curr = make_pair(count, value);
            if(curr >= smallest){
                sum -= (count * value);
                right.erase(curr);
                if(left.size() && right.size() < x){
                    auto largest = *left.rbegin();
                    sum += (largest.first * largest.second);
                    right.insert(largest);
                    left.erase(largest);
                }
            }
            else{
                left.erase(curr);
            }
        };

        int i = 0;
        for(int j=0; j<n; j++){
            if(freq[nums[j]] > 0){
                remove_right(freq[nums[j]], nums[j]);
            }
            freq[nums[j]]++;
            add_right(freq[nums[j]], nums[j]);

            if (j - i + 1 > k) { 
                remove_right(freq[nums[i]], nums[i]); 
                freq[nums[i]]--; 
                if (freq[nums[i]] > 0) { 
                    add_right(freq[nums[i]], nums[i]);
                }
                i++; 
            }

            if (j - i + 1 == k) {
                ans.push_back(sum); 
            }
        }
        return ans;
    }
};


/*

tc: o(nlogx)
sc: o(n)
*/
class Solution {
public:
    typedef long long ll;
    void add_right(ll count, ll value, set<pair<ll,ll>> &right, set<pair<ll,ll>> &left, ll &sum, int x){
        right.insert({count, value});
        sum += count * value;
        if(right.size() > x){
            auto smallest = *right.begin();
            sum -= smallest.first * smallest.second;
            left.insert(smallest);
            right.erase(right.begin());
        }
    }
    void remove_right(ll count, ll value, set<pair<ll,ll>> &right, set<pair<ll,ll>> &left, ll &sum, int x){
        auto smallest = *right.begin();
        auto curr = make_pair(count, value);
        if(curr >= smallest){
            sum -= count*value;
            right.erase(curr);
            if(left.size() && right.size() < x){
                auto largest = *left.rbegin();
                sum += largest.first * largest.second;
                right.insert(largest);
                left.erase(largest);
            }
        }
        else{
            left.erase(curr);
        }
    }
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        unordered_map<ll,ll> freq;
        set<pair<ll,ll>> left, right;
        ll sum = 0;
        vector<ll> ans;

        int i=0, j=0;
        while(j < n){
            if(freq[nums[j]] > 0){
                remove_right(freq[nums[j]], nums[j], right, left, sum, x);
            }
            freq[nums[j]]++;
            add_right(freq[nums[j]], nums[j], right, left, sum, x);

            if(j-i+1 > k){
                remove_right(freq[nums[i]], nums[i], right, left, sum, x);
                freq[nums[i]]--;
                if(freq[nums[i]] > 0){
                    add_right(freq[nums[i]], nums[i], right, left, sum, x);
                }
                i++;
            }

            if(j-i+1 == k){
                ans.push_back(sum);
            }
            j++;
        }
        return ans;
    }
};